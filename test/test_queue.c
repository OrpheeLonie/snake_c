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

    queue_delete(q);
}

void test_pop_queue()
{
    // Given
    Queue *q1 = queue_new(10);
    Queue *q2 = queue_new(10);
    int input[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // When
    int output1[10];
    int output2[10];
    for (int i = 0; i < 10; i++)
    {
        queue_push(q1, input[i]);
        output1[i] = queue_pop(q1);

        queue_push(q2, input[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        output2[i] = queue_pop(q2);
    }

    // Then
    for (int i = 0; i < 10; i++)
    {
        assert(input[i] == output1[i]);
        assert(input[i] == output2[i]);
    }
    assert(q1->size == 0);
    assert(q1->head == 0);
    assert(q1->tail == 0);
    assert(q2->size == 0);
    assert(q2->head == 0);
    assert(q2->tail == 0);

    queue_delete(q1);
    queue_delete(q2);
}

void test_peak_queue()
{
    // Given
    Queue *q = queue_new(10);
    int input[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++)
        queue_push(q, input[i]);

    // When
    int output[10];
    for (int i = 0; i < 10; i++)
    {
        output[i] = queue_peak(q);
        queue_pop(q);
    }

    // Then
    for (int i = 0; i < 10; i++)
    {
        assert(input[i] == output[i]);
    }
    assert(q->size == 0);
    assert(q->head == 0);
    assert(q->tail == 0);

    queue_delete(q);
}

int main(void)
{
    test_create_queue();
    test_push_queue();
    test_multiple_push_queue();
    test_pop_queue();
    test_peak_queue();
    return 0;
}
