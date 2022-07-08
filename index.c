#include<stdio.h>
#define SIZE 3

void show_grid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%-3c", grid[i][j]);
        putchar('\n');
    }
}
void update_grid(char grid[SIZE][SIZE], int pos_x, int pos_y, char val) {
    grid[pos_x][pos_y] = val;
}

int main()
{
    int x, y;
    char c;
    char grid[SIZE][SIZE] = {
                        {'X', 'X', 'O'},
                        {'X', 'X', 'O'},
                        {'O', 'O', 'X'} };

    // testing update_grid function;
    show_grid(grid);
    puts("Enter value and position to change in val, pos_x, pos_y format:");
    scanf("%c%d%d", &c, &x, &y);
    update_grid(grid, x, y, c);
    putchar('\n');
    show_grid(grid);

    return 0;
}
