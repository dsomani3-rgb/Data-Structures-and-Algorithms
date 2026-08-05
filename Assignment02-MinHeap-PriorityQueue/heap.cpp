#include <cstdio>
#include <cstdlib>
#include "heap.h"
#include "util.h"
#include "data_structures.h"

extern ELEMENT **V;
extern HEAP *pHeap;
extern int g_n;

static void swapHeapPositions(int aPos, int bPos) {
    int aIdx = pHeap->H[aPos];
    int bIdx = pHeap->H[bPos];
    pHeap->H[aPos] = bIdx;
    pHeap->H[bPos] = aIdx;
    V[aIdx]->pos = bPos;
    V[bIdx]->pos = aPos;
}

void InitHeap() {
    if (pHeap == nullptr) {
        pHeap = (HEAP*) malloc(sizeof(HEAP));
        pHeap->H = nullptr;
    } else {
        if (pHeap->H != nullptr) {
            free(pHeap->H);
            pHeap->H = nullptr;
        }
    }
    if (V == nullptr) {
        pHeap->capacity = 0;
        pHeap->H = nullptr;
    } else {
        pHeap->capacity = g_n;
        pHeap->H = (int*) malloc(sizeof(int) * (pHeap->capacity + 1));
    }
    pHeap->size = 0;
    if (V != nullptr) {
        for (int i = 1; i <= g_n; ++i) V[i]->pos = 0;
    }
}

void MinHeapify(int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int smallest = i;
    if (l <= pHeap->size) {
        double keyL = V[pHeap->H[l]]->key;
        double keyI = V[pHeap->H[smallest]]->key;
        if (keyL < keyI) smallest = l;
    }
    if (r <= pHeap->size) {
        double keyR = V[pHeap->H[r]]->key;
        double keySmall = V[pHeap->H[smallest]]->key;
        if (keyR < keySmall) smallest = r;
    }
    if (smallest != i) {
        swapHeapPositions(i, smallest);
        MinHeapify(smallest);
    }
}

void BuildHeap() {
    InitHeap();
    if (V == nullptr) return;
    pHeap->size = g_n;
    for (int i = 1; i <= g_n; ++i) {
        pHeap->H[i] = i;
        V[i]->pos = i;
    }
    for (int i = pHeap->size / 2; i >= 1; --i) MinHeapify(i);
}

void Insert(int index) {
    printf("Instruction: Insert %d\n", index);
    if (index < 1 || index > g_n) {
        fprintf(stderr, "Error: index out of bound\n");
        return;
    }
    if (V == nullptr) {
        fprintf(stderr, "Error: array is NULL\n");
        return;
    }
    if (V[index]->pos != 0) {
        fprintf(stderr, "Error: V[%d] already in the heap\n", index);
        return;
    }
    if (pHeap == nullptr) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    if (pHeap->size + 1 > pHeap->capacity) {
        fprintf(stderr, "Error: heap overflow\n");
        return;
    }
    pHeap->size = pHeap->size + 1;
    int i = pHeap->size;
    pHeap->H[i] = index;
    V[index]->pos = i;
    while (i > 1) {
        int parent = i / 2;
        if (V[pHeap->H[i]]->key < V[pHeap->H[parent]]->key) {
            swapHeapPositions(i, parent);
            i = parent;
        } else break;
    }
}

int ExtractMin() {
    printf("Instruction: ExtractMin\n");
    if (pHeap == nullptr) {
        fprintf(stderr, "Error: heap is NULL\n");
        return 0;
    }
    if (pHeap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return 0;
    }
    int minIdx = pHeap->H[1];
    int last = pHeap->H[pHeap->size];
    pHeap->H[1] = last;
    V[last]->pos = 1;
    V[minIdx]->pos = 0;
    pHeap->size = pHeap->size - 1;
    if (pHeap->size >= 1) MinHeapify(1);
    return minIdx;
}

void DecreaseKey(int index, double newKey) {
    printf("Instruction: DecreaseKey %d %lf\n", index, newKey);
    if (index < 1 || index > g_n) {
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }
    if (V[index]->pos == 0) {
        fprintf(stderr, "Error: V[%d] not in the heap\n", index);
        return;
    }
    if (!(newKey < V[index]->key)) {
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }
    V[index]->key = newKey;
    int i = V[index]->pos;
    while (i > 1) {
        int parent = i / 2;
        if (V[pHeap->H[i]]->key < V[pHeap->H[parent]]->key) {
            swapHeapPositions(i, parent);
            i = parent;
        } else break;
    }
}

void PrintHeap() {
    printf("Instruction: PrintHeap\n");
    if (pHeap == nullptr) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    printf("Capacity = %d, size = %d\n", pHeap->capacity, pHeap->size);
    for (int i = 1; i <= pHeap->size; ++i) {
        printf("H[%d] = %d\n", i, pHeap->H[i]);
    }
}

void PrintArray() {
    printf("Instruction: PrintArray\n");
    if (V == nullptr) {
        fprintf(stderr, "Error: array is NULL\n");
        return;
    }
    for (int i = 1; i <= g_n; ++i) {
        printf("%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
    }
}
