#include "stdio.h"

int main()
{
    int pos_x, pos_y;

    scanf("%d%d", &pos_x, &pos_y);
    while ((pos_x < 0 || pos_x > 2)
            || (pos_y < 0 || pos_y > 2))
        scanf("%d%d", &pos_x, &pos_y);


    printf("pos_x = %d, pos_y = %d", pos_x, pos_y);
}
