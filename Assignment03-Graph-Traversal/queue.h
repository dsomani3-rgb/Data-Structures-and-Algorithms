// Name: Dhanashree Somani
// ASU ID: 1239782599

#ifndef QUEUE_H
#define QUEUE_H

#include "data_structures.h"

typedef struct TAG_QNODE {
    int vertex;
    TAG_QNODE *next;
} QNODE;

typedef struct {
    QNODE *head;
    QNODE *tail;
} QUEUE;

QUEUE* initQueue();
void enqueue(QUEUE *q, int vertex);
int dequeue(QUEUE *q);
int isQueueEmpty(QUEUE *q);
void freeQueue(QUEUE *q);

#endif
