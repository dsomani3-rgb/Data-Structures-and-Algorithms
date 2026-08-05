// Dhanashree Somani
// ASU ID: 1239782599
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"
#include "heap.h"
#include "stack.h"

void PrintADJ(int n, pNODE* ADJ);
void DijkstraST(int n, pNODE* ADJ, pVERTEX* V, pHEAP pHeap, int s, int t);
void PrintPath(int n, pVERTEX* V, pSTACK pStack, int s, int t);
void PrintLength(pVERTEX* V, int s, int t);

#endif
