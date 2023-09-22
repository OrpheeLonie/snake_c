#ifndef QUEUE_H
#define QUEUE_H

struct Queue
{
    unsigned int max_size;
    unsigned int size;
    int *array;
    unsigned int head;
    unsigned int tail;
};

#endif // QUEUE_H
