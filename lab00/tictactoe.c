//Laboratorio 0 Scavuzzo Ignacio

//Ejercicio 2

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)
char board[BOARD_SIZE][BOARD_SIZE] = {
{ '-', '-', '-' },
{ '-', '-', '-' },
{ '-', '-', '-' }
};

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE]) {
    bool estadodecelda;
    board = board;
    estadodecelda = false;
    

    
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            if (board[row][column] == '-') {
                estadodecelda = true;
            } 

        }
        
    }

    return estadodecelda;

}


char get_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    
    board = board;
    char winner = '-';
    int contadorX = 0;
    int contadorO = 0;

    //filacompleta
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
                if (board[row][column] == 'X') {
                    contadorX = contadorX + 1;
                }
                if (board[row][column] == 'O') {
                    contadorO = contadorO + 1;
                }
            
        }
            if (2 < contadorX) {
                winner = 'X';
            }
            if (2 < contadorO) {
                winner = 'O';
            }
            contadorX = 0;
            contadorO = 0;
    }
    
    board = board;
    //columna completa
    for (int column = 0; column < BOARD_SIZE; ++column) {
        
        for (int row = 0; row < BOARD_SIZE; ++row) {
                if (board[row][column] == 'X') {
                    contadorX = contadorX + 1;
                }
                if (board[row][column] == 'O') {
                    contadorO = contadorO + 1;
                }
            
        }
            if (2 < contadorX) {
                winner = 'X';
            }
            if (2 < contadorO) {
                winner = 'O';
            }
            contadorX = 0;
            contadorO = 0;
            
    }
    //diagonal completa
    board = board;
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
        winner = 'X';
    }
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
        winner = 'O';
    }
    return winner;
}


int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            //exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);

    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
