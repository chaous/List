#include <stdio.h>
#include "List.h"


int main()
{
    List list;
    initList(&list);
    int a = 4;
    addElem(&list, &a);
    addElem(&list, &a);
    addElem(&list, &a);
    //delElmByNumber(&list, 1);


    print(&list, makeInt);
    printf("%d\n", lengh(&list));
    return 0;
}
