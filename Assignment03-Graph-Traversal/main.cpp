// Name: Dhanashree Somani
// ASU ID: 1239782599

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    const char *inputFile = argv[1];
    const char *graphType = argv[2];
    int flag = atoi(argv[3]);

    int isDirected;
    if (strcmp(graphType, "DirectedGraph") == 0) {
        isDirected = 1;
    } else if (strcmp(graphType, "UndirectedGraph") == 0) {
        isDirected = 0;
    } else {
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    if (flag < 0 || flag > 2) {
        fprintf(stderr, "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n");
        return 1;
    }

    GRAPH *G = readGraph(inputFile, isDirected, flag);
    if (G == NULL) {
        return 1;
    }

    QUEUE *Q = initQueue();

    int bfsDone = 0;
    int dfsDone = 0;

    char instruction[256];
    while (scanf("%s", instruction) == 1) {
        if (strcmp(instruction, "Stop") == 0) {
            break;
        } else if (strcmp(instruction, "ADJPrintAll") == 0) {
            adjPrintAll(G);
        } else if (strcmp(instruction, "ADJPrintOne") == 0) {
            int vertex;
            scanf("%d", &vertex);
            adjPrintOne(G, vertex);
        } else if (strcmp(instruction, "BFS") == 0) {
            int source;
            scanf("%d", &source);
            BFS(G, Q, source);
            bfsDone = 1;
        } else if (strcmp(instruction, "DFS") == 0) {
            DFS(G);
            dfsDone = 1;
        } else if (strcmp(instruction, "BFSPrintAll") == 0) {
            if (!bfsDone) {
                fprintf(stderr, "BFS has not been performed yet.\n");
            } else {
                bfsPrintAll(G);
            }
        } else if (strcmp(instruction, "BFSPrintOne") == 0) {
            int vertex;
            scanf("%d", &vertex);
            if (!bfsDone) {
                fprintf(stderr, "BFS has not been performed yet.\n");
            } else {
                bfsPrintOne(G, vertex);
            }
        } else if (strcmp(instruction, "DFSPrintAll") == 0) {
            if (!dfsDone) {
                fprintf(stderr, "DFS has not been performed yet.\n");
            } else {
                dfsPrintAll(G);
            }
        } else if (strcmp(instruction, "DFSPrintOne") == 0) {
            int vertex;
            scanf("%d", &vertex);
            if (!dfsDone) {
                fprintf(stderr, "DFS has not been performed yet.\n");
            } else {
                dfsPrintOne(G, vertex);
            }
        } else {
            fprintf(stderr, "Invalid instruction.\n");
        }
    }

    freeQueue(Q);
    freeGraph(G);

    return 0;
}
