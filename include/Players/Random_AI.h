#ifndef RANDOM_AI_H
#define RANDOM_AI_H

#include <string>

#include "Player.h"

class Board;
class Clock;
class Move;

class Random_AI : public Player
{
    public:
        const Move& choose_move(const Board& board, const Clock& clock) const override;
        std::string name() const override;
};

#endif // RANDOM_AI_H
