#ifndef SNAKE_H
#define SNAKE_H

#include "queue.h"

enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct Snake
{
    Queue *q_x;
    Queue *q_y;
    int next_x;
    int next_y;
    enum direction dir;
} Snake;

Snake *snake_new(unsigned int max_size);
void snake_delete(Snake *s);

#endif // SNAKE_H
