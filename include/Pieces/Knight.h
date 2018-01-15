#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

#include "Game/Color.h"

class Knight : public Piece
{
    public:
        explicit Knight(Color color);

        Piece_Type type() const override;
};

#endif // KNIGHT_H
