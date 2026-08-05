#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "data_structures.h"
#include "util.h"

ELEMENT **V = nullptr;
HEAP *pHeap = nullptr;
int g_n = 0;
char *g_input_filename = nullptr;
char *g_output_filename = nullptr;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./PJ2 <I-File> <O-File>\n");
        fprintf(stderr, "<I-File> is the name of the input file\n");
        fprintf(stderr, "<O-File> is the the name of the output file\n");
        return 1;
    }
    g_input_filename = argv[1];
    g_output_filename = argv[2];

    V = nullptr;
    pHeap = nullptr;
    g_n = 0;

    ProcessCommands(argc, argv);

    if (pHeap != nullptr) {
        if (pHeap->H != nullptr) free(pHeap->H);
        free(pHeap);
        pHeap = nullptr;
    }
    if (V != nullptr) {
        for (int i = 1; i <= g_n; ++i) {
            if (V[i] != nullptr) free(V[i]);
        }
        free(V);
        V = nullptr;
    }
    return 0;
}
