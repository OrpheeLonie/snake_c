#ifndef SNAKE_H
#define SNAKE_H

#include "queue.h"

typedef struct Snake
{
    Queue *q_x;
    Queue *q_y;
    int next_x;
    int next_y;
} Snake;

Snake *snake_new(unsigned int max_size);
void snake_delete(Snake *s);

#endif // SNAKE_H
