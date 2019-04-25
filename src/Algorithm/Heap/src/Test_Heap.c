#include "Heap.h"

static int cmp_func(void * data1,void * data2)
{
    int i1 = *(int *)data1;
    int i2 = *(int *)data2;

    if ( i1 == i2 )
    {
        return 0;
    }
    else if ( i1 > i2 )
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


int main()
{
    int iArray[] = { 8,3,1,2,31,23,23,9,81 };
    int tmp;
    int iLoop =0;
    PHeap_st pHeap = Create_Heap ( sizeof(int),64,cmp_func);
    for ( iLoop = 0; iLoop < (sizeof ( iArray ) / sizeof(int)) ; iLoop++ )
    {
        pHeap->PushBack(pHeap,&iArray[iLoop]);
    //for ( jLoop = 0; jLoop < pHeap->Num; jLoop ++ )
    //{
    //    
    //    printf ("%d ",*(int *)(pHeap->DataArray[jLoop]));
    //}
    //printf("\n");

    }

    while ( pHeap->Empty(pHeap) != 1 )
    {
        pHeap->PopFront(pHeap,&tmp);
        printf ("%d ",tmp);
    //for ( jLoop = 0; jLoop < pHeap->Num; jLoop ++ )
    //{
    //    
    //    printf ("%d ",*(int *)(pHeap->DataArray[jLoop]));
    //}
    //printf("\n");



    }

    printf("\n");
    return 0;

    
}
