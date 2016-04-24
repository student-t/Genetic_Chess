#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = -Iinclude
CFLAGS = -Wnon-virtual-dtor -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -pedantic -Wzero-as-null-pointer-constant -std=c++11 -Wextra -Wall -fexceptions
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC) -Iinclude/Genes -Iinclude
CFLAGS_DEBUG = $(CFLAGS) -g -DDEBUG
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/genetic_chess

INC_RELEASE = $(INC) -Iinclude/Genes -Iinclude
CFLAGS_RELEASE = $(CFLAGS) -fexpensive-optimizations -O3
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/genetic_chess

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/Game/Game.o $(OBJDIR_DEBUG)/src/Genes/Piece_Strength_Gene.o $(OBJDIR_DEBUG)/src/Genes/Pawn_Advancement_Gene.o $(OBJDIR_DEBUG)/src/Genes/Opponent_Pieces_Targeted_Gene.o $(OBJDIR_DEBUG)/src/Genes/Look_Ahead_Gene.o $(OBJDIR_DEBUG)/src/Genes/Last_Minute_Panic_Gene.o $(OBJDIR_DEBUG)/src/Genes/King_Confinement_Gene.o $(OBJDIR_DEBUG)/src/Genes/Genome.o $(OBJDIR_DEBUG)/src/Genes/Gene_Pool.o $(OBJDIR_DEBUG)/src/Genes/Gene.o $(OBJDIR_DEBUG)/src/Genes/Freedom_To_Move_Gene.o $(OBJDIR_DEBUG)/src/Genes/Branch_Pruning_Gene.o $(OBJDIR_DEBUG)/src/Game/Square.o $(OBJDIR_DEBUG)/src/Genes/Sphere_of_Influence_Gene.o $(OBJDIR_DEBUG)/src/Game/Color.o $(OBJDIR_DEBUG)/src/Game/Clock.o $(OBJDIR_DEBUG)/src/Game/Board.o $(OBJDIR_DEBUG)/src/Exceptions/Stalemate_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/Promotion_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/Out_Of_Time_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/Illegal_Move_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/Generic_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/Game_Ending_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/End_Of_File_Exception.o $(OBJDIR_DEBUG)/src/Exceptions/Checkmate_Exception.o $(OBJDIR_DEBUG)/src/Pieces/King.o $(OBJDIR_DEBUG)/src/Utility.o $(OBJDIR_DEBUG)/src/Players/Random_AI.o $(OBJDIR_DEBUG)/src/Players/Player.o $(OBJDIR_DEBUG)/src/Players/Outside_Player.o $(OBJDIR_DEBUG)/src/Players/Human_Player.o $(OBJDIR_DEBUG)/src/Players/Genetic_AI.o $(OBJDIR_DEBUG)/src/Players/AI_Player.o $(OBJDIR_DEBUG)/src/Pieces/Rook.o $(OBJDIR_DEBUG)/src/Pieces/Queen.o $(OBJDIR_DEBUG)/src/Pieces/Piece.o $(OBJDIR_DEBUG)/src/Pieces/Pawn.o $(OBJDIR_DEBUG)/src/Pieces/Knight.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/src/Pieces/Bishop.o $(OBJDIR_DEBUG)/src/Moves/Queenside_Castle.o $(OBJDIR_DEBUG)/src/Moves/Pawn_Promotion_by_Capture.o $(OBJDIR_DEBUG)/src/Moves/Pawn_Promotion.o $(OBJDIR_DEBUG)/src/Moves/Pawn_Move.o $(OBJDIR_DEBUG)/src/Moves/Pawn_Double_Move.o $(OBJDIR_DEBUG)/src/Moves/Pawn_Capture.o $(OBJDIR_DEBUG)/src/Moves/Move.o $(OBJDIR_DEBUG)/src/Moves/Kingside_Castle.o $(OBJDIR_DEBUG)/src/Moves/En_Passant.o $(OBJDIR_DEBUG)/src/Genes/Total_Force_Gene.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/Game/Game.o $(OBJDIR_RELEASE)/src/Genes/Piece_Strength_Gene.o $(OBJDIR_RELEASE)/src/Genes/Pawn_Advancement_Gene.o $(OBJDIR_RELEASE)/src/Genes/Opponent_Pieces_Targeted_Gene.o $(OBJDIR_RELEASE)/src/Genes/Look_Ahead_Gene.o $(OBJDIR_RELEASE)/src/Genes/Last_Minute_Panic_Gene.o $(OBJDIR_RELEASE)/src/Genes/King_Confinement_Gene.o $(OBJDIR_RELEASE)/src/Genes/Genome.o $(OBJDIR_RELEASE)/src/Genes/Gene_Pool.o $(OBJDIR_RELEASE)/src/Genes/Gene.o $(OBJDIR_RELEASE)/src/Genes/Freedom_To_Move_Gene.o $(OBJDIR_RELEASE)/src/Genes/Branch_Pruning_Gene.o $(OBJDIR_RELEASE)/src/Game/Square.o $(OBJDIR_RELEASE)/src/Genes/Sphere_of_Influence_Gene.o $(OBJDIR_RELEASE)/src/Game/Color.o $(OBJDIR_RELEASE)/src/Game/Clock.o $(OBJDIR_RELEASE)/src/Game/Board.o $(OBJDIR_RELEASE)/src/Exceptions/Stalemate_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/Promotion_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/Out_Of_Time_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/Illegal_Move_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/Generic_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/Game_Ending_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/End_Of_File_Exception.o $(OBJDIR_RELEASE)/src/Exceptions/Checkmate_Exception.o $(OBJDIR_RELEASE)/src/Pieces/King.o $(OBJDIR_RELEASE)/src/Utility.o $(OBJDIR_RELEASE)/src/Players/Random_AI.o $(OBJDIR_RELEASE)/src/Players/Player.o $(OBJDIR_RELEASE)/src/Players/Outside_Player.o $(OBJDIR_RELEASE)/src/Players/Human_Player.o $(OBJDIR_RELEASE)/src/Players/Genetic_AI.o $(OBJDIR_RELEASE)/src/Players/AI_Player.o $(OBJDIR_RELEASE)/src/Pieces/Rook.o $(OBJDIR_RELEASE)/src/Pieces/Queen.o $(OBJDIR_RELEASE)/src/Pieces/Piece.o $(OBJDIR_RELEASE)/src/Pieces/Pawn.o $(OBJDIR_RELEASE)/src/Pieces/Knight.o $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/src/Pieces/Bishop.o $(OBJDIR_RELEASE)/src/Moves/Queenside_Castle.o $(OBJDIR_RELEASE)/src/Moves/Pawn_Promotion_by_Capture.o $(OBJDIR_RELEASE)/src/Moves/Pawn_Promotion.o $(OBJDIR_RELEASE)/src/Moves/Pawn_Move.o $(OBJDIR_RELEASE)/src/Moves/Pawn_Double_Move.o $(OBJDIR_RELEASE)/src/Moves/Pawn_Capture.o $(OBJDIR_RELEASE)/src/Moves/Move.o $(OBJDIR_RELEASE)/src/Moves/Kingside_Castle.o $(OBJDIR_RELEASE)/src/Moves/En_Passant.o $(OBJDIR_RELEASE)/src/Genes/Total_Force_Gene.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src/Game || mkdir -p $(OBJDIR_DEBUG)/src/Game
	test -d $(OBJDIR_DEBUG)/src/Genes || mkdir -p $(OBJDIR_DEBUG)/src/Genes
	test -d $(OBJDIR_DEBUG)/src/Exceptions || mkdir -p $(OBJDIR_DEBUG)/src/Exceptions
	test -d $(OBJDIR_DEBUG)/src/Pieces || mkdir -p $(OBJDIR_DEBUG)/src/Pieces
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src
	test -d $(OBJDIR_DEBUG)/src/Players || mkdir -p $(OBJDIR_DEBUG)/src/Players
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	test -d $(OBJDIR_DEBUG)/src/Moves || mkdir -p $(OBJDIR_DEBUG)/src/Moves

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/src/Game/Game.o: src/Game/Game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Game/Game.cpp -o $(OBJDIR_DEBUG)/src/Game/Game.o

$(OBJDIR_DEBUG)/src/Genes/Piece_Strength_Gene.o: src/Genes/Piece_Strength_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Piece_Strength_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Piece_Strength_Gene.o

$(OBJDIR_DEBUG)/src/Genes/Pawn_Advancement_Gene.o: src/Genes/Pawn_Advancement_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Pawn_Advancement_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Pawn_Advancement_Gene.o

$(OBJDIR_DEBUG)/src/Genes/Opponent_Pieces_Targeted_Gene.o: src/Genes/Opponent_Pieces_Targeted_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Opponent_Pieces_Targeted_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Opponent_Pieces_Targeted_Gene.o

$(OBJDIR_DEBUG)/src/Genes/Look_Ahead_Gene.o: src/Genes/Look_Ahead_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Look_Ahead_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Look_Ahead_Gene.o

$(OBJDIR_DEBUG)/src/Genes/Last_Minute_Panic_Gene.o: src/Genes/Last_Minute_Panic_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Last_Minute_Panic_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Last_Minute_Panic_Gene.o

$(OBJDIR_DEBUG)/src/Genes/King_Confinement_Gene.o: src/Genes/King_Confinement_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/King_Confinement_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/King_Confinement_Gene.o

$(OBJDIR_DEBUG)/src/Genes/Genome.o: src/Genes/Genome.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Genome.cpp -o $(OBJDIR_DEBUG)/src/Genes/Genome.o

$(OBJDIR_DEBUG)/src/Genes/Gene_Pool.o: src/Genes/Gene_Pool.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Gene_Pool.cpp -o $(OBJDIR_DEBUG)/src/Genes/Gene_Pool.o

$(OBJDIR_DEBUG)/src/Genes/Gene.o: src/Genes/Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Gene.o

$(OBJDIR_DEBUG)/src/Genes/Freedom_To_Move_Gene.o: src/Genes/Freedom_To_Move_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Freedom_To_Move_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Freedom_To_Move_Gene.o

$(OBJDIR_DEBUG)/src/Genes/Branch_Pruning_Gene.o: src/Genes/Branch_Pruning_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Branch_Pruning_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Branch_Pruning_Gene.o

$(OBJDIR_DEBUG)/src/Game/Square.o: src/Game/Square.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Game/Square.cpp -o $(OBJDIR_DEBUG)/src/Game/Square.o

$(OBJDIR_DEBUG)/src/Genes/Sphere_of_Influence_Gene.o: src/Genes/Sphere_of_Influence_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Sphere_of_Influence_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Sphere_of_Influence_Gene.o

$(OBJDIR_DEBUG)/src/Game/Color.o: src/Game/Color.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Game/Color.cpp -o $(OBJDIR_DEBUG)/src/Game/Color.o

$(OBJDIR_DEBUG)/src/Game/Clock.o: src/Game/Clock.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Game/Clock.cpp -o $(OBJDIR_DEBUG)/src/Game/Clock.o

$(OBJDIR_DEBUG)/src/Game/Board.o: src/Game/Board.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Game/Board.cpp -o $(OBJDIR_DEBUG)/src/Game/Board.o

$(OBJDIR_DEBUG)/src/Exceptions/Stalemate_Exception.o: src/Exceptions/Stalemate_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Stalemate_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Stalemate_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/Promotion_Exception.o: src/Exceptions/Promotion_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Promotion_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Promotion_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/Out_Of_Time_Exception.o: src/Exceptions/Out_Of_Time_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Out_Of_Time_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Out_Of_Time_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/Illegal_Move_Exception.o: src/Exceptions/Illegal_Move_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Illegal_Move_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Illegal_Move_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/Generic_Exception.o: src/Exceptions/Generic_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Generic_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Generic_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/Game_Ending_Exception.o: src/Exceptions/Game_Ending_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Game_Ending_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Game_Ending_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/End_Of_File_Exception.o: src/Exceptions/End_Of_File_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/End_Of_File_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/End_Of_File_Exception.o

$(OBJDIR_DEBUG)/src/Exceptions/Checkmate_Exception.o: src/Exceptions/Checkmate_Exception.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Exceptions/Checkmate_Exception.cpp -o $(OBJDIR_DEBUG)/src/Exceptions/Checkmate_Exception.o

$(OBJDIR_DEBUG)/src/Pieces/King.o: src/Pieces/King.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/King.cpp -o $(OBJDIR_DEBUG)/src/Pieces/King.o

$(OBJDIR_DEBUG)/src/Utility.o: src/Utility.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Utility.cpp -o $(OBJDIR_DEBUG)/src/Utility.o

$(OBJDIR_DEBUG)/src/Players/Random_AI.o: src/Players/Random_AI.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Players/Random_AI.cpp -o $(OBJDIR_DEBUG)/src/Players/Random_AI.o

$(OBJDIR_DEBUG)/src/Players/Player.o: src/Players/Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Players/Player.cpp -o $(OBJDIR_DEBUG)/src/Players/Player.o

$(OBJDIR_DEBUG)/src/Players/Outside_Player.o: src/Players/Outside_Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Players/Outside_Player.cpp -o $(OBJDIR_DEBUG)/src/Players/Outside_Player.o

$(OBJDIR_DEBUG)/src/Players/Human_Player.o: src/Players/Human_Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Players/Human_Player.cpp -o $(OBJDIR_DEBUG)/src/Players/Human_Player.o

$(OBJDIR_DEBUG)/src/Players/Genetic_AI.o: src/Players/Genetic_AI.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Players/Genetic_AI.cpp -o $(OBJDIR_DEBUG)/src/Players/Genetic_AI.o

$(OBJDIR_DEBUG)/src/Players/AI_Player.o: src/Players/AI_Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Players/AI_Player.cpp -o $(OBJDIR_DEBUG)/src/Players/AI_Player.o

$(OBJDIR_DEBUG)/src/Pieces/Rook.o: src/Pieces/Rook.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/Rook.cpp -o $(OBJDIR_DEBUG)/src/Pieces/Rook.o

$(OBJDIR_DEBUG)/src/Pieces/Queen.o: src/Pieces/Queen.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/Queen.cpp -o $(OBJDIR_DEBUG)/src/Pieces/Queen.o

$(OBJDIR_DEBUG)/src/Pieces/Piece.o: src/Pieces/Piece.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/Piece.cpp -o $(OBJDIR_DEBUG)/src/Pieces/Piece.o

$(OBJDIR_DEBUG)/src/Pieces/Pawn.o: src/Pieces/Pawn.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/Pawn.cpp -o $(OBJDIR_DEBUG)/src/Pieces/Pawn.o

$(OBJDIR_DEBUG)/src/Pieces/Knight.o: src/Pieces/Knight.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/Knight.cpp -o $(OBJDIR_DEBUG)/src/Pieces/Knight.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/src/Pieces/Bishop.o: src/Pieces/Bishop.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Pieces/Bishop.cpp -o $(OBJDIR_DEBUG)/src/Pieces/Bishop.o

$(OBJDIR_DEBUG)/src/Moves/Queenside_Castle.o: src/Moves/Queenside_Castle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Queenside_Castle.cpp -o $(OBJDIR_DEBUG)/src/Moves/Queenside_Castle.o

$(OBJDIR_DEBUG)/src/Moves/Pawn_Promotion_by_Capture.o: src/Moves/Pawn_Promotion_by_Capture.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Pawn_Promotion_by_Capture.cpp -o $(OBJDIR_DEBUG)/src/Moves/Pawn_Promotion_by_Capture.o

$(OBJDIR_DEBUG)/src/Moves/Pawn_Promotion.o: src/Moves/Pawn_Promotion.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Pawn_Promotion.cpp -o $(OBJDIR_DEBUG)/src/Moves/Pawn_Promotion.o

$(OBJDIR_DEBUG)/src/Moves/Pawn_Move.o: src/Moves/Pawn_Move.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Pawn_Move.cpp -o $(OBJDIR_DEBUG)/src/Moves/Pawn_Move.o

$(OBJDIR_DEBUG)/src/Moves/Pawn_Double_Move.o: src/Moves/Pawn_Double_Move.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Pawn_Double_Move.cpp -o $(OBJDIR_DEBUG)/src/Moves/Pawn_Double_Move.o

$(OBJDIR_DEBUG)/src/Moves/Pawn_Capture.o: src/Moves/Pawn_Capture.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Pawn_Capture.cpp -o $(OBJDIR_DEBUG)/src/Moves/Pawn_Capture.o

$(OBJDIR_DEBUG)/src/Moves/Move.o: src/Moves/Move.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Move.cpp -o $(OBJDIR_DEBUG)/src/Moves/Move.o

$(OBJDIR_DEBUG)/src/Moves/Kingside_Castle.o: src/Moves/Kingside_Castle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/Kingside_Castle.cpp -o $(OBJDIR_DEBUG)/src/Moves/Kingside_Castle.o

$(OBJDIR_DEBUG)/src/Moves/En_Passant.o: src/Moves/En_Passant.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Moves/En_Passant.cpp -o $(OBJDIR_DEBUG)/src/Moves/En_Passant.o

$(OBJDIR_DEBUG)/src/Genes/Total_Force_Gene.o: src/Genes/Total_Force_Gene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Genes/Total_Force_Gene.cpp -o $(OBJDIR_DEBUG)/src/Genes/Total_Force_Gene.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src/Game
	rm -rf $(OBJDIR_DEBUG)/src/Genes
	rm -rf $(OBJDIR_DEBUG)/src/Exceptions
	rm -rf $(OBJDIR_DEBUG)/src/Pieces
	rm -rf $(OBJDIR_DEBUG)/src
	rm -rf $(OBJDIR_DEBUG)/src/Players
	rm -rf $(OBJDIR_DEBUG)
	rm -rf $(OBJDIR_DEBUG)/src/Moves

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src/Game || mkdir -p $(OBJDIR_RELEASE)/src/Game
	test -d $(OBJDIR_RELEASE)/src/Genes || mkdir -p $(OBJDIR_RELEASE)/src/Genes
	test -d $(OBJDIR_RELEASE)/src/Exceptions || mkdir -p $(OBJDIR_RELEASE)/src/Exceptions
	test -d $(OBJDIR_RELEASE)/src/Pieces || mkdir -p $(OBJDIR_RELEASE)/src/Pieces
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src
	test -d $(OBJDIR_RELEASE)/src/Players || mkdir -p $(OBJDIR_RELEASE)/src/Players
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	test -d $(OBJDIR_RELEASE)/src/Moves || mkdir -p $(OBJDIR_RELEASE)/src/Moves

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/src/Game/Game.o: src/Game/Game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Game/Game.cpp -o $(OBJDIR_RELEASE)/src/Game/Game.o

$(OBJDIR_RELEASE)/src/Genes/Piece_Strength_Gene.o: src/Genes/Piece_Strength_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Piece_Strength_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Piece_Strength_Gene.o

$(OBJDIR_RELEASE)/src/Genes/Pawn_Advancement_Gene.o: src/Genes/Pawn_Advancement_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Pawn_Advancement_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Pawn_Advancement_Gene.o

$(OBJDIR_RELEASE)/src/Genes/Opponent_Pieces_Targeted_Gene.o: src/Genes/Opponent_Pieces_Targeted_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Opponent_Pieces_Targeted_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Opponent_Pieces_Targeted_Gene.o

$(OBJDIR_RELEASE)/src/Genes/Look_Ahead_Gene.o: src/Genes/Look_Ahead_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Look_Ahead_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Look_Ahead_Gene.o

$(OBJDIR_RELEASE)/src/Genes/Last_Minute_Panic_Gene.o: src/Genes/Last_Minute_Panic_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Last_Minute_Panic_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Last_Minute_Panic_Gene.o

$(OBJDIR_RELEASE)/src/Genes/King_Confinement_Gene.o: src/Genes/King_Confinement_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/King_Confinement_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/King_Confinement_Gene.o

$(OBJDIR_RELEASE)/src/Genes/Genome.o: src/Genes/Genome.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Genome.cpp -o $(OBJDIR_RELEASE)/src/Genes/Genome.o

$(OBJDIR_RELEASE)/src/Genes/Gene_Pool.o: src/Genes/Gene_Pool.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Gene_Pool.cpp -o $(OBJDIR_RELEASE)/src/Genes/Gene_Pool.o

$(OBJDIR_RELEASE)/src/Genes/Gene.o: src/Genes/Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Gene.o

$(OBJDIR_RELEASE)/src/Genes/Freedom_To_Move_Gene.o: src/Genes/Freedom_To_Move_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Freedom_To_Move_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Freedom_To_Move_Gene.o

$(OBJDIR_RELEASE)/src/Genes/Branch_Pruning_Gene.o: src/Genes/Branch_Pruning_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Branch_Pruning_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Branch_Pruning_Gene.o

$(OBJDIR_RELEASE)/src/Game/Square.o: src/Game/Square.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Game/Square.cpp -o $(OBJDIR_RELEASE)/src/Game/Square.o

$(OBJDIR_RELEASE)/src/Genes/Sphere_of_Influence_Gene.o: src/Genes/Sphere_of_Influence_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Sphere_of_Influence_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Sphere_of_Influence_Gene.o

$(OBJDIR_RELEASE)/src/Game/Color.o: src/Game/Color.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Game/Color.cpp -o $(OBJDIR_RELEASE)/src/Game/Color.o

$(OBJDIR_RELEASE)/src/Game/Clock.o: src/Game/Clock.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Game/Clock.cpp -o $(OBJDIR_RELEASE)/src/Game/Clock.o

$(OBJDIR_RELEASE)/src/Game/Board.o: src/Game/Board.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Game/Board.cpp -o $(OBJDIR_RELEASE)/src/Game/Board.o

$(OBJDIR_RELEASE)/src/Exceptions/Stalemate_Exception.o: src/Exceptions/Stalemate_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Stalemate_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Stalemate_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/Promotion_Exception.o: src/Exceptions/Promotion_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Promotion_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Promotion_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/Out_Of_Time_Exception.o: src/Exceptions/Out_Of_Time_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Out_Of_Time_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Out_Of_Time_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/Illegal_Move_Exception.o: src/Exceptions/Illegal_Move_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Illegal_Move_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Illegal_Move_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/Generic_Exception.o: src/Exceptions/Generic_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Generic_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Generic_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/Game_Ending_Exception.o: src/Exceptions/Game_Ending_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Game_Ending_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Game_Ending_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/End_Of_File_Exception.o: src/Exceptions/End_Of_File_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/End_Of_File_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/End_Of_File_Exception.o

$(OBJDIR_RELEASE)/src/Exceptions/Checkmate_Exception.o: src/Exceptions/Checkmate_Exception.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Exceptions/Checkmate_Exception.cpp -o $(OBJDIR_RELEASE)/src/Exceptions/Checkmate_Exception.o

$(OBJDIR_RELEASE)/src/Pieces/King.o: src/Pieces/King.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/King.cpp -o $(OBJDIR_RELEASE)/src/Pieces/King.o

$(OBJDIR_RELEASE)/src/Utility.o: src/Utility.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Utility.cpp -o $(OBJDIR_RELEASE)/src/Utility.o

$(OBJDIR_RELEASE)/src/Players/Random_AI.o: src/Players/Random_AI.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Players/Random_AI.cpp -o $(OBJDIR_RELEASE)/src/Players/Random_AI.o

$(OBJDIR_RELEASE)/src/Players/Player.o: src/Players/Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Players/Player.cpp -o $(OBJDIR_RELEASE)/src/Players/Player.o

$(OBJDIR_RELEASE)/src/Players/Outside_Player.o: src/Players/Outside_Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Players/Outside_Player.cpp -o $(OBJDIR_RELEASE)/src/Players/Outside_Player.o

$(OBJDIR_RELEASE)/src/Players/Human_Player.o: src/Players/Human_Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Players/Human_Player.cpp -o $(OBJDIR_RELEASE)/src/Players/Human_Player.o

$(OBJDIR_RELEASE)/src/Players/Genetic_AI.o: src/Players/Genetic_AI.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Players/Genetic_AI.cpp -o $(OBJDIR_RELEASE)/src/Players/Genetic_AI.o

$(OBJDIR_RELEASE)/src/Players/AI_Player.o: src/Players/AI_Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Players/AI_Player.cpp -o $(OBJDIR_RELEASE)/src/Players/AI_Player.o

$(OBJDIR_RELEASE)/src/Pieces/Rook.o: src/Pieces/Rook.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/Rook.cpp -o $(OBJDIR_RELEASE)/src/Pieces/Rook.o

$(OBJDIR_RELEASE)/src/Pieces/Queen.o: src/Pieces/Queen.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/Queen.cpp -o $(OBJDIR_RELEASE)/src/Pieces/Queen.o

$(OBJDIR_RELEASE)/src/Pieces/Piece.o: src/Pieces/Piece.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/Piece.cpp -o $(OBJDIR_RELEASE)/src/Pieces/Piece.o

$(OBJDIR_RELEASE)/src/Pieces/Pawn.o: src/Pieces/Pawn.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/Pawn.cpp -o $(OBJDIR_RELEASE)/src/Pieces/Pawn.o

$(OBJDIR_RELEASE)/src/Pieces/Knight.o: src/Pieces/Knight.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/Knight.cpp -o $(OBJDIR_RELEASE)/src/Pieces/Knight.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/src/Pieces/Bishop.o: src/Pieces/Bishop.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Pieces/Bishop.cpp -o $(OBJDIR_RELEASE)/src/Pieces/Bishop.o

$(OBJDIR_RELEASE)/src/Moves/Queenside_Castle.o: src/Moves/Queenside_Castle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Queenside_Castle.cpp -o $(OBJDIR_RELEASE)/src/Moves/Queenside_Castle.o

$(OBJDIR_RELEASE)/src/Moves/Pawn_Promotion_by_Capture.o: src/Moves/Pawn_Promotion_by_Capture.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Pawn_Promotion_by_Capture.cpp -o $(OBJDIR_RELEASE)/src/Moves/Pawn_Promotion_by_Capture.o

$(OBJDIR_RELEASE)/src/Moves/Pawn_Promotion.o: src/Moves/Pawn_Promotion.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Pawn_Promotion.cpp -o $(OBJDIR_RELEASE)/src/Moves/Pawn_Promotion.o

$(OBJDIR_RELEASE)/src/Moves/Pawn_Move.o: src/Moves/Pawn_Move.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Pawn_Move.cpp -o $(OBJDIR_RELEASE)/src/Moves/Pawn_Move.o

$(OBJDIR_RELEASE)/src/Moves/Pawn_Double_Move.o: src/Moves/Pawn_Double_Move.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Pawn_Double_Move.cpp -o $(OBJDIR_RELEASE)/src/Moves/Pawn_Double_Move.o

$(OBJDIR_RELEASE)/src/Moves/Pawn_Capture.o: src/Moves/Pawn_Capture.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Pawn_Capture.cpp -o $(OBJDIR_RELEASE)/src/Moves/Pawn_Capture.o

$(OBJDIR_RELEASE)/src/Moves/Move.o: src/Moves/Move.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Move.cpp -o $(OBJDIR_RELEASE)/src/Moves/Move.o

$(OBJDIR_RELEASE)/src/Moves/Kingside_Castle.o: src/Moves/Kingside_Castle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/Kingside_Castle.cpp -o $(OBJDIR_RELEASE)/src/Moves/Kingside_Castle.o

$(OBJDIR_RELEASE)/src/Moves/En_Passant.o: src/Moves/En_Passant.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Moves/En_Passant.cpp -o $(OBJDIR_RELEASE)/src/Moves/En_Passant.o

$(OBJDIR_RELEASE)/src/Genes/Total_Force_Gene.o: src/Genes/Total_Force_Gene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Genes/Total_Force_Gene.cpp -o $(OBJDIR_RELEASE)/src/Genes/Total_Force_Gene.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src/Game
	rm -rf $(OBJDIR_RELEASE)/src/Genes
	rm -rf $(OBJDIR_RELEASE)/src/Exceptions
	rm -rf $(OBJDIR_RELEASE)/src/Pieces
	rm -rf $(OBJDIR_RELEASE)/src
	rm -rf $(OBJDIR_RELEASE)/src/Players
	rm -rf $(OBJDIR_RELEASE)
	rm -rf $(OBJDIR_RELEASE)/src/Moves

virtual_all: debug release

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release
