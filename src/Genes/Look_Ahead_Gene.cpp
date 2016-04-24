#include "Genes/Look_Ahead_Gene.h"

#include <cmath>

#include "Utility.h"

#include "Exceptions/Generic_Exception.h"

Look_Ahead_Gene::Look_Ahead_Gene() :
    Gene(0.0),
    look_ahead_constant(1)
{
    reset_properties();
}

void Look_Ahead_Gene::reset_properties()
{
    properties["Look Ahead Constant"] = &look_ahead_constant;
}

Look_Ahead_Gene::~Look_Ahead_Gene()
{
}

size_t Look_Ahead_Gene::look_ahead(double time, size_t choices_per_move) const
{
    auto result = (look_ahead_constant + std::log10(time))/std::log10(choices_per_move);
    return std::max(result, 0.0);
}

void Look_Ahead_Gene::mutate()
{
    look_ahead_constant += 0.1 + Random::random_normal(1.0);
}

Look_Ahead_Gene* Look_Ahead_Gene::duplicate() const
{
    auto dupe = new Look_Ahead_Gene(*this);
    dupe->reset_properties();
    return dupe;
}

std::string Look_Ahead_Gene::name() const
{
    return "Look Ahead Gene";
}

double Look_Ahead_Gene::score_board(const Board&, Color) const
{
    return 0.0;
}
