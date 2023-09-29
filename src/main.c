#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "queue.h"
#include "snake.h"
#include "utils.h"

#define SPEED 50000
#define BOARD_SIDE 30
#define APPLE_SYMBOL "@"
#define SNAKE_SYMBOL "#"
#define BOARD_SYMBOL "*"

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
    printf(APPLE_SYMBOL);
}

void draw_board()
{
    for (int i = 0; i <= BOARD_SIDE; i++)
    {
        gotoXY(i, 0);
        printf(BOARD_SYMBOL);
        gotoXY(i, BOARD_SIDE);
        printf(BOARD_SYMBOL);
    }

    for (int i = 1; i <= BOARD_SIDE - 1; i++)
    {
        gotoXY(0, i);
        printf(BOARD_SYMBOL);
        gotoXY(BOARD_SIDE, i);
        printf(BOARD_SYMBOL);
    }
}

int is_outside(int x, int y)
{
    return x == 0 || y == 0 || x == BOARD_SIDE || y == BOARD_SIDE;
}

int main()
{
    set_terminal_flags();
    hide_cursor();
    clear_screen();

    srand(time(NULL));

    draw_board();
    int apple_x, apple_y;
    Snake *s = snake_new(100, 10, 10);
    for (int i = 0; i < 5; i++)
    {
        snake_step_on_apple(s);
        gotoXY(s->pos_x, s->pos_y);
        printf(SNAKE_SYMBOL);
    }
    new_apple(&apple_x, &apple_y);
    fflush(stdout);
    usleep(SPEED);

    char c;
    int x, y;
    while ((c = read_char()) != 'q' && !is_outside(s->pos_x, s->pos_y))
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
        printf(APPLE_SYMBOL);
        gotoXY(s->pos_x, s->pos_y);
        printf(SNAKE_SYMBOL);

        fflush(stdout);
        usleep(SPEED);
    }

    gotoXY(0, BOARD_SIDE + 2);
    printf("You died");

    printf("\e[?25h\n");
    snake_delete(s);

    return 0;
}
