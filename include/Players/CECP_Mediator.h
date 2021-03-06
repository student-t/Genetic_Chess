#ifndef CECP_MEDIATOR_H
#define CECP_MEDIATOR_H

#include "Outside_Player.h"
#include "Game/Color.h"
#include "Thinking.h"

#include <string>

class Board;
class Game_Result;
class Clock;

class CECP_Mediator : public Outside_Player
{
    public:
        explicit CECP_Mediator(const Player& local_player);

        const Move& choose_move(const Board& b, const Clock& clock) const override;
        std::string receive_move(const Clock& clock) const override;

        Color get_ai_color() const override;
        void process_game_ending(const Game_Result& gee, const Board& board) const override;

        std::string name() const override;

        void initial_board_setup(Board& board) const override;

    private:
        mutable std::string first_move;
        mutable std::string received_name;
        mutable Thinking_Output_Type thinking_mode;
        mutable std::string move_text;

        void get_clock_specs() override;
        std::string receive_cecp_command() const;
        void wait_for_quit() const;
};

#endif // CECP_MEDIATOR_H
