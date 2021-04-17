//
// Created by Ilya on 4/17/2021.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "stdbool.h"
#include <stddef.h>



typedef struct Node
{
    struct Node* node;
    void* elem;
}Node;

typedef struct List
{
    Node* node;
}List;

List* initList(List* list);

void addElem(List* list, void* newElem);

Node* initNode(void* NewElem);

bool delElem(List* list, void* elem);

size_t lengh(List* list);
bool delElmByNumber(List* list, size_t number);

int makeInt(Node* node);

void print(List* list, int (*makeType)(Node* node));
bool isSorted(List* list);



#endif //LIST_LIST_H
