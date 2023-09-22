#include "queue.h"

#include <stdlib.h>

Queue *new_queue(unsigned int max_size)
{
    Queue *q = malloc(sizeof(struct Queue));
    if (q == NULL)
        return NULL;

    q->array = malloc(sizeof(int) * max_size);
    if (q->array == NULL)
    {
        free(q);
        return NULL;
    }

    q->max_size = max_size;
    q->size = 0;
    q->head = 0;
    q->tail = 0;

    return q;
}

void delete_queue(Queue *q)
{
    free(q);
}
