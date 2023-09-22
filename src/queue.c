#include "queue.h"

#include <stdlib.h>

Queue *queue_new(unsigned int max_size)
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

void queue_delete(Queue *q)
{
    free(q->array);
    free(q);
}

int queue_push(Queue *q, int val)
{
    if (q->size >= q->max_size)
        return 1;

    q->array[q->head] = val;
    q->head = (q->head+1) % q->max_size;
    q->size++;

    return 0;
}
