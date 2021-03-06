#include <iostream>
#include <memory>
#include <fstream>
#include <cctype>

#include "Game/Game.h"
#include "Game/Board.h"
#include "Game/Game_Result.h"

#include "Players/Genetic_AI.h"
#include "Players/Human_Player.h"
#include "Players/Random_AI.h"
#include "Players/Outside_Player.h"

#include "Genes/Gene_Pool.h"
#include "Stalemate_Search.h"

#include "Exceptions/Illegal_Move_Exception.h"

#include "Utility.h"
#include "Testing.h"

void print_help();
void replay_game(const std::string& file_name, int game_number);
bool confirm_game_record(const std::string& file_name);
int find_last_id(const std::string& filename);

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);

    try
    {
        run_tests();

        if(argc > 1)
        {
            if(std::string(argv[1]) == "-genepool")
            {
                std::string gene_pool_config_file_name;
                if(argc > 2)
                {
                    gene_pool_config_file_name = argv[2];
                }

                gene_pool(gene_pool_config_file_name);
            }
            else if(std::string(argv[1]) == "-replay")
            {
                if(argc > 2)
                {
                    std::string file_name = argv[2];
                    int game_number = -1;
                    if(argc > 3)
                    {
                        game_number = std::stoi(argv[3]);
                    }
                    replay_game(file_name, game_number);
                }
                else
                {
                    std::cout << "Provide a file containing a game to replay." << std::endl;
                    return 1;
                }
            }
            else if(std::string(argv[1]) == "-stalemate")
            {
                stalemate_search_start();
            }
            else if(std::string(argv[1]) == "-confirm")
            {
                if(argc >= 3)
                {
                    if( ! confirm_game_record(argv[2]))
                    {
                        std::cerr << "Game contains illegal or mismarked moves." << std::endl;
                        return 2;
                    }
                }
                else
                {
                    std::cerr << "Provide a file containing a game to confirm has all legal moves." << std::endl;
                    return 1;
                }
            }
            else
            {
                // Use pointers since each player could be Human, Genetic, Random, etc.
                std::unique_ptr<Player> white;
                std::unique_ptr<Player> black;
                std::unique_ptr<Player> latest;

                double game_time = 0;
                size_t moves_per_reset = 0;
                double increment_time = 0;

                for(int i = 1; i < argc; ++i)
                {
                    std::string opt = argv[i];
                    if(opt == "-human")
                    {
                        latest = std::make_unique<Human_Player>();
                    }
                    else if(opt == "-random")
                    {
                        latest = std::make_unique<Random_AI>();
                    }
                    else if(opt == "-genetic")
                    {
                        std::string filename;
                        int id = -1;
                        if(i + 1 < argc)
                        {
                            filename = argv[i+1];
                            if(filename.front() == '-')
                            {
                                filename.clear();
                            }
                        }

                        if(i + 2 < argc)
                        {
                            try
                            {
                                id = std::stoi(argv[i+2]);
                            }
                            catch(const std::exception&)
                            {
                            }
                        }

                        if(filename.empty())
                        {
                            latest = std::make_unique<Genetic_AI>();
                            for(int j = 0; j < 100; ++j)
                            {
                                static_cast<Genetic_AI*>(latest.get())->mutate();
                            }
                            static_cast<const Genetic_AI*>(latest.get())->print_genome("single_game_player.txt");
                        }
                        else
                        {
                            if(id < 0)
                            {
                                latest = std::make_unique<Genetic_AI>(filename, find_last_id(filename));
                                i += 1;
                            }
                            else
                            {
                                latest = std::make_unique<Genetic_AI>(filename, id);
                                i += 2;
                            }
                        }
                    }
                    else if(opt == "-time")
                    {
                        game_time = std::stod(argv[++i]);
                    }
                    else if(opt == "-reset_moves")
                    {
                        moves_per_reset = std::stoul(argv[++i]);
                    }
                    else if(opt == "-increment_time")
                    {
                        increment_time = std::stod(argv[++i]);
                    }
                    else
                    {
                        throw std::runtime_error("Invalid option: " + opt);
                    }

                    if(latest)
                    {
                        if( ! white)
                        {
                            white = std::move(latest);
                        }
                        else if( ! black)
                        {
                            black = std::move(latest);
                        }
                        else
                        {
                            throw std::runtime_error("More than two players specified.");
                        }
                    }
                }

                std::string game_file_name = "game.pgn";

                if(black)
                {
                    play_game(*white, *black, game_time, moves_per_reset, increment_time, game_file_name);
                }
                else
                {
                    auto outside = connect_to_outside(*white);
                    game_time = outside->get_game_time();
                    moves_per_reset = outside->get_reset_moves();
                    increment_time = outside->get_increment();

                    if(outside->get_ai_color() == WHITE)
                    {
                        play_game(*white, *outside, game_time, moves_per_reset, increment_time, game_file_name);
                    }
                    else
                    {
                        play_game(*outside, *white, game_time, moves_per_reset, increment_time, game_file_name);
                    }
                }
            }
        }
        else
        {
            print_help();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "\n\nERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void print_help()
{
    std::cout << "\n\nGenetic Chess" << std::endl
              << "=============" << std::endl << std::endl
              << "Options:" << std::endl
              << "\t-genepool [file name]" << std::endl
              << "\t\tStart a run of a gene pool with parameters set in the given\n\t\tfile name." << std::endl << std::endl
              << "\t-replay [filename]" << std::endl
              << "\t\tStep through a PGN game file, drawing the board after each\n\t\tmove with an option to begin playing at any time." << std::endl << std::endl
              << "\t-confirm [filename]" << std::endl
              << "\t\tCheck a file containing PGN game records for any illegal moves\n\t\tor mismarked checks or checkmates." << std::endl << std::endl
              << "\t-stalemate" << std::endl
              << "\t\tBegin a search for the shortest possible stalemate--i.e., where\n\t\tthe player to move has no legal moves. Estimated time to\n\t\tcompletion: months." << std::endl << std::endl
              << "The following options start a game with various players. If two players are\nspecified, the first plays white and the second black. If only one player is\nspecified, the program will wait for a CECP command from outside to start\nplaying." << std::endl << std::endl
              << "\t-human" << std::endl
              << "\t\tSpecify a human player for a game." << std::endl << std::endl
              << "\t-genetic [filename [number]]" << std::endl
              << "\t\tSpecify a genetic AI player for a game. Optional file name and\n\t\tID number to load an AI from a file." << std::endl << std::endl
              << "\t-random" << std::endl
              << "\t\tSpecify a player that makes random moves for a game." << std::endl << std::endl
              << "Other game options:" << std::endl << std::endl
              << "\t-time [number]" << std::endl
              << "\t\tSpecify the time (in seconds) each player has to play the game\n\t\tor to make a set number of moves (see -reset_moves option)." << std::endl << std::endl
              << "\t-reset_moves [number]" << std::endl
              << "\t\tSpecify the number of moves a player must make within the time\n\t\tlimit. The clock adds the initial time every time this\n\t\tnumber of moves is made." << std::endl << std::endl
              << "\t-increment_time [number]" << std::endl
              << "\t\tSpecify seconds to add to time after each move." << std::endl << std::endl;
}

int find_last_id(const std::string& players_file_name)
{
    auto pools = load_gene_pool_file(players_file_name);
    int smallest_id = -1;
    if( ! pools.empty())
    {
        smallest_id = pools.front().front().get_id();
        for(const auto& pool : pools)
        {
            for(const auto& player : pool)
            {
                if(player.get_id() < smallest_id)
                {
                    smallest_id = player.get_id();
                }
            }
        }
    }

    if(smallest_id != -1)
    {
        return smallest_id;
    }

    std::ifstream player_input(players_file_name);
    std::string line;
    int last_player = -1;
    while(std::getline(player_input, line))
    {
        if(String::starts_with(line, "ID:"))
        {
            last_player = std::stoi(String::split(line).back());
        }
    }

    // Filter out players with zero wins
    auto games_file = players_file_name + "_games.txt";
    std::ifstream games_input(games_file);
    std::map<int, int> win_count;
    int best_id = -1;
    while(std::getline(games_input, line))
    {
        int white_id = -1;
        int black_id = -1;
        if(String::starts_with(line, "[White"))
        {
            white_id = std::stoi(String::split(String::split(line, "\"")[1])[2]);
        }
        else if(String::starts_with(line, "[Black"))
        {
            black_id = std::stoi(String::split(String::split(line, "\"")[1])[2]);
        }
        else if(String::starts_with(line, "[Result"))
        {
            auto result_string = String::split(line, "\"")[1];
            auto winning_id = -1;
            if(result_string == "1-0")
            {
                winning_id = white_id;
            }
            else if(result_string == "0-1")
            {
                winning_id = black_id;
            }

            int wins_so_far = ++win_count[winning_id];
            if(wins_so_far >= 3 && winning_id > best_id)
            {
                best_id = winning_id;
            }
        }
    }

    if(best_id == -1)
    {
        return last_player;
    }
    else
    {
        return best_id;
    }
}

void replay_game(const std::string& file_name, int game_number)
{
    std::ifstream ifs(file_name);
    std::vector<std::string> game_headers;
    std::string line;
    if(game_number >= 0)
    {
        // fast forward to indicated game
        while(std::getline(ifs, line))
        {
            line = String::trim_outer_whitespace(line);
            if(String::starts_with(line, '['))
            {
                game_headers.push_back(line);
            }
            else
            {
                game_headers.clear();
            }

            if(String::starts_with(line, "[Round"))
            {
                auto number = std::stoi(String::split(line, "\"")[1]);
                if(number == game_number)
                {
                    break;
                }
            }
        }

        if( ! ifs)
        {
            std::cout << "No game with ID number " << game_number << " found." << std::endl;
        }

        for(const auto& header : game_headers)
        {
            std::cout << header << std::endl;
        }
    }

    Board board;
    Game_Result result;
    bool game_started = false;
    while( ! result.game_has_ended() && std::getline(ifs, line))
    {
        line = String::strip_block_comment(line, '{', '}');
        line = String::strip_comments(line, ';');
        if(line.empty())
        {
            if(game_started)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        if(line[0] == '[') // header lines
        {
            std::cout << line << std::endl;
            continue;
        }

        for(const auto& s : String::split(line))
        {
            try
            {
                result = board.submit_move(board.get_move(s));

                board.ascii_draw(WHITE);
                game_started = true;
                std::cout << "Last move: ";
                std::cout << (board.get_game_record().size() + 1)/2 << ". ";
                std::cout << (board.whose_turn() == WHITE ? "... " : "");
                std::cout << board.get_game_record().back()->coordinate_move() << std::endl;
                if(result.game_has_ended())
                {
                    std::cout << result.get_ending_reason() << std::endl;
                    break;
                }

                std::cout << "Enter \"y\" to play game from here: " << std::endl;
                char response = std::cin.get();
                if(std::tolower(response) == 'y')
                {
                    play_game_with_board(Human_Player(),
                                         Human_Player(),
                                         0,
                                         0,
                                         0,
                                         file_name + "_continued.pgn",
                                         board);
                     break;
                }
            }
            catch(const Illegal_Move_Exception&)
            {
                std::cout << "Ignoring: " << s << std::endl;
                continue;
            }
        }
    }
}

bool confirm_game_record(const std::string& file_name)
{
    auto input = std::ifstream(file_name);
    std::string line;

    auto expected_winner = NONE;
    auto expect_checkmate = true;
    auto in_game = false;
    Board board;

    while(std::getline(input, line))
    {
        line = String::strip_block_comment(line, '{', '}');
        line = String::strip_comments(line, ';');
        line = String::remove_extra_whitespace(line);
        if(line.empty())
        {
            continue;
        }

        if(in_game && String::starts_with(line, '['))
        {
            expected_winner = NONE;
            expect_checkmate = true;
            in_game = false;
            board = Board();
        }

        if(String::starts_with(line, "[Result"))
        {
            if(String::contains(line, "1-0"))
            {
                expected_winner = WHITE;
            }
            else if(String::contains(line, "0-1"))
            {
                expected_winner = BLACK;
            }
            else if(String::contains(line, "1/2-1/2"))
            {
                expected_winner = NONE;
            }
            else
            {
                std::cerr << "Malformed Result: " << line << std::endl;
                return false;
            }
        }
        else if(String::starts_with(line, "[Termination"))
        {
            expect_checkmate = false;
        }
        else if(String::starts_with(line, "[FEN"))
        {
            board = Board(String::split(line, "\"").at(1));
        }
        else if(String::starts_with(line, '['))
        {
            continue;
        }
        else
        {
            // In game
            in_game = true;
            std::string move_number;
            for(const auto& move : String::split(line))
            {
                if(move.back() == '.')
                {
                    move_number = move + ' ';
                    continue;
                }

                if(board.whose_turn() == BLACK)
                {
                    move_number += "... ";
                }

                if((move == "1/2-1/2" && expected_winner != NONE) ||
                    (move == "1-0" && expected_winner != WHITE) ||
                   (move == "0-1" && expected_winner != BLACK))
                {
                    std::cerr << "Final result mark (" << move << ") does not match game result." << std::endl;
                    return false;
                }

                if(move == "1/2-1/2" || move == "1-0" || move == "0-1")
                {
                    continue;
                }

                try
                {
                    auto move_checks = move.back() == '+';
                    auto move_checkmates = move.back() == '#';
                    auto& move_to_submit = board.get_move(move);
                    if(String::contains(move, 'x')) // check that move captures
                    {
                        const Board& temp = board; // to prevent use of non-const private overload
                        if( ! temp.piece_on_square(move_to_submit.end_file(), move_to_submit.end_rank()) && ! move_to_submit.is_en_passant())
                        {
                            std::cerr << "Move: " << move_number << move << " indicates capture but does not capture." << std::endl;
                            return false;
                        }
                    }

                    auto result = board.submit_move(move_to_submit);
                    if(move_checks)
                    {
                        if( ! board.king_is_in_check())
                        {
                            std::cerr << "Move (" << move_number << move << ") indicates check but does not check." << std::endl;
                            return false;
                        }
                    }

                    if(move_checkmates)
                    {
                        if(result.get_winner() != opposite(board.whose_turn()))
                        {
                            std::cerr << "Move (" << move_number << move << ") indicates checkmate, but move does not checkmate." << std::endl;
                            return false;
                        }

                        if( ! expect_checkmate)
                        {
                            std::cerr << "Game ends in checkmate, but this is not indicated in headers." << std::endl;
                            return false;
                        }
                    }
                }
                catch(const Illegal_Move_Exception&)
                {
                    std::cerr << "Move (" << move_number << move << ") is illegal." << std::endl;
                    return false;
                }
            }
        }
    }

    return true;
}
