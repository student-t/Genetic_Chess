#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Game/Color.h"


class Knight : public Piece
{
    public:
        explicit Knight(Color color);
        Knight(const Knight&) = delete;
        Knight& operator=(const Knight&) = delete;
        virtual ~Knight() override;
};

#endif // KNIGHT_H
