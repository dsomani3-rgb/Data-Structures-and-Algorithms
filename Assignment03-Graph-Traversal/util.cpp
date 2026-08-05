// Name: Dhanashree Somani
// ASU ID: 1239782599

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

GRAPH* readGraph(const char *filename, int isDirected, int flag) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    int n, m;
    fscanf(fp, "%d %d", &n, &m);

    GRAPH *G = createGraph(n, m, isDirected, flag);

    for (int i = 0; i < m; i++) {
        int idx, u, v;
        double w;
        fscanf(fp, "%d %d %d %lf", &idx, &u, &v, &w);
        insertEdge(G, idx, u, v, w);
    }

    fclose(fp);
    return G;
}
