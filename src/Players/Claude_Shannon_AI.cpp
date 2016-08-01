#include "Players/Claude_Shannon_AI.h"

#include <limits>

#include "Moves/Move.h"
#include "Game/Board.h"
#include "Game/Color.h"

#include "Exceptions/Checkmate_Exception.h"
#include "Exceptions/Game_Ending_Exception.h"

Claude_Shannon_AI::Claude_Shannon_AI() : recursion_depth(3)
{
}

Claude_Shannon_AI::~Claude_Shannon_AI()
{
}

const Complete_Move Claude_Shannon_AI::choose_move(const Board& board, const Clock&) const
{
    return choose_move(board, recursion_depth);
}

const Complete_Move Claude_Shannon_AI::choose_move(const Board& board, int look_ahead) const
{
    auto best_move = board.all_legal_moves().front();
    auto best_score = std::numeric_limits<int>::lowest();
    for(const auto& move : board.all_legal_moves())
    {
        try
        {
            auto next_board = board.make_hypothetical();
            next_board.submit_move(move);
            auto score = evalutate_position(next_board, board.whose_turn(), look_ahead);
            if(score > best_score)
            {
                best_score = score;
                best_move = move;
            }
        }
        catch(const Checkmate_Exception&)
        {
            return move;
        }
        catch(const Game_Ending_Exception&)
        {
            continue;
        }
    }

    return best_move;
}

int Claude_Shannon_AI::evalutate_position(const Board& /*board*/, Color /*perspective*/, int /*look_ahead*/) const
{
    return 0;
}