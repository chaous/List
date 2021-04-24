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



typedef struct typeList
{
    int (*makeInt)(Node* node);
    float (*makeFloat)(Node* node);
    double (*makeDouble)(Node* node);
    char (*makeChar)(Node* node);
    long long (*makeLongLong)(Node* node);

}typeList;

typedef struct List
{
    Node* node;
    typeList* typeList;
    char type;

}List;


typeList* initTypes(typeList* type, int (*makeInt)(Node* node), float (*makeFloat)(Node* node), char (*makeChar)(Node* node), long long (*makeLongLong)(Node* node), double (*makeDouble)(Node* node));


List* initList(List* list, char c);

void addElem(List* list, void* newElem);

Node* initNode(void* NewElem);

bool delElem(List* list, void* elem);

size_t lengh(List* list);
bool delElmByNumber(List* list, size_t number);

int makeInt(Node* node);
float makeFloat(Node* node);
double makeDouble(Node* node);
char makeChar(Node* node);
long long makeLongLong(Node* node);


void printInt(List* list, int (*makeType)(Node* node));
void printList(List* list);
void printFloat(List* list, float (*makeType)(Node* node));
void printDouble(List* list, double (*makeType)(Node* node));
void printChar(List* list, char (*makeType)(Node* node));
void printLongLong(List* list, long long (*makeType)(Node* node));
bool isSorted(List *list);

bool compInt(Node* a, Node* b);
bool comp(Node* a, Node* b, char type);
void destroyList(List* list);



#endif //LIST_LIST_H
