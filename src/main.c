#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "utils.h"

int main()
{
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);

    // tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // system("clear");
    printf("\e[2J");
    for (int i = 0; i < 10; i++)
    {
        gotoXY(20+i, 10);
        printf("#\n");
        usleep(200000);
    }

    return 0;
}
