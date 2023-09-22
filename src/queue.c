#include "queue.h"

#include <stdlib.h>

Queue *new_queue(unsigned int max_size)
{
    return malloc(sizeof(struct Queue));
}

void delete_queue(Queue *q)
{
    free(q);
}
