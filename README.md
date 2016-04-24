# Genetic Chess
An amateur attempt at breeding a chess-playing AI.



## Genes currently active in Genetic AI instances


### Board Evaluation Genes

#### Freedom To Move Gene
Counts the number of legal moves available in the current position.

#### King Confinement Gene
Counts the king's legal moves.

#### Opponent Pieces Targeted Gene
Totals the total strength (as determined by the Piece Strength Gene below) of
the opponent's pieces currently under attack.

#### Pawn Advancement Gene
Measures the progress of all pawns towards the opposite side of the board.

#### Sphere of Influence Gene
Counts the number of squares attacked by all pieces, weighted by the square's
proximity to the opponent's king.

#### Total Force Gene
Sums the strength of all the player's pieces on the board.



### Regulatory Genes

#### Branch Pruning Gene
Specifies when to cut off analyzing a line of moves based on whether the
current board evaluation is too low compared to the current board state.

#### Last Minute Panic Gene
If the time left in the game is less than the amount specified here, then
look-ahead on all lines is cut off.

#### Look Ahead Gene
Determines how many moves to look ahead based on the time left and how many move choices are available.

#### Piece Strength Gene
Specifies the importance or strength of each differet type of chess piece.
