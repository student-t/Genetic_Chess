#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

#include "Game/Color.h"

class Bishop : public Piece
{
    public:
        explicit Bishop(Color color);

        Piece_Type type() const override;
};

#endif // BISHOP_H
