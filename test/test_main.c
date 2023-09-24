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

void test_multiple_push_queue()
{
    // Given
    Queue *q = queue_new(10);
    int expected_output[11] = {0};
    expected_output[10] = 1;

    // When
    int output[11];
    for (int i = 0; i < 11; i++)
    {
        output[i] = queue_push(q, i);
    }

    // Then
    assert(q->size == 10);
    assert(q->head == 0);
    assert(q->tail == 0);
    for (int i = 0; i < 11; i++)
        assert(expected_output[i] == output[i]);
    for (int i = 0; i < 10; i++)
        assert(q->array[i] == i);
}

int main(void)
{
    test_create_queue();
    test_push_queue();
    return 0;
}
