#include <assert.h>
#include <stdlib.h>

#include "../src/snake.h"

void test_create_snake()
{
    // Given
    unsigned int max_size = 10;

    // When
    Snake *s = snake_new(max_size);

    // Then
    assert(s != NULL);
    assert(s->q_x != NULL);
    assert(s->q_y != NULL);
    assert(s->dir == RIGHT);

    snake_delete(s);
}

int main(void)
{
    test_create_snake();

    return 0;
}
