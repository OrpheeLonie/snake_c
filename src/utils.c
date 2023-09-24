#include <stdio.h>

void gotoXY(int x, int y)
{
    printf("\e[%d;%dH", y, x);
}

void clear_screen()
{
    printf("\e[2J");
}
