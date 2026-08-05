#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct TAG_ELEMENT {
    int index;   
    double key;  
    int pos;     
} ELEMENT;

typedef struct TAG_HEAP {
    int capacity; 
    int size;     
    int *H;       
} HEAP;

extern ELEMENT **V;  
extern HEAP *pHeap;  
extern int g_n;      
extern char *g_input_filename;
extern char *g_output_filename;

#endif 
