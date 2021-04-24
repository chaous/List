//
// Created by Ilya on 4/17/2021.
//
#include "List.h"
#include <stdlib.h>
#include <stdio.h>


List *initList(List *list, char c) {
    list->node = NULL;
    list->typeList = initTypes((list->typeList), makeInt, makeFloat, makeChar,
    makeLongLong, makeDouble);
    list->type = c;
    return list;
}

void addElem(List* list, void *newElem) {
    Node* node = initNode(newElem);
    if(list->node == NULL)
    {
        list->node = node;
        return;
    }
    Node* lastElem = list->node;
    while (lastElem->node != NULL)
        lastElem = lastElem->node;
    lastElem->node = node;


}

Node *initNode(void *NewElem) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->elem = NewElem;
    node->node = NULL;
    return node;
}

bool delElem(List *list, void *elem) {
    if(list->node == NULL)
        return false;
    if (list->type == 'i') {
        int value = *(int *) elem;
        Node *node = list->node;
        if (*(int *) (list->node->elem) == value) {
            list->node = node->node;
            free(node);
            return true;
        }
            while (*(int *) (node->node->elem) != value)
                node = node->node;
            if (*(int *) (node->node->elem) == value) {
                Node *delElem = node->node;
                node->node = delElem->node;
                free(delElem);
                return true;
            }

    }
        if (list->type == 'c')
        {
            char value = *(char*)elem;
            Node* node = list->node;
            if(*(char*)(list->node->elem) == value) {
                list->node = node->node;
                free(node);
                return true;
            }
                while(*(char*)(node->node->elem) != value)
                    node = node->node;
                if(*(char*)(node->node->elem) == value) {
                    Node *delElem = node->node;
                    node->node = delElem->node;
                    free(delElem);
                    return true;
                }

    }
    if (list->type == 'd')
    {
        double value = *(double*)elem;
        Node* node = list->node;
        if(*(double*)(list->node->elem) == value) {
            list->node = node->node;
            free(node);
            return true;
        }
            while(*(double*)(node->node->elem) != value)
                node = node->node;
            if(*(double*)(node->node->elem) == value) {
                Node *delElem = node->node;
                node->node = delElem->node;
                free(delElem);
                return true;
            }
        }

    if (list->type == 'l')
    {
        long long value = *(long long*)elem;
        Node* node = list->node;
        if(*(long long*)(list->node->elem) == value) {
            list->node = node->node;
            free(node);
            return true;
        }
            while(*(long long*)(node->node->elem) != value)
                node = node->node;
            if(*(long long*)(node->node->elem) == value) {
                Node *delElem = node->node;
                node->node = delElem->node;
                free(delElem);
                return true;
            }
        }

    if (list->type == 'f')
    {
        float value = *(float*)elem;
        Node* node = list->node;
        if(*(float*)(list->node->elem) == value) {
            list->node = node->node;
            free(node);
            return true;
        }

            while(*(float*)(node->node->elem) != value)
                node = node->node;
            if(*(float*)(node->node->elem) == value) {
                Node *delElem = node->node;
                node->node = delElem->node;
                free(delElem);
                return true;
            }
        }

    /*Node* delElem = list->node;
    if(delElem == NULL)
        return false;
    if(delElem->elem == elem)
    {
        list->node = delElem->node;
        free(delElem);
        return true;
    }
    while (delElem->node != NULL)
    {
        if(delElem->node->elem == elem)
        {
            Node* node = delElem->node;
            delElem->node = node->node;
            free(node);
            return true;
        }
        delElem = delElem->node;
    }
    return false;*/
    return false;
}

size_t lengh(List *list) {
    size_t size = 0;
    Node* node = list->node;
    while(node != 0)
    {
        ++size;
        node = node->node;
    }

    return size;
}

bool delElmByNumber(List *list, size_t number) {
    if(list == NULL)
        return false;
    if(list->node == NULL)
        return false;
    Node* node = list->node;
    if(number == 0)
    {
        list->node = node->node;
        free(node);
        return true;
    }
    for(size_t i = 0; i != number - 1; ++i)
    {
        if(node->node == NULL)
            return false;
        node = node->node;
    }

    Node* delElem = node->node;
    node->node = delElem->node;
    free(delElem);
    return true;

}

int makeInt(Node *node) {
    int elem = *(int *)(node->elem);
    return elem;
}

void printInt(List *list, int (*makeType)(Node *)) {
    Node* node = list->node;
    while(node != 0)
    {
        int elem = (*makeType)(node);
        printf("%d->", elem);
        node = node->node;
    }
    printf("NULL\n");

}

bool isSorted(List *list){
    Node* node = list->node;
    if(node == NULL)
        return true;
    while (node->node != NULL)
    {
        if(comp(node, (node->node), list->type))
            return false;
        node = node->node;
    }
    return true;
}


bool compInt(Node *a, Node *b) {
    int elem = *(int *)(a->elem);
    int elem2 = *(int *)(b->elem);
    return elem > elem2;
}

void destroyList(List *list) {
    Node* node = list->node;
    while(node->node != NULL)
    {
        Node* nodeOld = node;
        node = node->node;
        free(nodeOld);
    }
    //list->node = NULL;
}

long long makeLongLong(Node *node) {
    return *(long long *)(node->elem);
}

char makeChar(Node *node) {
    return *(char *)(node->elem);
}

double makeDouble(Node *node) {
    return *(double *)(node->elem);
}

float makeFloat(Node *node) {
    return *(float *)(node->elem);
}



void printChar(List *list, char (*makeType)(Node *)) {
    Node* node = list->node;
    while(node != 0)
    {
        char elem = (*makeType)(node);
        printf("%c->", elem);
        node = node->node;
    }
    printf("NULL\n");
}


void printList(List *list) {
    if(list->type == 'i')
        printInt(list, list->typeList->makeInt);
    if(list->type == 'c')
        printChar(list, list->typeList->makeChar);
    if(list->type == 'l')
        printLongLong(list, list->typeList->makeLongLong);
    if(list->type == 'f')
        printFloat(list, list->typeList->makeFloat);
    if(list->type == 'd')
        printDouble(list, list->typeList->makeDouble);



}

void printFloat(List *list, float (*makeType)(Node *)) {
    Node* node = list->node;
    while(node != 0)
    {
        float elem = (*makeType)(node);
        printf("%f->", elem);
        node = node->node;
    }
    printf("NULL\n");
}

void printDouble(List *list, double (*makeType)(Node *)) {
    Node* node = list->node;
    while(node != 0)
    {
        double elem = (*makeType)(node);
        printf("%lf->", elem);
        node = node->node;
    }
    printf("NULL\n");
}

void printLongLong(List *list, long long int (*makeType)(Node *)) {
    Node* node = list->node;
    while(node != 0)
    {
        long long elem = (*makeType)(node);
        printf("%lld->", elem);
        node = node->node;
    }
    printf("NULL\n");
}

bool comp(Node *a, Node *b, char type) {
    if(type == 'i')
        return makeInt(a) > makeInt(b);
    if(type == 'f')
        return makeFloat(a) > makeFloat(b);
    if (type == 'c')
        return makeChar(a) > makeChar(b);
    if (type == 'l')
        return makeLongLong(a) > makeLongLong(b);
    if (type == 'd')
        return makeDouble(a) > makeDouble(b);
}

typeList *initTypes(typeList *type, int (*makeInt)(Node *), float (*makeFloat)(Node *), char (*makeChar)(Node *),
                    long long int (*makeLongLong)(Node *), double (*makeDouble)(Node *)) {
    type = (typeList*)malloc(sizeof(typeList));
    type->makeDouble = makeDouble;
    type->makeChar = makeChar;
    type->makeInt = makeInt;
    type->makeLongLong = makeLongLong;
    type->makeFloat = makeFloat;
    return type;
}


