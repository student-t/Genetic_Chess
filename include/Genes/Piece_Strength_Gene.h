#ifndef PIECE_STRENGTH_GENE_H
#define PIECE_STRENGTH_GENE_H

#include "Gene.h"

#include <string>
#include <array>
#include <memory>

#include "Pieces/Piece_Types.h"

class Piece;
class Board;

// Database of the value of piece types
class Piece_Strength_Gene : public Gene
{
    public:
        Piece_Strength_Gene();

        std::unique_ptr<Gene> duplicate() const override;

        std::string name() const override;

        double piece_value(const Piece* piece) const;

    protected:
        void reset_properties() const override;
        void load_properties() override;

    private:
        std::array<double, 6> piece_strength;
        double normalizing_factor;

        double score_board(const Board& board) const override;
        void renormalize();
        double piece_value(Piece_Type type) const;
        double& piece_value(Piece_Type type);
        void gene_specific_mutation() override;
};

#endif // PIECE_STRENGTH_GENE_H
