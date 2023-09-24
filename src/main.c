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
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // fcntl(STDIN_FILENO, O_NONBLOCK);

    // system("clear");
    printf("\e[2J");
    for (int i = 0; i < 10; i++)
    {
        gotoXY(20+i, 10);
        printf("#\n");
        usleep(200000);
        char c = getc(stdin);
        if (c != EOF)
        {
            gotoXY(i, 0);
            printf("%c\n", c);
        }
    }

    return 0;
}
