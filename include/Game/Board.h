#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include <string>
#include <array>
#include <mutex>

#include "Moves/Move.h"
#include "Moves/Kingside_Castle.h"
#include "Moves/Queenside_Castle.h"
#include "Moves/En_Passant.h"
#include "Moves/Pawn_Promotion.h"
#include "Moves/Pawn_Double_Move.h"
#include "Moves/Pawn_Move.h"

#include "Color.h"
#include "Square.h"
#include "Game_Result.h"
#include "Pieces/Piece_Types.h"
#include "Players/Player.h"
#include "Players/Thinking.h"

class Clock;

class Piece;
class Pawn;
class Rook;
class Knight;
class Bishop;
class Queen;
class King;


class Board
{
    public:
        Board();
        explicit Board(const std::string& fen); // reproduce board from Forsythe-Edwards Notation string

        Game_Result submit_move(const Move& move);

        const Move& get_move(const std::string& move, char promote = 0) const;
        const Move& get_move(char file_start, int rank_start, char file_end, int rank_end, char promote = 0) const;

        bool is_legal(char file_start, int rank_start,
                      char file_end,   int rank_end) const;

        Color whose_turn() const;
        static Color square_color(char file, int rank);

        void ascii_draw(Color perspective = WHITE) const;

        std::string fen_status() const; // current state of board in FEN
        const std::vector<const Move*>& get_game_record() const;
        std::string get_last_move_record() const;

        // Communication between players
        void set_thinking_mode(Thinking_Output_Type) const;
        Thinking_Output_Type get_thinking_mode() const;

        // With commentary
        void print_game_record(const Player* white,
                               const Player* black,
                               const std::string& file_name,
                               const Game_Result& result,
                               double initial_time,
                               size_t moves_to_reset,
                               double increment,
                               const Clock& game_clock) const;

        std::string last_move_coordinates() const;

        void set_turn(Color color);

        static bool inside_board(char file, int rank);
        static bool inside_board(char file);
        static bool inside_board(int rank);

        static size_t board_index(char file, int rank);

        const Piece* piece_on_square(char file, int rank) const;

        const std::vector<const Move*>& legal_moves() const;
        const std::vector<const Move*>& other_moves() const;

        bool safe_for_king(char file, int rank, Color king_color) const;
        bool is_en_passant_targetable(char file, int rank) const;
        bool piece_has_moved(char file, int rank) const;
        Square find_king(Color color) const;
        bool king_is_in_check() const;
        bool king_is_in_check_after_move(const Move& move) const;
        Square piece_is_pinned(char file, int rank) const; // returns pinning square or {'\0', 0} if none
        bool all_empty_between(char file_start, int rank_start, char file_end, int rank_end) const;
        bool enough_material_to_checkmate() const;

        // Methods for gene reference
        bool capture_possible() const;
        bool has_castled(Color player) const;
        std::array<bool, 64> all_square_indices_attacked_by(Color player) const;
        size_t number_of_promoted_pawns(Color color) const;

        static const Piece* get_piece(Piece_Type piece_type, Color color);

    private:
        std::array<const Piece*, 64> board;
        std::map<uint64_t, int> repeat_count;
        Color turn_color;
        std::vector<const Move*> game_record;
        std::array<bool, 64> unmoved_positions;
        Square en_passant_target;
        std::string starting_fen;
        std::array<Square, 2> king_location;
        size_t move_count_start_offset;

        // Information cache for gene reference
        std::array<bool, 2> already_castled;
        std::array<size_t, 2> promoted_pawns_count;
        bool capturing_move_available;

        // Pieces
        static const Rook   white_rook;
        static const Knight white_knight;
        static const Bishop white_bishop;
        static const Queen  white_queen;
        static const King   white_king;
        static const Pawn   white_pawn;

        static const Rook   black_rook;
        static const Knight black_knight;
        static const Bishop black_bishop;
        static const Queen  black_queen;
        static const King   black_king;
        static const Pawn   black_pawn;

        // Caches
        std::vector<const Move*> other_moves_cache;
        std::vector<const Move*> legal_moves_cache;
        std::vector<Square> checking_squares;

        void recreate_move_caches();
        void refresh_checking_squares();

        // Communication channels
        mutable Thinking_Output_Type thinking_indicator;

        const Piece*& piece_on_square(char file, int rank);
        void remove_piece(char file, int rank);
        void make_move(char file_start, int rank_start, char file_end, int rank_end);
        bool no_legal_moves() const;
        std::string board_status() const; // for detecting threefold repetition
        void make_en_passant_targetable(char file, int rank);
        void clear_en_passant_target();
        bool is_in_legal_moves_list(const Move& move) const;
        void place_piece(const Piece* piece, char file, int rank);
        void switch_turn();
        void set_unmoved(char file, int rank);

        // Zobrist hashing
        uint64_t board_hash;

        void initialize_board_hash();
        uint64_t get_board_hash() const;

        // Hash values for squares
        static std::mutex hash_lock;
        static bool hash_values_initialized;
        static std::array<std::map<const Piece*, uint64_t>, 64> square_hash_values; // [board_index][moved?][piece_hash]
        static std::array<uint64_t, 64> en_passant_hash_values;
        static std::array<uint64_t, 64> castling_hash_values;

        void update_board_hash(char file, int rank);
        uint64_t get_square_hash(char file, int rank) const;

        // Whose turn?
        static std::array<uint64_t, 2> color_hash_values; // for whose_turn() hashing

        uint64_t get_color_hash(Color color) const;
        void update_board_hash(Color color);

        bool king_multiply_checked() const;
        static bool straight_line_move(char file_start, int rank_start, char file_end, int rank_end);
        bool attacks(char origin_file, int origin_rank, char target_file, int target_rank) const;

        // Moves with side effects are friends of Board
        friend void Kingside_Castle::side_effects(Board&) const; // moves second piece
        friend void Queenside_Castle::side_effects(Board&) const; // moves second piece
        friend void En_Passant::side_effects(Board&) const; // capture piece on another square
        friend void Pawn_Promotion::side_effects(Board&) const; // replace piece
        friend void Pawn_Double_Move::side_effects(Board&) const; // mark square as En Passant target
        friend void Pawn_Move::side_effects(Board&) const; // reset three-fold and 50-move counts
};

#endif // BOARD_H
