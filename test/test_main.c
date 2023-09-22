#include <assert.h>
#include <stdlib.h>

#include "../src/queue.h"

void test_create_queue()
{
    // Given
    int output = 1;

    // When
    Queue *q = new_queue(10);

    // Then
    assert(q != NULL);

    delete_queue(q);
}

int main(void)
{
    test_create_queue();
    return 0;
}
