// This program allows users to play the tic-tac-toe game.
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool bingo(char *board, int dim);

void place_symbol(char *board, int row, int col, char sym, int dim);

// valid_coord(board, row, col) checks if the coordinates row and col are valid.
// requires: board is a valid pointer
bool valid_coord(char *board, int row, int col, int dim);

// game(board, player1, player2, plays, dim) allows two players to play tic-tac-toe within
// plays number of moves.
// requires: plays must be equal to dimension of the board squared (not asserted)
//           player1 and player2 must be ASCII characters
//           player1 and player2 cannot have the same character
//           player1 and player2 must be alphabetic or numeric characters
//           board is a valid pointer
//           dim must be positive
// effects: reads input from user
//          produces output
//          may mutate the board
void game(char *board, char player1, char player2, int plays, int dim);