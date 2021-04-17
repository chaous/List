//
// Created by Ilya on 4/17/2021.
//
#include "List.h"
#include <stdlib.h>


List *initList(List *list) {
    list->node = NULL;
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
    Node* node = (Node*) malloc(sizeof(Node));
    node->elem = NewElem;
    node->node = NULL;
    return node;
}

bool delElem(List *list, void *elem) {
    Node* delElem = list->node;
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
