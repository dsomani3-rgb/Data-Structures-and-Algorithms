// Dhanashree Somani
// ASU ID: 1239782599
#include "main.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./PJ4 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    const char* inputFile  = argv[1];
    const char* graphType  = argv[2];
    const char* flagStr    = argv[3];

    int directed = -1;
    if (strcmp(graphType, "DirectedGraph") == 0)   directed = 1;
    else if (strcmp(graphType, "UndirectedGraph") == 0) directed = 0;
    else {
        fprintf(stderr, "Usage: ./PJ4 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    int flag = -1;
    if (strcmp(flagStr, "1") == 0)      flag = 1;
    else if (strcmp(flagStr, "0") == 0) flag = 0;
    else {
        fprintf(stderr, "Usage: ./PJ4 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    int n = 0, m = 0;
    pVERTEX* V   = NULL;
    pNODE*   ADJ = NULL;

    if (!ReadGraph(inputFile, &n, &m, &V, &ADJ, directed, flag)) {
        fprintf(stderr, "Error: Cannot read graph from %s\n", inputFile);
        return 1;
    }

    pHEAP  pHeap  = CreateHeap(n);
    pSTACK pStack = CreateStack(n);

    int lastMode = 0;
    int lastSource = 0;
    int lastDest   = 0;

    char instruction[64];
    while (scanf("%s", instruction) == 1) {
        if (strcmp(instruction, "Stop") == 0) {
            break;
        } else if (strcmp(instruction, "PrintADJ") == 0) {
            PrintADJ(n, ADJ);
        } else if (strcmp(instruction, "SinglePair") == 0) {
            int s, t;
            scanf("%d %d", &s, &t);
            DijkstraST(n, ADJ, V, pHeap, s, t);
            lastMode   = 1;
            lastSource = s;
            lastDest   = t;
        } else if (strcmp(instruction, "SingleSource") == 0) {
            int s;
            scanf("%d", &s);
            DijkstraST(n, ADJ, V, pHeap, s, -1);
            lastMode   = 2;
            lastSource = s;
            lastDest   = -1;
        } else if (strcmp(instruction, "PrintLength") == 0) {
            int s, t;
            scanf("%d %d", &s, &t);
            bool valid = false;
            if (lastMode == 2 && s == lastSource) valid = true;
            if (lastMode == 1 && s == lastSource && t == lastDest) valid = true;
            if (valid) {
                PrintLength(V, s, t);
            } else {
                fprintf(stderr, "Error: Invalid instruction.\n");
            }
        } else if (strcmp(instruction, "PrintPath") == 0) {
            int s, t;
            scanf("%d %d", &s, &t);
            bool valid = false;
            if (lastMode == 2 && s == lastSource) valid = true;
            if (lastMode == 1 && s == lastSource && t == lastDest) valid = true;
            if (valid) {
                PrintPath(n, V, pStack, s, t);
            } else {
                fprintf(stderr, "Error: Invalid instruction.\n");
            }
        } else {
            fprintf(stderr, "Error: Invalid instruction.\n");
        }
    }

    DestroyHeap(pHeap);
    DestroyStack(pStack);
    FreeGraph(n, V, ADJ);

    return 0;
}
