
#include "UI.h"
#include "ListIterator.h"
#include <stdio.h>
#include <stdlib.h>

void getInput() {
    List list;
    printf("chouse type int or float or double or long long or char\n");
    char type;
    scanf("%c", &type);
    list = *initList(&list, type);
    while(true)
    {
        char input;
        scanf("%c", &input);
        if (input == 'a')
        {
            if(list.type == 'i')
            {
                int* elem = (int*)malloc(sizeof(int));
                scanf("%i", elem);
                addElem(&list, elem);
            }
            if(list.type  == 'c')
            {
                char* elem = (char*)malloc(sizeof(char));
                scanf("%c", elem);
                addElem(&list, elem);
            }
            if(list.type  == 'l')
            {
                long long* elem = (long long*)malloc(sizeof(long long));
                scanf("%llu", elem);
                addElem(&list, elem);
            }
            if(list.type  == 'f')
            {
                float* elem = (float*)malloc(sizeof(float));
                scanf("%f", elem);
                addElem(&list, elem);
            }
            if(list.type  == 'd')
            {
                double* elem = (double*)malloc(sizeof(double));
                scanf("%lf", elem);
                addElem(&list, elem);
            }
            printList(&list);
        }

        if(input == 'd')
        {
            printf("elem\n");
            if(list.type  == 'i')
            {
                int* elem = (int*)malloc(sizeof(int));
                scanf("%i", elem);
                delElem(&list, elem);
            }
            if(list.type  == 'c')
            {
                char* elem = (char*)malloc(sizeof(char));
                scanf("%c", elem);
                delElem(&list, elem);
            }
            if(list.type  == 'l')
            {
                long long* elem = (long long*)malloc(sizeof(long long));
                scanf("%llu", elem);
                delElem(&list, elem);
            }
            if(list.type  == 'f')
            {
                float* elem = (float*)malloc(sizeof(float));
                scanf("%f", elem);
                delElem(&list, elem);
            }
            if(list.type  == 'd')
            {
                double* elem = (double*)malloc(sizeof(double));
                scanf("%lf", elem);
                delElem(&list, elem);
            }
            printList(&list);
        }
        if (input == 'n')
        {
            int elem;
            printf("number\n");
            scanf("%i", &elem);
            delElmByNumber(&list, elem);
        }
        if(input == 'p')
            printList(&list);

        if(input == 's')
        {
            if(isSorted(&list))
                printf("true\n");
            else
                printf("false\n");
        }
        if(input == 'e')
            break;
    }

    destroyList(&list);


}

