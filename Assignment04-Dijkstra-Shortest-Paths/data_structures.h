// data_structures.h
// CSE310 Project 4
// Dhanashree Somani
// ASU ID: 1239782599
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>

typedef enum { WHITE, GRAY, BLACK } COLOR;

typedef struct TAG_VERTEX {
    int    index;
    COLOR  color;
    double key;
    int    pi;       
    int    position;
} VERTEX;

typedef VERTEX* pVERTEX;

typedef VERTEX   ELEMENT;
typedef ELEMENT* pELEMENT;

typedef struct TAG_NODE {
    int      index;
    int      u;
    int      v;
    double   w;
    TAG_NODE* next;
} NODE;

typedef NODE* pNODE;

typedef struct TAG_HEAP {
    int       capacity;
    int       size;
    pELEMENT* H;
} HEAP;

typedef HEAP* pHEAP;

typedef struct TAG_STACK {
    int       capacity;
    int       top;
    pELEMENT* S;
} STACK;

typedef STACK* pSTACK;

#endif
