#include "Genes/Piece_Strength_Gene.h"

#include <cmath>
#include <limits>
#include <cctype>
#include <array>
#include <cassert>
#include <memory>
#include <vector>

#include "Genes/Gene.h"
#include "Utility.h"
#include "Pieces/Piece.h"
#include "Pieces/Piece_Type.h"

const std::vector<Piece_Type> Piece_Strength_Gene::piece_types = {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};

Piece_Strength_Gene::Piece_Strength_Gene()
{
    for(auto type : piece_types)
    {
        piece_strength[type] = 0.0;
    }
    renormalize();
}

void Piece_Strength_Gene::reset_properties() const
{
    for(const auto& piece : piece_types)
    {
        properties[std::string(1, Board::get_piece(piece, WHITE)->fen_symbol())] = piece_value_raw(piece);
    }
}

void Piece_Strength_Gene::load_properties()
{
    for(const auto& piece_score : properties)
    {
        switch(piece_score.first[0])
        {
            case 'P':
                piece_value_ref(PAWN) = piece_score.second;
                break;
            case 'R':
                piece_value_ref(ROOK) = piece_score.second;
                break;
            case 'N':
                piece_value_ref(KNIGHT) = piece_score.second;
                break;
            case 'B':
                piece_value_ref(BISHOP) = piece_score.second;
                break;
            case 'Q':
                piece_value_ref(QUEEN) = piece_score.second;
                break;
            case 'K':
                piece_value_ref(KING) = piece_score.second;
                break;
            default:
                throw std::runtime_error("Unrecognized piece type: " + piece_score.first);
        }
    }
    renormalize();
}

void Piece_Strength_Gene::gene_specific_mutation()
{
    for(auto piece : piece_types)
    {
        const double mean_number_of_mutations = 2.0;
        if(Random::success_probability(mean_number_of_mutations/piece_types.size()))
        {
            piece_value_ref(piece) += Random::random_normal(1.0);
        }
    }

    // The queen always has a value far from zero. Setting it to be
    // non-negative should speed up the evolution of the values of the
    // other pieces and genes that reference this gene. This does not
    // narrow the range of genomes since multiplying the other piece values
    // and gene priorities by -1 results in identical behavior.
    piece_value_ref(QUEEN) = std::max(0.0, piece_value(QUEEN));
    renormalize();
}

double Piece_Strength_Gene::piece_value(Piece_Type type) const
{
    return piece_value_raw(type)/normalizing_factor;
}

double& Piece_Strength_Gene::piece_value_ref(Piece_Type type)
{
    return piece_strength[type];
}

double Piece_Strength_Gene::piece_value_raw(Piece_Type type) const
{
    return piece_strength[type];
}

std::unique_ptr<Gene> Piece_Strength_Gene::duplicate() const
{
    return std::make_unique<Piece_Strength_Gene>(*this);
}

std::string Piece_Strength_Gene::name() const
{
    return "Piece Strength Gene";
}

double Piece_Strength_Gene::score_board(const Board&) const
{
    return 0.0;
}

void Piece_Strength_Gene::renormalize()
{
    // Sum is equal to the total strength of a player's starting pieces
    // (8 pawns, 2 rooks, 2 knights, 2 bishops, 1 queen).
    auto total = 8*piece_value(PAWN) +
                 2*piece_value(ROOK) +
                 2*piece_value(KNIGHT) +
                 2*piece_value(BISHOP) +
                   piece_value(QUEEN);

    // Use absolute value so there aren't discontinuous jumps due to small mutations.
    normalizing_factor = std::abs(total);
    if(normalizing_factor < std::numeric_limits<double>::epsilon())
    {
        // Prevent absurdly large strength return values due to near-zero sum of pieces.
        normalizing_factor = 1.0;
    }
}
