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

/*
 * Make the snake step forward without poping from th queues
 * *s: the snake
 */
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

/*
 * Make the snake go forward and return the position of the tail
 * *s: the snake
 * *x: the position where the tail was
 * *y: the position where the tail was
 */
void snake_step(Snake *s, int *x, int *y)
{
    snake_step_on_apple(s);
    *x = queue_pop(s->q_x);
    *y = queue_pop(s->q_y);
}
