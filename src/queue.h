#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue
{
    unsigned int max_size;
    unsigned int size;
    int *array;
    unsigned int head;
    unsigned int tail;
} Queue;

Queue *new_queue(unsigned int max_size);
void delete_queue(Queue *q);

#endif // QUEUE_H
