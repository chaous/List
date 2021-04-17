//
// Created by Ilya on 4/17/2021.
//

#ifndef LIST_LISTITERATOR_H
#define LIST_LISTITERATOR_H
#include "List.h"


typedef struct It{

    Node* it;

}It;



It begin(List* list);
It end(List* list);

It next(It it);

It set(It it, void* elem);




#endif //LIST_LISTITERATOR_H
