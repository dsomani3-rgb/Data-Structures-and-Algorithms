// Name: Dhanashree Somani
// ASU ID: 1239782599

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef enum { WHITE, GRAY, BLACK } COLOR;

typedef struct TAG_VERTEX {
    int index;
    COLOR BFS_color, DFS_color;
    int BFS_pred, BFS_d;
    int DFS_pred, DFS_d, DFS_f;
} VERTEX;

typedef VERTEX *pVERTEX;

typedef struct TAG_NODE {
    int index;
    int u;
    int v;
    double w;
    TAG_NODE *next;
} NODE;

typedef NODE *pNODE;

#endif
