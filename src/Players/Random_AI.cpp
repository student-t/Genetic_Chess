#include "Players/Random_AI.h"

#include <vector>

#include "Game/Board.h"
#include "Moves/Complete_Move.h"

class Clock;

#include "Exceptions/Illegal_Move_Exception.h"

#include "Utility.h"

const Complete_Move Random_AI::choose_move(const Board& board, const Clock& /*clock*/) const
{
    const auto& moves = board.legal_moves();
    return moves[Random::random_integer(0, moves.size() - 1)];
}

std::string Random_AI::name() const
{
    return "Random AI";
}
