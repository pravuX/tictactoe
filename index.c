#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

// for a given grid, display it.
void show_grid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%-3c", grid[i][j]);
        putchar('\n');
    }
}

// called after each update_grid invocation, to check for possible win
int check_win(char grid[SIZE][SIZE], char val) {
    // Each move, do 3 vertical checks, 3 horizontal checks, and 2 diagonal checks
    // horizontal checks
    if (   val==grid[0][0] && grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2]
        || val==grid[1][0] && grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2]
        || val==grid[2][0] && grid[2][0]==grid[2][1] && grid[2][1]==grid[2][2])
        return 1;
    // vertical checks
    if (   val==grid[0][0] && grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0]
        || val==grid[0][1] && grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1]
        || val==grid[0][2] && grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2])
        return 1;
    // diagonal checks
    if (   val==grid[0][0] && grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]
        || val==grid[0][2] && grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
        return 1;
    return 0;
}

// for a given grid, position vand value, update the value at the position.
void update_grid(char grid[SIZE][SIZE], int pos_x, int pos_y, char val) {
    grid[pos_x][pos_y] = val;
}

// reset the grid to contain all blanks.
void reset_grid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = ' ';
        }
}

int main()
{
    int pos_x, pos_y;
    char c;
    char quit = 'n';
    int turn = 0; // 0 for X, 1 for O
    int no_moves = 0;
    int win;
    char grid[SIZE][SIZE];
    reset_grid(grid);

    show_grid(grid); // REMOVE later
    while (1 && no_moves < 9) {
        if (turn == 0) {
            turn = 1; // it's O's turn next.
            puts("\nIt's X's turn");
            puts("Enter position to put X");
            scanf("%d%d", &pos_x, &pos_y);
            update_grid(grid, pos_x, pos_y, 'X');
            no_moves++; // make sure the users can input only untill the grid is fully filled
            if ((win = check_win(grid, 'X'))) {
                puts("X wins\n");
                show_grid(grid);
                break;
            }
        } else {
            turn = 0; // it's X's turn next.
            puts("\nIt's O's turn");
            puts("Enter position to put O");
            scanf("%d%d", &pos_x, &pos_y);
            update_grid(grid, pos_x, pos_y, 'O');
            // check_win(grid, pos_x, pos_y, 'O');
            no_moves++;
            if ((win = check_win(grid, 'O'))) {
                puts("O wins\n");
                show_grid(grid);
                break;
            }
        }
        show_grid(grid);
    }

    return 0;
}
