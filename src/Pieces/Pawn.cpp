#include "Pieces/Pawn.h"
#include "Moves/Pawn_Move.h"
#include "Moves/Pawn_Capture.h"
#include "Moves/Pawn_Double_Move.h"
#include "Moves/Pawn_Promotion.h"
#include "Moves/Pawn_Promotion_by_Capture.h"
#include "Moves/En_Passant.h"

#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"

Pawn::Pawn(Color color_in) : Piece(color_in)
{
    symbol = "P";

    possible_moves.emplace_back(std::make_unique<Pawn_Move>(my_color));
    possible_moves.emplace_back(std::make_unique<Pawn_Double_Move>(my_color));

    std::vector<std::shared_ptr<const Piece>> possible_promotions;
    possible_promotions.emplace_back(std::make_shared<Queen>(my_color));
    possible_promotions.emplace_back(std::make_shared<Knight>(my_color));
    possible_promotions.emplace_back(std::make_shared<Rook>(my_color));
    possible_promotions.emplace_back(std::make_shared<Bishop>(my_color));

    for(auto dir : {'r', 'l'})
    {
        possible_moves.emplace_back(std::make_unique<Pawn_Capture>(my_color, dir));
        possible_moves.emplace_back(std::make_unique<En_Passant>(my_color, dir));
        for(auto promote : possible_promotions)
        {
            possible_moves.emplace_back(std::make_unique<Pawn_Promotion_by_Capture>(promote, dir));
        }
    }

    for(auto promote : possible_promotions)
    {
        possible_moves.emplace_back(std::make_unique<Pawn_Promotion>(promote));
    }

    // ASCII Art http://ascii.co.uk/art/chess (VK)
    ascii_art_lines.push_back("  _  ");
    ascii_art_lines.push_back(" ( ) ");
    ascii_art_lines.push_back("/___\\");
    if(color() == BLACK)
    {
        ascii_art_lines[1].replace(2, 1, "#");
        ascii_art_lines[2].replace(1, 3, "###");
    }
}

Pawn::~Pawn()
{
}

std::string Pawn::pgn_symbol() const
{
    return "";
}

bool Pawn::is_pawn() const
{
    return true;
}
