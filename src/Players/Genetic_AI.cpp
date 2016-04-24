#include "Players/Genetic_AI.h"

#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Utility.h"
#include "Moves/Move.h"
#include "Game/Board.h"
#include "Game/Clock.h"
#include "Pieces/Piece.h"

#include "Exceptions/Checkmate_Exception.h"
#include "Exceptions/Game_Ending_Exception.h"
#include "Exceptions/Generic_Exception.h"
#include "Exceptions/End_Of_File_Exception.h"

int Genetic_AI::next_id = 0;

Genetic_AI::Genetic_AI() :
    genome(),
    id(next_id++),
    parents()
{
}

Genetic_AI::Genetic_AI(const Genetic_AI& other, bool is_clone) :
    genome(other.genome),
    id(is_clone ? next_id++ : other.id)
{
    if(is_clone)
    {
        parents = {other.id};
    }
}

Genetic_AI::Genetic_AI(const Genetic_AI& A, const Genetic_AI& B) :
    genome(A.genome, B.genome),
    id(next_id++),
    parents({A.id, B.id})
{
}

Genetic_AI::Genetic_AI(const std::string& file_name)
{
    std::ifstream ifs(file_name);
    if( ! ifs)
    {
        throw Generic_Exception("Could not read: " + file_name);
    }

    read_from(ifs);
}

Genetic_AI::Genetic_AI(std::istream& is)
{
    read_from(is);
}

void Genetic_AI::read_from(std::istream& is)
{
    std::string line;
    id = -1;
    while(std::getline(is, line))
    {
        if(line.empty())
        {
            continue;
        }

        if(String::starts_with(line, "ID:"))
        {
            id = atoi(String::split(line)[1].c_str());
            break;
        }
        else
        {
            throw Generic_Exception("Invalid Genetic_AI line: " + line);
        }
    }

    if( ! is)
    {
        if(id > -1)
        {
            throw Generic_Exception("Incomplete Genetic_AI spec in file for ID " + String::to_string(id));
        }
        else
        {
            throw End_Of_File_Exception();
        }
    }

    if(id >= next_id)
    {
        next_id = id + 1;
    }

    genome.read_from(is);
}

const Complete_Move Genetic_AI::choose_move(const Board& board, const Clock& clock) const
{
    return choose_move(board, clock, -1);
}

const Complete_Move Genetic_AI::choose_move(const Board& board, const Clock& clock, int look_ahead) const
{
    auto legal_moves = board.all_legal_moves();
    if(legal_moves.size() == 1)
    {
        return legal_moves.front();
    }
    double best_score = std::numeric_limits<double>::lowest();
    auto best_move = legal_moves.front();
    if(look_ahead == -1)
    {
        look_ahead = genome.look_ahead(clock.time_left(board.whose_turn()),
                                       board.number_all_moves());
    }

    for(const auto& move : legal_moves)
    {
        if(clock.time_left(clock.running_for()) < 0)
        {
            break;
        }

        double score;
        try
        {
            auto hypothetical = board.make_hypothetical();
            hypothetical.submit_move(move);
            score = evaluate_board(hypothetical,
                                   clock,
                                   board.whose_turn(),
                                   look_ahead,
                                   genome.evaluate(board, board.whose_turn()));
        }
        catch(const Checkmate_Exception&)
        {
            return move;
        }
        catch(const Game_Ending_Exception&) // stalemate
        {
            score = std::numeric_limits<double>::lowest();
        }

        if(score > best_score)
        {
            best_score = score;
            best_move = move;
        }
    }

    return best_move;
}

double Genetic_AI::evaluate_board(const Board& board,
                                  const Clock& clock,
                                  Color perspective,
                                  size_t look_ahead,
                                  double original_board_score) const
{
    auto board_score = genome.evaluate(board, perspective);
    if(look_ahead > 0
       && clock.time_left(clock.running_for()) > genome.time_required()
       && board_score - original_board_score > genome.minimum_score_change())
    {
        try
        {
            auto next_board = board.make_hypothetical();
            Complete_Move next_move = choose_move(next_board, clock, look_ahead - 1);
            next_board.submit_move(next_move);
            return evaluate_board(next_board, clock, perspective, look_ahead - 1, original_board_score);
        }
        catch(const Game_Ending_Exception& gee)
        {
            return gee.winner() == perspective ?
                                        std::numeric_limits<double>::max() :
                                        std::numeric_limits<double>::lowest();
        }
    }

    return board_score;
}

void Genetic_AI::mutate()
{
    genome.mutate();
}

void Genetic_AI::print_genome(const std::string& file_name) const
{
    if(file_name.empty())
    {
        print_genome(std::cout);
    }
    else
    {
        auto dest = std::ofstream(file_name, std::ofstream::app);
        print_genome(dest);
    }
}

void Genetic_AI::print_genome(std::ostream& os) const
{
    os << "ID: " << get_id() << std::endl;
    genome.print(os);
    os << "END" << std::endl << std::endl;
}

std::string Genetic_AI::name() const
{
    std::ostringstream oss;
    oss << "Genetic AI " << get_id();
    return oss.str();
}

int Genetic_AI::get_id() const
{
    return id;
}

std::vector<int> Genetic_AI::get_parents() const
{
    return parents;
}

bool Genetic_AI::operator==(const Genetic_AI& other) const
{
    return this == &other;
}

bool Genetic_AI::operator!=(const Genetic_AI& other) const
{
    return ! (*this == other);
}
