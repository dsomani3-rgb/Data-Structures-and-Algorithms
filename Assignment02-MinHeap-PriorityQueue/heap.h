// Dhanashree Somani
// ASU ID: 1239782599

#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

void InitHeap();
void BuildHeap();
void MinHeapify(int i);
void Insert(int index);
int ExtractMin(); 
void DecreaseKey(int index, double newKey);

void PrintHeap();
void PrintArray();

#endif 
