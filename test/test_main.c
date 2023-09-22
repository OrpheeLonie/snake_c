#include <assert.h>
#include <stdlib.h>

#include "../src/queue.h"

void test_create_queue()
{
    // Given
    unsigned int max_size = 10;

    // When
    Queue *q = queue_new(max_size);

    // Then
    assert(q != NULL);
    assert(q->array != NULL);
    assert(q->max_size == max_size);
    assert(q->size == 0);
    assert(q->head == 0);
    assert(q->tail == 0);

    queue_delete(q);
}

void test_push_queue()
{
    // Given
    Queue *q = queue_new(10);

    // When
    queue_push(q, 1);
    // Then
}

int main(void)
{
    test_create_queue();
    return 0;
}
