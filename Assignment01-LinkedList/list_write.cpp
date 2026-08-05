// Dhanashree Somani
// ASU ID: 1239782599

#include <cstdio>
#include <new>
#include "list_read.h"
#include "list_write.h"

void listRelease(LIST *pLIST) {
    if (pLIST == NULL) return;

    NODE *curr = pLIST->head;
    NODE *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    pLIST->head = NULL;
    pLIST->tail = NULL;
    pLIST->length = 0;
}

NODE *listInsert(LIST *pLIST, double key) {
    if (pLIST == NULL) return NULL;

    NODE *node = new (std::nothrow) NODE;
    if (node == NULL) return NULL;

    node->key = key;
    node->next = pLIST->head;
    pLIST->head = node;

    if (pLIST->length == 0) {
        pLIST->tail = node;
    }

    pLIST->length++;
    return node;
}

NODE *listAppend(LIST *pLIST, double key) {
    if (pLIST == NULL) return NULL;

    NODE *node = new (std::nothrow) NODE;
    if (node == NULL) return NULL;

    node->key = key;
    node->next = NULL;

    if (pLIST->length == 0) {
        pLIST->head = node;
        pLIST->tail = node;
    } else {
        pLIST->tail->next = node;
        pLIST->tail = node;
    }

    pLIST->length++;
    return node;
}

NODE *listDelete(LIST *pLIST, double key) {
    if (pLIST == NULL) return NULL;

    NODE *curr = pLIST->head;
    NODE *prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                pLIST->head = curr->next;
            } else {
                prev->next = curr->next;
            }

            if (curr == pLIST->tail) {
                pLIST->tail = prev;
            }

            pLIST->length--;
            curr->next = NULL; 
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    fprintf(stdout, "Warning in listDelete: Key %0.6f not in list\n", key);
    return NULL;
}

void listPrint(LIST *pLIST) {
    if (pLIST == NULL) return;

    NODE *curr = pLIST->head;
    while (curr != NULL) {
        fprintf(stdout, "%lf\n", curr->key);
        curr = curr->next;
    }
}

int listLength(LIST *pLIST) {
    if (pLIST == NULL) return 0;
    return pLIST->length;
}
