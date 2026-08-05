
// Name: Dhanashree Somani
// ASU ID: 1239782599

#include <stdlib.h>
#include "queue.h"

QUEUE* initQueue() {
    QUEUE *q = (QUEUE*) malloc(sizeof(QUEUE));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(QUEUE *q, int vertex) {
    QNODE *node = (QNODE*) malloc(sizeof(QNODE));
    node->vertex = vertex;
    node->next = NULL;
    if (q->tail == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
}

int dequeue(QUEUE *q) {
    if (q->head == NULL) return -1;
    QNODE *temp = q->head;
    int v = temp->vertex;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;
    free(temp);
    return v;
}

int isQueueEmpty(QUEUE *q) {
    return (q->head == NULL);
}

void freeQueue(QUEUE *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}
