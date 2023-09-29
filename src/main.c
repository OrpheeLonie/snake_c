#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "queue.h"
#include "snake.h"
#include "utils.h"

#define SPEED 50000

char read_char()
{
    char c = EOF, c_tmp;
    while ((c_tmp = getc(stdin)) != EOF)
        c = c_tmp;
    return c;
}

void new_apple(int *x, int *y)
{
    *x = rand() % 10;
    *y = rand() % 10;

    gotoXY(*x, *y);
    printf("@");
}

int main()
{
    set_terminal_flags();
    hide_cursor();
    clear_screen();

    srand(time(NULL));

    int apple_x, apple_y;
    Snake *s = snake_new(100, 10, 10);
    for (int i = 0; i < 5; i++)
    {
        snake_step_on_apple(s);
        gotoXY(s->pos_x, s->pos_y);
        printf("#");
    }
    new_apple(&apple_x, &apple_y);
    fflush(stdout);
    usleep(SPEED);

    char c;
    int x, y;
    while ((c = read_char()) != 'q')
    {
        if (c != EOF)
            snake_set_direction(s, c);

        if (s->pos_x == apple_x && s->pos_y == apple_y)
        {
            new_apple(&apple_x, &apple_y);
            snake_step_on_apple(s);
        }
        else
        {
            snake_step(s, &x, &y);
            gotoXY(x, y);
            printf(" ");
        }
        gotoXY(apple_x, apple_y);
        printf("@");
        gotoXY(s->pos_x, s->pos_y);
        printf("#");

        fflush(stdout);
        usleep(SPEED);
    }

    snake_delete(s);

    return 0;
}
