#ifndef LOOK_AHEAD_GENE_H
#define LOOK_AHEAD_GENE_H

#include "Genes/Gene.h"

class Board;
class Clock;

class Look_Ahead_Gene : public Gene
{
    public:
        Look_Ahead_Gene();
        virtual ~Look_Ahead_Gene() override;

        Look_Ahead_Gene* duplicate() const override;
        void mutate() override;

        double score_board(const Board& board, Color perspective) const override;

        std::string name() const override;

        size_t positions_to_examine(const Board& board, const Clock& clock) const;

    private:
        void reset_properties() const override;
        void load_properties() override;

        double mean_game_length; // in moves by one player
        double positions_per_second; // number of positions examined per second
};

#endif // LOOK_AHEAD_GENE_H
