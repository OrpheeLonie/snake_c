#include <assert.h>
#include <stdlib.h>

#include "../src/snake.h"

void test_create_snake()
{
    // Given
    unsigned int max_size = 10;
    int x = 10;
    int y = 10;

    // When
    Snake *s = snake_new(max_size, x, y);

    // Then
    assert(s != NULL);
    assert(s->q_x != NULL);
    assert(s->q_y != NULL);
    assert(s->dir == RIGHT);
    assert(s->pos_x == x);
    assert(s->pos_y == y);

    queue_push(s->q_x, 0);

    snake_delete(s);
}

void test_snake_step_on_apple()
{
    // Given
    int x = 10;
    int y = 10;
    Snake *s1 = snake_new(10, x, y);
    s1->dir = UP;
    Snake *s2 = snake_new(10, x, y);
    s2->dir = DOWN;
    Snake *s3 = snake_new(10, x, y);
    s3->dir = LEFT;
    Snake *s4 = snake_new(10, x, y);

    // When
    snake_step_on_apple(s1);
    snake_step_on_apple(s2);
    snake_step_on_apple(s3);
    snake_step_on_apple(s4);

    // Then
    assert(s1->pos_x == x);
    assert(s1->pos_y == y - 1);
    assert(s1->q_x->size == 1);
    assert(queue_peak(s1->q_x) == s1->pos_x);
    assert(s1->q_y->size == 1);
    assert(queue_peak(s1->q_y) == s1->pos_y);
    assert(s2->pos_y == y + 1);
    assert(s3->pos_x == x - 1);
    assert(s3->pos_y == y);
    assert(s4->pos_x == x + 1);
    assert(s4->pos_y == y);

    snake_delete(s1);
    snake_delete(s2);
    snake_delete(s3);
    snake_delete(s4);
}

void test_snake_step()
{
    // Given
    Snake *s = snake_new(10, 10, 10);
    snake_step_on_apple(s);
    snake_step_on_apple(s);
    enum direction dirs[5] = {UP, LEFT, DOWN, DOWN, DOWN};
    int expected_x[5] = {11, 12, 12, 11, 11};
    int expected_y[5] = {10, 10, 9, 9, 10};

    // When
    int output_x[5];
    int output_y[5];
    for (int i = 0; i < 5; i++)
    {
        s->dir = dirs[i];
        snake_step(s, output_x+i, output_y+i);
        assert(s->q_x->size == 2);
        assert(s->q_x->size == 2);
    }

    // Then
    for (int i = 0; i < 5; i++)
    {
        assert(expected_x[i] == output_x[i]);
        assert(expected_y[i] == output_y[i]);
    }

    snake_delete(s);
}

int main(void)
{
    test_create_snake();
    test_snake_step_on_apple();
    test_snake_step();

    return 0;
}
