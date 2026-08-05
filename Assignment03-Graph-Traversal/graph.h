// Name: Dhanashree Somani
// ASU ID: 1239782599

#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"
#include "queue.h"

typedef struct {
    int n;          
    int m;          
    pVERTEX *V;     
    pNODE *ADJ;     
    int isDirected; 
    int flag;       
} GRAPH;

GRAPH* createGraph(int n, int m, int isDirected, int flag);
void insertEdge(GRAPH *G, int idx, int u, int v, double w);
void freeGraph(GRAPH *G);

void adjPrintAll(GRAPH *G);
void adjPrintOne(GRAPH *G, int vertex);

void BFS(GRAPH *G, QUEUE *Q, int source);
void DFS(GRAPH *G);

void bfsPrintAll(GRAPH *G);
void bfsPrintOne(GRAPH *G, int vertex);
void dfsPrintAll(GRAPH *G);
void dfsPrintOne(GRAPH *G, int vertex);

#endif
