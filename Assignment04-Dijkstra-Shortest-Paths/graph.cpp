// Dhanashree Somani
// ASU ID: 1239782599
#include "graph.h"
#include <cstdio>
#include <cfloat>

void PrintADJ(int n, pNODE* ADJ) {
    for (int i = 1; i <= n; i++) {
        printf("ADJ[%d]:", i);
        pNODE cur = ADJ[i];
        while (cur != NULL) {
            printf("-->[%d %d: %4.2lf]", cur->u, cur->v, cur->w);
            cur = cur->next;
        }
        printf("\n");
    }
}

void DijkstraST(int n, pNODE* ADJ, pVERTEX* V, pHEAP pHeap, int s, int t) {
    for (int i = 1; i <= n; i++) {
        V[i]->index    = i;
        V[i]->key      = DBL_MAX;
        V[i]->pi       = 0;
        V[i]->color    = WHITE;
        V[i]->position = 0;
    }
    pHeap->size = 0;

    V[s]->key   = 0.0;
    V[s]->color = GRAY;
    Insert(pHeap, V[s]);

    while (pHeap->size > 0) {
        pELEMENT u = ExtractMin(pHeap);
        int uid = u->index;

        if (uid == t) break; 

        pNODE cur = ADJ[uid];
        while (cur != NULL) {
            int vid = cur->v;
            double w = cur->w;
            if (V[vid]->color == WHITE) {
                V[vid]->color = GRAY;
                V[vid]->key   = V[uid]->key + w;
                V[vid]->pi    = uid;
                Insert(pHeap, V[vid]);
            } else if (V[vid]->color == GRAY) {
                double newKey = V[uid]->key + w;
                if (newKey < V[vid]->key) {
                    V[vid]->pi = uid;
                    DecreaseKey(pHeap, V[vid]->position, newKey);
                }
            }
            cur = cur->next;
        }
        V[uid]->color = BLACK;
    }
    while (pHeap->size > 0) {
        ExtractMin(pHeap);
    }
}

void PrintPath(int n, pVERTEX* V, pSTACK pStack, int s, int t) {
    if (V[t]->key == DBL_MAX) {
        printf("There is no path from %d to %d.\n", s, t);
        return;
    }
    pStack->top = 0;
    int cur = t;
    while (cur != 0) {
        Push(pStack, V[cur]);
        cur = V[cur]->pi;
    }
    printf("The shortest path from %d to %d is:\n", s, t);
    int first = 1;
    while (!IsEmpty(pStack)) {
        pELEMENT e = Pop(pStack);
        if (!first) printf("-->");
        printf("[%d:%8.2lf]", e->index, e->key);
        first = 0;
    }
    printf(".\n");
}

void PrintLength(pVERTEX* V, int s, int t) {
    if (V[t]->key == DBL_MAX) {
        printf("There is no path from %d to %d.\n", s, t);
    } else {
        printf("The length of the shortest path from %d to %d is:%9.2lf\n", s, t, V[t]->key);
    }
}
