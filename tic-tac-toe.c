// This program is a simple tic-tac-toe game that can be played by two players written in C.
#include <stdio.h>
#include <assert.h>
#include "play_game.h"

// board(table, dim) creates a board of dimension dim x dim.
// requires: dim <= 5
//           table is a valid pointer
// effects: produces output
void print_board(char table[], int dim) {
    assert(dim <= 5);
    assert(table);
    for (int i = 0; i < (2 * dim + 1); i++) {
        for (int j = 0; j < (2 * dim + 1); j++) {
            if (i % 2 == 0) {
                printf("-");
            } else {
                if (j % 2 == 0) {
                    printf("|");                
                } else {
                    printf("%c", *(table));
                    ++table;
                }
            }
        }
        printf("\n");
    }
}


int main(void) {
    int dim = 0;
    printf("What is the dimension of the board? (max 5) ");
    scanf("%d", &dim);
    char table[dim * dim];
    for (int i = 0; i < dim * dim; i++) {
        table[i] = ' ';
    }
    print_board(table, dim);
    game(table, 'O', 'X', dim * dim, dim);
}