#include "Genes/King_Protection_Gene.h"

#include "Game/Board.h"
#include "Pieces/Piece.h"
#include "Exceptions/Generic_Exception.h"

King_Protection_Gene::King_Protection_Gene() : Gene(0.0)
{
}

King_Protection_Gene::~King_Protection_Gene()
{
}

void King_Protection_Gene::reset_properties() const
{
    reset_base_properties();
}

void King_Protection_Gene::load_properties()
{
    load_base_properties();
}

double King_Protection_Gene::score_board(const Board& board, Color perspective) const
{
    // Count the number of unguarded squares that a piece could attack the king from
    //
    // Start at the king, then go by rows, columns, and diagonals. The last square to include
    // is either the edge of the board or a square containing a piece of either color. THe
    // latter condition holds because that piece blocks squares beyond it. Finally, check knight
    // moves.
    //
    // A square counts as guarded if it is able to be attacked by a friendly piece.
    //
    // All squares count equally.
    auto temp = board.make_hypothetical();
    temp.set_turn(perspective);

    auto king_location = temp.find_king(perspective);
    char king_file = king_location.first;
    int  king_rank = king_location.second;

    auto square_count = 0;

    // Rows, columns, diagonals
    for(auto file_step : {-1, 0, 1})
    {
        for(auto rank_step : {-1, 0, 1})
        {
            if(file_step == 0 && rank_step == 0)
            {
                continue;
            }

            for(int steps = 1; steps <= 7; ++steps)
            {
                char file = king_file + steps*file_step;
                int  rank = king_rank + steps*rank_step;
                if(! temp.inside_board(file) || ! temp.inside_board(rank))
                {
                    break;
                }

                if( ! temp.square_attacked_by(file, rank, perspective))
                {
                       ++square_count;
                }

                if(temp.piece_on_square(file, rank))
                {
                    break;
                }
            }
        }
    }

    // Knight moves
    for(auto file_step : {1, 2})
    {
        auto rank_step  = 3 - file_step; // (1,2) or (2,1)

        for(auto file_direction : {-1, 1})
        {
            for(auto rank_direction : {-1, 1})
            {
                char file = king_file + file_direction*file_step;
                int  rank = king_rank + rank_direction*rank_step;

                if( ! temp.inside_board(file) || ! temp.inside_board(rank))
                {
                    continue;
                }

                if( ! temp.square_attacked_by(file, rank, perspective))
                {
                    ++square_count;
                }
            }
        }
    }

    const int max_square_count =  8      // knight
                                + 7 + 7  // rooks/queen
                                + 7 + 6; // bishop/queen
    return double(max_square_count - square_count)/max_square_count; // return score [0, 1]
}

King_Protection_Gene* King_Protection_Gene::duplicate() const
{
    return new King_Protection_Gene(*this);
}

std::string King_Protection_Gene::name() const
{
    return "King Protection Gene";
}