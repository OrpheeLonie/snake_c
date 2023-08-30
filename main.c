#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "src/utils.h"

int main()
{
    /*
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    */

    system("clear");
    gotoXY(7, 5);
    printf("abc");
    gotoXY(2, 8);
    printf("abc");
    // printf("%c[%d;%df", 0x1B, 4, 52);
    printf("def");

    return 0;
}
