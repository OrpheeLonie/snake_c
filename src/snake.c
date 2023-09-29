#include "snake.h"

#include <stdlib.h>

Snake *snake_new(unsigned int max_size)
{
    Snake *s = malloc(sizeof(Snake));
    s->q_x = queue_new(max_size);
    s->q_y = queue_new(max_size);

    return s;
}

void snake_delete(Snake *s)
{
    queue_delete(s->q_x);
    queue_delete(s->q_y);
    free(s);
}
