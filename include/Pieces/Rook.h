#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

#include "Game/Color.h"

class Rook : public Piece
{
    public:
        explicit Rook(Color color_in);

        Piece_Type type() const override;
};

#endif // ROOK_H
