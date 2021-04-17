//
// Created by Ilya on 4/17/2021.
//
#include "ListIterator.h"
#include "stdlib.h"

It begin(List *list) {
    It it;
    it.it = list->node;
    return it;
}

It end(List *list) {
    It it;
    it.it = list->node;
    while (it.it != NULL)
        it.it = it.it->node;
    return it;

}

It next(It it) {
    if(it.it->node != NULL)
    {
        it.it = it.it->node;
        return it;
    }
    exit(1);
}

It set(It it, void *elem) {
    it.it->elem = elem;
    return it;
}






