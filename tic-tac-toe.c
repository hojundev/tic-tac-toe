// This program is a simple tic-tac-toe game that can be played by two players written in C.
#include <stdio.h>

void board(char table[], int dim) {
    assert(dim <= 5);
    for (int i = 0; i < (2 * dim + 1); i++) {
        for (int j = 0; j < (2 * dim + 1); j++) {
            if (i % 2 == 0) {
                *(table + j) = '-';
            } else {
                if (j % 2 == 0) {
                    *(table + j) = '|';                
                } else {
                    *(table + j) = ' ';
                }
            }
        }
        table += (2 * dim + 1);
    }
}


int main(void) {
    int dim = 0;
    printf("What is the dimension of the board? (max 5) ");
    scanf("%d", &dim);
    char table[4 * dim * dim + 4 * dim + 1];
    board(table, dim);
    for (int i = 0; i < (2 * dim + 1); i++) {
        for (int j = 0; j < (2 * dim + 1); j++) {
            printf("%c", table[i * (2 * dim + 1) + j]);
        }
        printf("\n");
    }
    return 0;
}