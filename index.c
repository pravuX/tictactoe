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
// void show_format(int i, int j)
// {
//     int a[3][3];
//     for(i=0;i<3;i++)
//     {
//         for(j=0;j<3;j++)
//         {
//             scanf("%d", &a[i][j]);
//             printf("%d", a[i][j]);
//         }

//     }
// }
// I wanted to show format but it didn't work.
int main()
{
    int pos_x, pos_y;
    char c;
    char quit = 'n';
    int turn = 0; // 0 for X, 1 for O
    int no_moves = 0;
    int win;
     // format like this::
      printf("00 01 02\n\n");
    printf("10 11 12\n\n");
    printf("20 21 22\n\n");  
    char current_val = '\0';
    char grid[SIZE][SIZE];
    reset_grid(grid);

    while (1 && no_moves < 9) {
        if (turn == 0) {
            turn = 1; // switch turn to O
            current_val = 'X';
        } else {
            turn = 0; // switch turn to X
            current_val = 'O';
        }
        printf("It's %c's turn\n", current_val);
        printf("Enter position to put %c.\n", current_val);
        scanf("%d%d", &pos_x, &pos_y);
        while ((pos_x < 0 || pos_x > 2)
                || (pos_y < 0 || pos_y > 2))
            scanf("%d%d", &pos_x, &pos_y);
        update_grid(grid, pos_x, pos_y, current_val);
        no_moves++;
        if ((win = check_win(grid, current_val))) {
            printf("%c wins\n", current_val);
            break;
        }
        show_grid(grid);
    }
    show_grid(grid);

    return 0;
}
