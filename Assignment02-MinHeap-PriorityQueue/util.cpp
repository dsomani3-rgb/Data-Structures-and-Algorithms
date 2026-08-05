#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

extern ELEMENT **V;
extern HEAP *pHeap;
extern int g_n;
extern char *g_input_filename;
extern char *g_output_filename;

static void DoRead() {
    printf("Instruction: Read\n");
    FILE *fin = fopen(g_input_filename, "r");
    if (fin == NULL) {
        fprintf(stderr, "Error: cannot open input file\n");
        return;
    }
    int n;
    if (fscanf(fin, "%d", &n) != 1) {
        fclose(fin);
        fprintf(stderr, "Error: cannot read n\n");
        return;
    }
    if (V != nullptr) {
        for (int i = 1; i <= g_n; ++i) {
            if (V[i] != nullptr) free(V[i]);
        }
        free(V);
        V = nullptr;
    }
    g_n = n;
    V = (ELEMENT**) malloc(sizeof(ELEMENT*) * (g_n + 1));
    for (int i = 1; i <= g_n; ++i) {
        V[i] = (ELEMENT*) malloc(sizeof(ELEMENT));
        V[i]->index = i;
        V[i]->pos = 0;
        V[i]->key = 0.0;
        double key;
        if (fscanf(fin, "%lf", &key) != 1) {
            key = 0.0;
        }
        V[i]->key = key;
    }
    fclose(fin);
    if (pHeap != nullptr) {
        if (pHeap->H != nullptr) free(pHeap->H);
        free(pHeap);
        pHeap = nullptr;
    }
    pHeap = (HEAP*) malloc(sizeof(HEAP));
    pHeap->capacity = g_n;
    pHeap->size = 0;
    pHeap->H = (int*) malloc(sizeof(int) * (pHeap->capacity + 1));
}

static void DoWrite() {
    printf("Instruction: Write\n");
    FILE *fout = fopen(g_output_filename, "w");
    if (fout == NULL) {
        fprintf(stderr, "Error: cannot open output file\n");
        return;
    }
    if (V != nullptr) {
        for (int i = 1; i <= g_n; ++i) {
            fprintf(fout, "%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
        }
    }
    fclose(fout);
}

void ProcessCommands(int argc, char **argv) {
    char line[256];
    while (true) {
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        char *p = line;
        while (*p && (*p == ' ' || *p == '\t')) ++p;
        int L = strlen(p);
        while (L > 0 && (p[L-1] == '\n' || p[L-1] == '\r')) { p[--L] = 0; }
        if (L == 0) continue;
        char cmd[64];
        char *tok = strtok(p, " \t");
        if (tok == NULL) continue;
        strncpy(cmd, tok, sizeof(cmd)-1); cmd[sizeof(cmd)-1] = 0;

        if (strcmp(cmd, "Stop") == 0) {
            printf("Instruction: Stop\n");
            break;
        } else if (strcmp(cmd, "Read") == 0) {
            DoRead();
        } else if (strcmp(cmd, "PrintArray") == 0) {
            PrintArray();
        } else if (strcmp(cmd, "PrintHeap") == 0) {
            PrintHeap();
        } else if (strcmp(cmd, "InitHeap") == 0) {
            printf("Instruction: InitHeap\n");
            InitHeap();
        } else if (strcmp(cmd, "BuildHeap") == 0) {
            printf("Instruction: BuildHeap\n");
            BuildHeap();
        } else if (strcmp(cmd, "Insert") == 0) {
            char *t = strtok(NULL, " \t");
            if (t == NULL) {
                fprintf(stderr, "Warning: Invalid instruction\n");
                continue;
            }
            int idx = atoi(t);
            Insert(idx);
        } else if (strcmp(cmd, "ExtractMin") == 0) {
            ExtractMin();
        } else if (strcmp(cmd, "DecreaseKey") == 0) {
            char *t1 = strtok(NULL, " \t");
            char *t2 = strtok(NULL, " \t");
            if (t1 == NULL || t2 == NULL) {
                fprintf(stderr, "Warning: Invalid instruction\n");
                continue;
            }
            int idx = atoi(t1);
            double newKey = atof(t2);
            DecreaseKey(idx, newKey);
        } else if (strcmp(cmd, "Write") == 0) {
            DoWrite();
        } else {
            fprintf(stderr, "Warning: Invalid instruction\n");
        }
    }
}
