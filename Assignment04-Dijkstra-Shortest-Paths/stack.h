// Dhanashree Somani
// ASU ID: 1239782599
#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

pSTACK CreateStack(int capacity);
void   DestroyStack(pSTACK pStack);
void   Push(pSTACK pStack, pELEMENT elem);
pELEMENT Pop(pSTACK pStack);
int    IsEmpty(pSTACK pStack);

#endif
