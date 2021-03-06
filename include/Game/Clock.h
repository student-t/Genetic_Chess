#ifndef Clock_H
#define Clock_H

#include <array>
#include <chrono>

#include "Color.h"
#include "Game_Result.h"

class CECP_Mediator;
class UCI_Mediator;

class Clock
{
    public:
        // Game clock settings: total time, moves to reset clock, time increment per move
        Clock(double duration_seconds = 0.0, size_t moves = 0, double increment_seconds = 0.0);
        Game_Result punch(); // start/stop both clocks
        void stop(); // stop both clocks
        void start(); // resume after stop()
        double time_left(Color color) const;
        size_t moves_to_reset(Color color) const;
        bool is_running() const;
        Color running_for() const;

    private:
        using fractional_seconds = std::chrono::duration<double>;

        // timers are mutable so they can be adjusted by external interfaces (xboard, UCI, etc.)
        mutable std::array<fractional_seconds, 2> timers;

        std::array<size_t, 2> moves;
        std::array<fractional_seconds, 2> initial_time;
        std::array<fractional_seconds, 2> increment;

        Color whose_turn;
        bool use_clock;
        bool use_reset;
        size_t move_count_reset;
        bool clocks_running;
        std::chrono::steady_clock::time_point time_previous_punch;

        // When playing with outside interfaces, use the external clock
        friend class CECP_Mediator;
        friend class UCI_Mediator;
        void set_time(Color player, double new_time_seconds) const;
};

#endif // Clock_H
