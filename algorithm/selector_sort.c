//SelectSort.c

#include <stdio.h>

#include "type.h"

void swap(ElemType *a, ElemType *b)

{

    ElemType *tmp = *a;

    *a=*b;

    *b=tmp;

}

void SelectSort(SqList *L)

{

    int min_key; ElemType min_value;

    for( int i= 0; i< L->length; i++)

    {

        

        min_key = i; 

        min_value = L->data[i];

        for( int j= i+1; j< L->length; j++)

        {

            if(min_value>L->data[j])

            {

                min_value  = L->data[j];

                min_key = j;

            }

        }

        if(i!=min_key)    

        swap( &(L->data[i]) , &(L->data[min_key] ));

    }

}

void printContent(SqList *L)

{

    for(int i = 0; i< L->length; i++)

    {

        printf("%d \t",L->data[i] );

    }

}

void main(void)

{

    SqList l ;

    

    l.data[0] = 9;

    l.data[1] = 1;

    l.data[2] = 5;

    l.data[3] = 8;

    l.data[4] = 3;

    l.data[5] = 7;

    l.data[6] = 4;

    l.data[7] = 6;

    l.data[8] = 2;

    l.length = 9;

    printContent(&l);

    printf("\n");

    SelectSort(&l);

    printContent(&l);

    printf("\n");

}
