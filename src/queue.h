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

Queue *queue_new(unsigned int max_size);
void queue_delete(Queue *q);
int queue_push(Queue *q, int val);
int queue_pop(Queue *q);

#endif // QUEUE_H
