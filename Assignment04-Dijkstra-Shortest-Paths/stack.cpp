// Dhanashree Somani
// ASU ID: 1239782599
#include "stack.h"
#include <cstdlib>

pSTACK CreateStack(int capacity) {
    pSTACK pStack = (pSTACK)calloc(1, sizeof(STACK));
    pStack->capacity = capacity;
    pStack->top = 0;
    pStack->S = (pELEMENT*)calloc(capacity + 1, sizeof(pELEMENT));
    return pStack;
}

void DestroyStack(pSTACK pStack) {
    if (pStack) {
        free(pStack->S);
        free(pStack);
    }
}

void Push(pSTACK pStack, pELEMENT elem) {
    pStack->S[++pStack->top] = elem;
}

pELEMENT Pop(pSTACK pStack) {
    if (pStack->top == 0) return NULL;
    return pStack->S[pStack->top--];
}

int IsEmpty(pSTACK pStack) {
    return pStack->top == 0;
}
