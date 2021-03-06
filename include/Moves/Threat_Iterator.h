#ifndef THREAT_ITERATOR_H
#define THREAT_ITERATOR_H

#include "Game/Color.h"

class Board;
struct Square;
class Piece;

// The iterator created by Threat_Generator that creates
// all squares that attack Square{file_start, rank_start}.
class Threat_Iterator
{
    public:
        Threat_Iterator(char target_file_in,
                        int  target_rank_in,
                        Color attack_color,
                        const Board& reference_board);

        void operator++();
        Square operator*() const;
        bool operator!=(const Threat_Iterator& other) const;
        bool operator==(const Threat_Iterator& other) const;

        Threat_Iterator make_end_iterator() const;

    private:
        char target_file;
        int  target_rank;

        int file_step;
        int rank_step;
        int step_size;
        size_t knight_index;

        Color attacking_color;
        const Board& board;
        const Piece* target_king;

        void next_threat();
        char attacking_file() const;
        int  attacking_rank() const;
        void convert_to_end_iterator();
};

#endif // THREAT_ITERATOR_H
