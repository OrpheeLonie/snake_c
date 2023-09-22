#include <assert.h>
#include <stdlib.h>

#include "../src/queue.h"

void test_create_queue()
{
    // Given
    int max_size = 10;

    // When
    Queue *q = new_queue(max_size);

    // Then
    assert(q != NULL);
    assert(q->array != NULL);
    assert(q->max_size == max_size);
    assert(q->size == 0);
    assert(q->head == 0);
    assert(q->tail == 0);

    delete_queue(q);
}

int main(void)
{
    test_create_queue();
    return 0;
}
