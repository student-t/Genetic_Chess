#ifndef PAWN_H
#define PAWN_H

#include <string>

#include "Piece.h"

enum Color;

class Pawn : public Piece
{
    public:
        explicit Pawn(Color color_in);
        Pawn(const Pawn&) = delete;
        Pawn& operator=(const Pawn&) = delete;
        std::string pgn_symbol() const override;

        bool is_pawn() const override;
};

#endif // PAWN_H
