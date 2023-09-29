#include "snake.h"

#include <stdlib.h>

Snake *snake_new(unsigned int max_size, int x, int y)
{
    Snake *s = malloc(sizeof(Snake));
    s->q_x = queue_new(max_size);
    s->q_y = queue_new(max_size);
    s->dir = RIGHT;
    s->next_x = x;
    s->next_y = y;

    return s;
}

void snake_delete(Snake *s)
{
    queue_delete(s->q_x);
    queue_delete(s->q_y);
    free(s);
}

static void update_next_position(Snake *s)
{
    switch(s->dir)
    {
        case UP:
            s->next_y--;
            break;
        case DOWN:
            s->next_y++;
            break;
        case LEFT:
            s->next_x--;
            break;
        case RIGHT:
            s->next_x++;
            break;
    }
}

void snake_step_on_apple(Snake *s)
{
    update_next_position(s);
    queue_push(s->q_x, s->next_x);
    queue_push(s->q_y, s->next_y);
}
