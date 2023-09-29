#include "snake.h"

#include <stdlib.h>

Snake *snake_new(unsigned int max_size, int x, int y)
{
    Snake *s = malloc(sizeof(Snake));
    s->q_x = queue_new(max_size);
    s->q_y = queue_new(max_size);
    s->dir = RIGHT;
    s->pos_x = x;
    s->pos_y = y;

    return s;
}

void snake_delete(Snake *s)
{
    queue_delete(s->q_x);
    queue_delete(s->q_y);
    free(s);
}

void snake_step_on_apple(Snake *s)
{
    switch(s->dir)
    {
        case UP:
            s->pos_y--;
            break;
        case DOWN:
            s->pos_y++;
            break;
        case LEFT:
            s->pos_x--;
            break;
        case RIGHT:
            s->pos_x++;
            break;
    }

    queue_push(s->q_x, s->pos_x);
    queue_push(s->q_y, s->pos_y);
}
