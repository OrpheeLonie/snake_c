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
    int val = 42;

    // When
    queue_push(q, val);

    // Then
    assert(q->size == 1);
    assert(q->head == 1);
    assert(q->tail == 0);
    assert(q->array[0] == val);

    queue_delete(q);
}

int main(void)
{
    test_create_queue();
    test_push_queue();
    return 0;
}
