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
    int pos_x;
    int pos_y;
    enum direction dir;
} Snake;

Snake *snake_new(unsigned int max_size, int x, int y);
void snake_delete(Snake *s);
void snake_step_on_apple(Snake *s);

#endif // SNAKE_H
