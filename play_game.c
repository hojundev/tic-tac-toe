#include "play_game.h"

void place_symbol(char *board, int row, int col, char sym, int dim) {
    assert(board);
    assert(row >= 0);
    assert(col >= 0);
    *(board + dim * (row - 1) + (col - 1)) = sym;
}

bool valid_coord(char *board, int row, int col, int dim) {
    assert(board);
    if (row <= 0 || row > dim) {
        printf("Invalid row. Please enter a row between 1 and %d.\n", dim);
        return false;
    } else if (col <= 0 || col > dim) {
        printf("Invalid column. Please enter a column between 1 and %d.\n", dim);
        return false;
    } else if (*(board + dim * (row - 1) + (col - 1)) != ' ') {
        printf("Invalid move. Please enter a row and column that is not taken.\n");
        return false;
    } else {
        return true;
    }
}

void game(char *board,char player1, char player2, int plays, int dim) {
    assert(board);
    assert(player1 != player2);
    assert((player1 >= '0' && player1 <= '9') || (player1 >= 'A' && player1 <= 'Z')
    || (player1 >= 'a' && player1 <= 'z'));
    assert((player2 >= '0' && player2 <= '9') || (player2 >= 'A' && player2 <= 'Z')
    || (player2 >= 'a' && player2 <= 'z'));
    assert(plays >= 0);
    assert(dim > 0);
    int row = 0;
    int col = 0;
    while(plays > 0) {
        if (plays % 2 == 1) {
            printf("Player 1, please enter the row and column of your move (row, column): ");
            scanf("%d, %d", &row, &col);
            while (!valid_coord(board, row, col, dim)) {
                printf("Player 1, please enter the row and column of your move ");
                printf("(row, column): ");
                scanf("%d, %d", &row, &col);
            }
            place_symbol(board, row, col, player1, dim);
            plays--;
        } else {
            printf("Player 2, please enter the row and column of your move (row, column): ");
            scanf("%d, %d", &row, &col);
            while (!valid_coord(board, row, col, dim)) {
                printf("Player 2, please enter the row and column of your move ");
                printf("(row, column): ");
                scanf("%d, %d", &row, &col);
            }
            place_symbol(board, row, col, player2, dim);
            plays--;
        }
    }
}