// Name: Dhanashree Somani
// ASU ID: 1239782599

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define INFINITY_VAL -1  
GRAPH* createGraph(int n, int m, int isDirected, int flag) {
    GRAPH *G = (GRAPH*) malloc(sizeof(GRAPH));
    G->n = n;
    G->m = m;
    G->isDirected = isDirected;
    G->flag = flag;

    G->V = (pVERTEX*) calloc(n + 1, sizeof(pVERTEX));
    G->ADJ = (pNODE*) calloc(n + 1, sizeof(pNODE));

    for (int i = 1; i <= n; i++) {
        G->V[i] = (VERTEX*) calloc(1, sizeof(VERTEX));
        G->V[i]->index = i;
        G->V[i]->BFS_color = WHITE;
        G->V[i]->DFS_color = WHITE;
        G->V[i]->BFS_pred = 0;
        G->V[i]->BFS_d = INFINITY_VAL;
        G->V[i]->DFS_pred = 0;
        G->V[i]->DFS_d = 0;
        G->V[i]->DFS_f = 0;
        G->ADJ[i] = NULL;
    }
    return G;
}

static void insertNode(GRAPH *G, int idx, int u, int v, double w) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));
    newNode->index = idx;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;

    int flag = G->flag;

    if (flag == 0) {
        newNode->next = G->ADJ[u];
        G->ADJ[u] = newNode;
    } else if (flag == 1) {
        if (G->ADJ[u] == NULL) {
            G->ADJ[u] = newNode;
        } else {
            NODE *cur = G->ADJ[u];
            while (cur->next != NULL) cur = cur->next;
            cur->next = newNode;
        }
    } else {
        NODE *prev = NULL;
        NODE *cur = G->ADJ[u];
        while (cur != NULL && cur->v < v) {
            prev = cur;
            cur = cur->next;
        }
        newNode->next = cur;
        if (prev == NULL)
            G->ADJ[u] = newNode;
        else
            prev->next = newNode;
    }
}

void insertEdge(GRAPH *G, int idx, int u, int v, double w) {
    insertNode(G, idx, u, v, w);
    if (!G->isDirected) {
        insertNode(G, idx, v, u, w);
    }
}

void freeGraph(GRAPH *G) {
    for (int i = 1; i <= G->n; i++) {
        // Free adjacency list
        NODE *cur = G->ADJ[i];
        while (cur != NULL) {
            NODE *tmp = cur->next;
            free(cur);
            cur = tmp;
        }
        free(G->V[i]);
    }
    free(G->V);
    free(G->ADJ);
    free(G);
}

void adjPrintAll(GRAPH *G) {
    for (int i = 1; i <= G->n; i++) {
        adjPrintOne(G, i);
    }
}

void adjPrintOne(GRAPH *G, int vertex) {
    printf("ADJ[%d]:", vertex);
    NODE *cur = G->ADJ[vertex];
    while (cur != NULL) {
        printf("-->[%d %d: %4.2lf]", cur->u, cur->v, cur->w);
        cur = cur->next;
    }
    printf("\n");
}

void BFS(GRAPH *G, QUEUE *Q, int source) {
    for (int i = 1; i <= G->n; i++) {
        G->V[i]->BFS_color = WHITE;
        G->V[i]->BFS_d = INFINITY_VAL;
        G->V[i]->BFS_pred = 0;
    }

    G->V[source]->BFS_color = GRAY;
    G->V[source]->BFS_d = 0;
    G->V[source]->BFS_pred = 0;

    while (!isQueueEmpty(Q)) dequeue(Q);

    enqueue(Q, source);

    while (!isQueueEmpty(Q)) {
        int u = dequeue(Q);
        NODE *cur = G->ADJ[u];
        while (cur != NULL) {
            int v = cur->v;
            if (G->V[v]->BFS_color == WHITE) {
                G->V[v]->BFS_color = GRAY;
                G->V[v]->BFS_d = G->V[u]->BFS_d + 1;
                G->V[v]->BFS_pred = u;
                enqueue(Q, v);
            }
            cur = cur->next;
        }
        G->V[u]->BFS_color = BLACK;
    }
}

static int dfsTime;

static void DFS_Visit(GRAPH *G, int u) {
    dfsTime++;
    G->V[u]->DFS_d = dfsTime;
    G->V[u]->DFS_color = GRAY;

    NODE *cur = G->ADJ[u];
    while (cur != NULL) {
        int v = cur->v;
        if (G->V[v]->DFS_color == WHITE) {
            G->V[v]->DFS_pred = u;
            DFS_Visit(G, v);
        }
        cur = cur->next;
    }

    G->V[u]->DFS_color = BLACK;
    dfsTime++;
    G->V[u]->DFS_f = dfsTime;
}

void DFS(GRAPH *G) {
    for (int i = 1; i <= G->n; i++) {
        G->V[i]->DFS_color = WHITE;
        G->V[i]->DFS_pred = 0;
        G->V[i]->DFS_d = 0;
        G->V[i]->DFS_f = 0;
    }
    dfsTime = 0;
    for (int i = 1; i <= G->n; i++) {
        if (G->V[i]->DFS_color == WHITE) {
            DFS_Visit(G, i);
        }
    }
}

void bfsPrintOne(GRAPH *G, int vertex) {
    printf("Vertex %d:\n", vertex);
    if (G->V[vertex]->BFS_d == INFINITY_VAL)
        printf("BFS_d = INFINITY\n");
    else
        printf("BFS_d = %d\n", G->V[vertex]->BFS_d);
    if (G->V[vertex]->BFS_pred == 0)
        printf("BFS_pred = NULL\n");
    else
        printf("BFS_pred = %d\n", G->V[vertex]->BFS_pred);
    if (G->V[vertex]->BFS_color == WHITE)
        printf("BFS_color = WHITE\n");
    else if (G->V[vertex]->BFS_color == GRAY)
        printf("BFS_color = GRAY\n");
    else
        printf("BFS_color = BLACK\n");
    printf("\n");
}

void bfsPrintAll(GRAPH *G) {
    for (int i = 1; i <= G->n; i++) {
        bfsPrintOne(G, i);
    }
}

void dfsPrintOne(GRAPH *G, int vertex) {
    printf("Vertex %d:\n", vertex);
    printf("DFS_d = %d\n", G->V[vertex]->DFS_d);
    printf("DFS_f = %d\n", G->V[vertex]->DFS_f);
    if (G->V[vertex]->DFS_pred == 0)
        printf("DFS_pred = NULL\n");
    else
        printf("DFS_pred = %d\n", G->V[vertex]->DFS_pred);
    if (G->V[vertex]->DFS_color == WHITE)
        printf("DFS_color = WHITE\n");
    else if (G->V[vertex]->DFS_color == GRAY)
        printf("DFS_color = GRAY\n");
    else
        printf("DFS_color = BLACK\n");
    printf("\n");
}

void dfsPrintAll(GRAPH *G) {
    for (int i = 1; i <= G->n; i++) {
        dfsPrintOne(G, i);
    }
}
