#ifndef GENE_H
#define GENE_H

#include <map>
#include <string>
#include <memory>
#include <iosfwd>

#include "Game/Color.h"

class Board;
class Piece_Strength_Gene;

class Gene
{
    public:
        explicit Gene(double initial_scalar_value);
        virtual ~Gene();

        void read_from(std::istream& is);

        virtual void mutate();
        double evaluate(const Board& board, Color perspective) const;
        virtual Gene* duplicate() const = 0;

        virtual std::string name() const = 0;
        void print(std::ostream& os) const;

        virtual void reset_piece_strength_gene(const std::shared_ptr<const Piece_Strength_Gene>& psg);

    protected:
        mutable std::map<std::string, double> properties; // used to simplify reading/writing from/to files
        void reset_base_properties() const;
        void load_base_properties();

    private:
        virtual double score_board(const Board& board, Color perspective) const = 0;
        void throw_on_invalid_line(const std::string& line, const std::string& reason) const;
        virtual void reset_properties() const = 0;
        virtual void load_properties() = 0;

        double scalar;
};

#endif // GENE_H
