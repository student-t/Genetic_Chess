#ifndef TESTING_H
#define TESTING_H

#include <memory>
#include <cstdlib>

#include "Game/Board.h"
#include "Moves/Move.h"
#include "Players/Genetic_AI.h"

#include "Utility.h"

#include "Exceptions/Illegal_Move_Exception.h"

void run_tests()
{
    // Castling with attacking piece
    for(auto castle_side : std::string("KQ"))
    {
        for(int rook_left_space = 0; rook_left_space < 8; ++rook_left_space)
        {
            auto rook_left  = (rook_left_space > 0 ? String::to_string(rook_left_space) : std::string());
            auto rook_right = (rook_left_space < 7 ? String::to_string(7 - rook_left_space) : std::string());
            Board board("1k6/" + rook_left + "r" + rook_right + "/8/8/8/8/8/R3K2R w KQ - 0 1");

            char final_file = (castle_side == 'K' ? 'g' : 'c');

            try
            {
                board.get_complete_move('e', 1, final_file, 1);
            }
            catch(const Illegal_Move_Exception&)
            {
                if(castle_side == 'K')
                {
                    if(rook_left_space >= 4 && rook_left_space <= 6)
                    {
                        continue;
                    }
                }
                else
                {
                    if(rook_left_space >= 2 && rook_left_space <= 4)
                    {
                        continue;
                    }
                }

                board.ascii_draw(WHITE);
                std::cout << String::to_string(castle_side) + "-castle should be legal here." << std::endl;
                throw Illegal_Move_Exception("test failed");
            }

            if(castle_side == 'K')
            {
                if(rook_left_space < 4 || rook_left_space > 6)
                {
                    continue;
                }
            }
            else
            {
                if(rook_left_space < 2 || rook_left_space > 4)
                {
                    continue;
                }
            }

            board.ascii_draw(WHITE);
            std::cout << String::to_string(castle_side) + "-castle should be illegal here." << std::endl;
            throw Illegal_Move_Exception("Test failed.");
        }
    }


    // Test Genetic_AI file loading
    auto ai1 = Genetic_AI();
    for(int i = 0; i < 1000; ++i)
    {
        ai1.mutate();
    }
    auto file_name1 = "genome1.txt";
    auto file_name2 = "genome2.txt";
    remove(file_name1);
    remove(file_name2);

    ai1.print_genome(file_name1);

    auto ai2 = Genetic_AI(file_name1);
    ai2.print_genome(file_name2);

    std::ifstream file1(file_name1);
    std::ifstream file2(file_name2);
    int line_count = 0;

    while(true)
    {
        std::string line1, line2;
        std::getline(file1, line1);
        std::getline(file2, line2);
        ++line_count;

        if(line1 != line2)
        {
            std::cerr << "Mismatch at line " << line_count << ":\n";
            std::cerr << line1 << " != " << line2 << "\n";
            throw Generic_Exception("Test failed!");
        }

        if( ! file1 && ! file2)
        {
            break;
        }
    }

    remove(file_name1);
    remove(file_name2);
    std::cout << "All tests passed." << std::endl;
}

#endif // TESTING_H
