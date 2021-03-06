#ifndef GENETIC_AI_H
#define GENETIC_AI_H

#include <iosfwd>
#include <string>

#include "Player.h"

#include "Genes/Genome.h"
#include "Moves/Move.h"

class Board;
class Clock;
struct Game_Tree_Node_Result;

class Genetic_AI : public Player
{
    public:
        Genetic_AI();
        explicit Genetic_AI(const std::string& file_name); // read genome from file
        Genetic_AI(const std::string& file_name, int id); // read genome from gene pool file with ID
        explicit Genetic_AI(std::istream& is); // read genome from file
        Genetic_AI(const Genetic_AI& gai_mother,
                   const Genetic_AI& gai_father); // offspring with random recombination of genes

        void mutate(bool just_testing = false);
        const Move& choose_move(const Board& board, const Clock& clock) const override;

        std::string name() const override;
        std::string author() const override;

        std::string get_commentary_for_move(size_t move_number) const override;

        void print_genome(const std::string& file_name = "") const;
        void print_genome(std::ostream& file) const;

        int get_id() const;
        bool operator<(const Genetic_AI& other) const;
        bool operator==(const Genetic_AI& other) const;

    private:
        Genome genome;

        static int next_id;
        int id;
        double value_of_centipawn;

        mutable std::vector<const Move*> principal_variation;
        mutable std::vector<std::vector<const Move*>> commentary;

        // Monitor search speed to adapt to different computers/competing workloads
        mutable int nodes_searched;
        mutable double clock_start_time;
        mutable size_t maximum_depth;

        mutable int nodes_evaluated;
        mutable double total_evaluation_time;
        mutable double evaluation_speed;

        void read_from(std::istream& is);

        // Minimax (actually negamax) with alpha-beta pruning
        Game_Tree_Node_Result search_game_tree(const Board& board,
                                               double time_to_examine,
                                               const Clock& clock,
                                               size_t depth,
                                               Game_Tree_Node_Result alpha,
                                               const Game_Tree_Node_Result& beta,
                                               bool still_on_principal_variation) const;

        Game_Tree_Node_Result create_result(const Board& board,
                                            Color perspective,
                                            Game_Result move_result,
                                            size_t depth) const;

        // Output thinking to stdout
        void output_thinking_cecp(const Game_Tree_Node_Result& thought,
                                  const Clock& clock,
                                  Color perspective) const;

        void calibrate_thinking_speed();
        double centipawn_value() const;
        void calculate_centipawn_value();
};

#endif // GENETIC_AI_H
