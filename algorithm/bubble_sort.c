//BubbleSort.c

#include <stdio.h>

#include "type.h"

void swap(ElemType  **a, ElemType **b)

{



    ElemType tmp = *a;

    *a=*b;

    *b=tmp;



}

void BubbleSort( SqList *L)

{

    int i;

    for(i=0;i<L->length ; i++)

    {

        int j;

        for(j=i+1; j<L->length; j++)

        {

            if(L->data[i]> L->data[j])

            {

                swap(&L->data[i], &L->data[j]);

            }

        }

    }

}

void printContent(SqList *L)

{

    int i;

    for(i=0;i< L->length;i++)

    {

        printf("%d ", L->data[i]);

    }

}

void main(void)

{

    SqList list, *slist;

    slist = &list;

    slist->data[0]=1;

    slist->data[1]=5;

    slist->data[2]=4;

    slist->data[3]=2;

    slist->data[4]=22;

    slist->length=5;

    printContent(slist);

    printf("\n");

    BubbleSort(slist);

    printContent(slist);

    printf("\n");

}
