#ifndef PAWN_PROMOTION_H
#define PAWN_PROMOTION_H

#include "Pawn_Move.h"

#include <string>
#include <memory>

class Board;
class Piece;

class Pawn_Promotion : public Pawn_Move
{
    public:
        explicit Pawn_Promotion(const Piece* promotion);
        Pawn_Promotion(const Pawn_Promotion&) = delete;
        Pawn_Promotion& operator=(const Pawn_Promotion&) = delete;
        virtual ~Pawn_Promotion() override;

        void side_effects(Board& board, char file_start, int rank_start) const;
        virtual std::string name() const;
        virtual bool is_legal(const Board& board, char file_start, int rank_start) const;
        virtual std::string game_record_item(const Board& board, char file_start, int rank_start) const;

    protected:
        mutable std::shared_ptr<const Piece> promote_to;
};

#endif // PAWN_PROMOTION_H
