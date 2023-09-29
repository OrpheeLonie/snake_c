#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void gotoXY(int x, int y)
{
    printf("\e[%d;%dH", y, x);
}

void clear_screen()
{
    printf("\e[2J");
}

void hide_cursor()
{
    printf("\e[?25l");
}

void set_terminal_flags()
{
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
}
