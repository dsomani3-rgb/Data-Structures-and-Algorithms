// Dhanashree Somani
// ASU ID: 1239782599
#include "heap.h"
#include <cstdlib>

pHEAP CreateHeap(int capacity) {
    pHEAP pHeap = (pHEAP)calloc(1, sizeof(HEAP));
    pHeap->capacity = capacity;
    pHeap->size = 0;
    pHeap->H = (pELEMENT*)calloc(capacity + 1, sizeof(pELEMENT));
    return pHeap;
}

void DestroyHeap(pHEAP pHeap) {
    if (pHeap) {
        free(pHeap->H);
        free(pHeap);
    }
}

static void Swap(pHEAP pHeap, int i, int j) {
    pELEMENT tmp = pHeap->H[i];
    pHeap->H[i] = pHeap->H[j];
    pHeap->H[j] = tmp;
    pHeap->H[i]->position = i;
    pHeap->H[j]->position = j;
}

void Heapify(pHEAP pHeap, int i) {
    int left  = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;
    if (left  <= pHeap->size && pHeap->H[left]->key  < pHeap->H[smallest]->key) smallest = left;
    if (right <= pHeap->size && pHeap->H[right]->key < pHeap->H[smallest]->key) smallest = right;
    if (smallest != i) {
        Swap(pHeap, i, smallest);
        Heapify(pHeap, smallest);
    }
}

void Insert(pHEAP pHeap, pELEMENT elem) {
    pHeap->size++;
    int i = pHeap->size;
    pHeap->H[i] = elem;
    elem->position = i;
    while (i > 1 && pHeap->H[i]->key < pHeap->H[i/2]->key) {
        Swap(pHeap, i, i/2);
        i = i/2;
    }
}

pELEMENT ExtractMin(pHEAP pHeap) {
    if (pHeap->size == 0) return NULL;
    pELEMENT min = pHeap->H[1];
    pHeap->H[1] = pHeap->H[pHeap->size];
    pHeap->H[1]->position = 1;
    pHeap->size--;
    min->position = 0;
    if (pHeap->size > 0)
        Heapify(pHeap, 1);
    return min;
}

void DecreaseKey(pHEAP pHeap, int pos, double newKey) {
    pHeap->H[pos]->key = newKey;
    int i = pos;
    while (i > 1 && pHeap->H[i]->key < pHeap->H[i/2]->key) {
        Swap(pHeap, i, i/2);
        i = i/2;
    }
}
