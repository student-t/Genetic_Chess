#ifndef PAWN_MOVE_H
#define PAWN_MOVE_H

#include "Move.h"
#include "Game/Color.h"

#include <string>

class Pawn_Move : public Move
{
    public:
        Pawn_Move(Color color_in, char file_start, int rank_start);

        void side_effects(Board& board) const override;
        bool can_capture() const override;
};

#endif // PAWN_MOVE_H
