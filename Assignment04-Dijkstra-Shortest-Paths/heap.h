// Dhanashree Somani
// ASU ID: 1239782599
#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

pHEAP CreateHeap(int capacity);
void  DestroyHeap(pHEAP pHeap);
void  Insert(pHEAP pHeap, pELEMENT elem);
pELEMENT ExtractMin(pHEAP pHeap);
void  DecreaseKey(pHEAP pHeap, int pos, double newKey);
void  Heapify(pHEAP pHeap, int i);

#endif
