#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "queue.h"
#include "snake.h"

#define SPEED 50000

char read_char()
{
    char c = EOF, c_tmp;
    while ((c_tmp = getc(stdin)) != EOF)
        c = c_tmp;
    return c;
}

int main()
{
    set_terminal_flags();
    hide_cursor();
    clear_screen();

    Snake *s = snake_new(100, 10, 10);
    for (int i = 0; i < 5; i++)
    {
        snake_step_on_apple(s);
        gotoXY(s->pos_x, s->pos_y);
        printf("#");
    }
    fflush(stdout);
    usleep(SPEED);

    char c;
    int x, y;
    while ((c = read_char()) != 'q')
    {
        if (c != EOF)
            snake_set_direction(s, c);

        snake_step(s, &x, &y);
        gotoXY(s->pos_x, s->pos_y);
        printf("#");
        gotoXY(x, y);
        printf(" ");

        fflush(stdout);
        usleep(SPEED);
    }

    snake_delete(s);

    return 0;
}
