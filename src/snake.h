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

#endif // SNAKE_H
