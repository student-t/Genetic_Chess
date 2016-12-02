#include "Players/Human_Player.h"

#include <string>
#include <iostream>

#include "Game/Board.h"
#include "Game/Clock.h"
#include "Moves/Move.h"

#include "Exceptions/Illegal_Move_Exception.h"
#include "Exceptions/Promotion_Exception.h"

Human_Player::Human_Player()
{
    std::cout << "Enter name: ";
    getline(std::cin, player_name);
}

Human_Player::~Human_Player()
{
}

const Complete_Move Human_Player::choose_move(const Board& board, const Clock& clock) const
{
    auto last_move_illegal = false;
    std::string why_illegal;
    std::string move;

    while(true)
    {
        board.ascii_draw(board.whose_turn());
        if(last_move_illegal)
        {
            std::cout << "Illegal move: " << move << " (" << why_illegal << ")" << std::endl;
        }
        std::cout << color_text(board.whose_turn());
        if( ! name().empty())
        {
            std::cout << " (" << name() << ")";
        }
        std::cout << " to move   |   ";
        std::cout << "Last move: " << board.last_move() << "   |   ";
        std::cout << "Time remaining: " << clock.time_left(board.whose_turn()) << std::endl;
        std::cout << "Enter move: ";
        std::getline(std::cin, move);
        try
        {
            board.ascii_draw(opposite(board.whose_turn()));
            return board.get_complete_move(move);
        }
        catch(const Illegal_Move_Exception& e)
        {
            last_move_illegal = true;
            why_illegal = e.what();
            continue;
        }
        catch(const Promotion_Exception&)
        {
            std::cout << "What should the pawn be promoted to?\n";
            std::cout << "Choice: [B N R Q]: ";
            char promote;
            std::cin >> promote;
            try
            {
                board.ascii_draw(opposite(board.whose_turn()));
                return board.get_complete_move(move, promote);
            }
            catch(const Illegal_Move_Exception& e)
            {
                last_move_illegal = true;
                why_illegal = e.what();
                continue;
            }
        }
    }
}

std::string Human_Player::name() const
{
    return player_name;
}
