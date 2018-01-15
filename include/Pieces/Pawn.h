#ifndef PAWN_H
#define PAWN_H

#include <string>

#include "Piece.h"

#include "Game/Color.h"

class Pawn : public Piece
{
    public:
        explicit Pawn(Color color_in);

        std::string pgn_symbol() const override;
        Piece_Type type() const override;
};

#endif // PAWN_H
