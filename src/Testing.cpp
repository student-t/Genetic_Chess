#include "Testing.h"

#ifdef DEBUG
#include <memory>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cmath>
#include <thread>
#include <iomanip>

#include "Game/Board.h"
#include "Moves/Move.h"
#include "Players/Genetic_AI.h"
#include "Game/Clock.h"

#include "Utility.h"

#include "Exceptions/Illegal_Move_Exception.h"

// Declaration to silence warnings
bool files_are_identical(const std::string& file_name1, const std::string& file_name2);

bool files_are_identical(const std::string& file_name1, const std::string& file_name2)
{
    std::ifstream file1(file_name1);
    std::ifstream file2(file_name2);
    int line_count = 0;

    while(true)
    {
        std::string line1, line2;
        std::getline(file1, line1);
        std::getline(file2, line2);
        ++line_count;

        if(line1 != line2)
        {
            std::cerr << "Mismatch at line " << line_count << ":\n";
            std::cerr << line1 << " != " << line2 << "\n";
            return false;
        }

        if( ! file1 && ! file2)
        {
            break;
        }
    }

    return true;
}

void run_tests()
{
    bool tests_passed = true;

    // Castling with attacking piece
    for(auto castle_side : std::string("KQ"))
    {
        for(int rook_left_space = 0; rook_left_space < 8; ++rook_left_space)
        {
            auto rook_left  = (rook_left_space > 0 ? std::to_string(rook_left_space) : std::string());
            auto rook_right = (rook_left_space < 7 ? std::to_string(7 - rook_left_space) : std::string());
            Board board("1k6/" + rook_left + "r" + rook_right + "/8/8/8/8/8/R3K2R w KQ - 0 1");

            char final_file = (castle_side == 'K' ? 'g' : 'c');

            try
            {
                board.get_complete_move('e', 1, final_file, 1);
            }
            catch(const Illegal_Move_Exception&)
            {
                if(castle_side == 'K')
                {
                    if(rook_left_space >= 4 && rook_left_space <= 6)
                    {
                        continue;
                    }
                }
                else
                {
                    if(rook_left_space >= 2 && rook_left_space <= 4)
                    {
                        continue;
                    }
                }

                board.ascii_draw(WHITE);
                std::cout << std::string(1, castle_side) + "-castle should be legal here." << std::endl;
                tests_passed = false;
            }

            if(castle_side == 'K')
            {
                if(rook_left_space < 4 || rook_left_space > 6)
                {
                    continue;
                }
            }
            else
            {
                if(rook_left_space < 2 || rook_left_space > 4)
                {
                    continue;
                }
            }

            board.ascii_draw(WHITE);
            std::cout << std::string(1, castle_side) + "-castle should be illegal here." << std::endl;
            tests_passed = false;
        }
    }


    // Test Genetic_AI file loading
    auto pool_file_name = "test_gene_pool.txt";
    auto write_file_name = "test_genome_write.txt";
    auto rewrite_file_name = "test_genome_rewrite.txt";
    remove(pool_file_name);
    remove(write_file_name);
    remove(rewrite_file_name);

    std::vector<Genetic_AI> test_pool(100);
    for(auto& ai : test_pool)
    {
        for(int i = 0; i < 1000; ++i)
        {
            ai.mutate();
        }
        ai.print_genome(pool_file_name);
    }

    auto index = Random::random_integer(0, test_pool.size() - 1);
    test_pool[index].print_genome(write_file_name);
    auto read_ai = Genetic_AI(pool_file_name, index);
    read_ai.print_genome(rewrite_file_name);

    if( ! files_are_identical(write_file_name, rewrite_file_name))
    {
        std::cerr << "Genome loaded from gene pool file not preserved." << std::endl;
        tests_passed = false;
    }
    else
    {
        remove(pool_file_name);
        remove(write_file_name);
        remove(rewrite_file_name);
    }


    // String utilities
    std::string original = "   a    #     b";
    std::string expected = "a";
    std::string result = String::strip_comments(original, '#');
    if(expected != result)
    {
        std::cerr << "\"" << original << "\" --> \"" << result << "\"" << std::endl;
        tests_passed = false;
    }

    original = "   a    {    b    }    c   {   d  }   ";
    expected = "a c";
    result = String::strip_block_comment(original, '{', '}');
    if(expected != result)
    {
        std::cerr << "\"" << original << "\" --> \"" << result << "\"" << std::endl;
        tests_passed = false;
    }


    // Poisson distribution check
    const double mean_moves = 35.0;
    double mean_moves_calc = 0.0;
    double mean_moves_calc_prev = -1.0;
    for(int i = 1; mean_moves_calc != mean_moves_calc_prev; ++i)
    {
        mean_moves_calc_prev = mean_moves_calc;
        mean_moves_calc += Math::poisson_probability(mean_moves, i)*i;
    }

    if(std::abs(mean_moves - mean_moves_calc) > 1e-6)
    {
        std::cerr << "Poisson distribution test failed. Expected: " << mean_moves << " Result: " << mean_moves_calc << std::endl;
        tests_passed = false;
    }

    // Clock time reset test
    auto time = 30;
    auto moves_to_reset = 40;
    auto clock = Clock(time, moves_to_reset);
    clock.start();
    for(int i = 0; i < 2*moves_to_reset; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        clock.punch();
    }
    clock.stop();
    if(clock.time_left(BLACK) != time)
    {
        std::cerr << "Clock incorrect: time left for black is " << clock.time_left(BLACK) << " sec. Should be " << time << "sec." << std::endl;
        tests_passed = false;
    }

    // Clock time increment test
    auto increment = 5;
    auto clock2 = Clock(time, 0, increment);
    clock2.start();
    double expected_time = time;
    for(int i = 0; i < 2*moves_to_reset; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        clock2.punch();
        if(i % 2 == 1) // only on black moves
        {
            expected_time += increment - 0.005;
        }
    }
    clock2.stop();
    if(std::abs(clock2.time_left(BLACK) - expected_time) > 0.01)
    {
        std::cerr << "Clock incorrect: time left for black is " << clock2.time_left(BLACK) << " sec. Should be " << expected_time << "sec." << std::endl;
        tests_passed = false;
    }

    Game_Tree_Node_Result r1 = {Complete_Move(),
                                10,
                                WHITE,
                                2,
                                ""};
    Game_Tree_Node_Result r2 = {Complete_Move(),
                                10,
                                BLACK,
                                2,
                                ""};

    if(better_than(r2, r1, WHITE))
    {
        std::cerr << "1. Error in comparing Game Tree Node Results." << std::endl;
        tests_passed = false;
    }

    if(better_than(r1, r2, BLACK))
    {
        std::cerr << "2. Error in comparing Game Tree Node Results." << std::endl;
        tests_passed = false;
    }

    Game_Tree_Node_Result alpha_start = {Complete_Move(),
                                         -Math::infinity,
                                         WHITE,
                                         0,
                                         ""};

    Game_Tree_Node_Result beta_start = {Complete_Move(),
                                        Math::infinity,
                                        WHITE,
                                        0,
                                        ""};
    if(better_than(alpha_start, beta_start, WHITE))
    {
        std::cerr << "3. Error in comparing Game Tree Node Results." << std::endl;
        tests_passed = false;
    }

    if( ! better_than(alpha_start, beta_start, BLACK))
    {
        std::cerr << "4. Error in comparing Game Tree Node Results." << std::endl;
        tests_passed = false;
    }


    Game_Tree_Node_Result white_win4 = {Complete_Move(),
                                        Math::win_score,
                                        WHITE,
                                        4,
                                        ""};
    Game_Tree_Node_Result white_win6 = {Complete_Move(),
                                        Math::win_score,
                                        WHITE,
                                        6,
                                        ""};
    if(better_than(white_win6, white_win4, WHITE))
    {
        std::cerr << "Later win preferred over earlier win." << std::endl;
        tests_passed = false;
    }

    if(better_than(white_win4, white_win6, BLACK))
    {
        std::cerr << "Earlier loss preferred over later win." << std::endl;
        tests_passed = false;
    }

    Game_Tree_Node_Result black_loss6 = {Complete_Move(),
                                         -Math::win_score,
                                         BLACK,
                                         6,
                                         ""};
    if( ! (white_win6 == black_loss6))
    {
        std::cerr << "White win in 6 not equal to black loss in 6." << std::endl;
        tests_passed = false;
    }


    // Move ambiguity check
    Board board;
    bool ambiguous_move_caught = false;
    try
    {
        for(auto move : {"Nc3", "a1",
                         "Nf3", "b1",
                         "Ne4", "c1",
                         "Ng5"})
        {
            board.submit_move(board.get_complete_move(move));
        }
    }
    catch(const Illegal_Move_Exception&)
    {
        ambiguous_move_caught = true;
    }

    if( ! ambiguous_move_caught)
    {
        std::cerr << "Last move should have been an error:" << std::endl;
        board.print_game_record();
        tests_passed = false;
    }

    Board().ascii_draw(WHITE);

    for(int i = 0; i < 10; ++i)
    {
        std::cout << std::setw(7) << Random::random_integer(-1000, 1000) << '\t'
                  << std::setw(10) << Random::random_real(0, 2) << '\t'
                  << std::setw(10) << Random::random_normal(3) << '\n';
    }

    if(tests_passed)
    {
        std::cout << "All tests passed." << std::endl;
    }
    else
    {
        std::cout << "Tests failed." << std::endl;
    }
}
#else
void run_tests() {}
#endif
