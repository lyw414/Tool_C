#include "Sort.h"
TCompareResultForSort CompareForSort ( void * data1,void * data2 )
{

    if ( (*(int *)(data1)) == (*(int*)(data2)) )    
    {
        return EQUAL;
    }
    else if ( (*(int *)(data1)) > (*(int *)(data2)) )    
    {
        return LESSTHAN;
    }
    else
    {
        return GREATERTHAN;
    }
}

int main()
{
    int a[] = { 11,1,4,2,8,0,9};
    int iLoop = 0;
//    Sort(p,CompareForSort);
    PSort p = Init_Sort ( CompareForSort );
//  p->SortFunc(&p,a,sizeof(int),sizeof(a) / sizeof ( int ) ,Bubble_SORT);
//  p->SortFunc(p,a,sizeof(int),sizeof(a) / sizeof ( int ) ,INSERT_SORT);
//  p->SortFunc(p,a,sizeof(int),sizeof(a) / sizeof ( int ) ,SELECT_SORT);
    p->SortFunc(p,a,sizeof(int),sizeof(a) / sizeof ( int ) ,SHELL_SORT);
    for ( iLoop = 0; iLoop < sizeof(a) / sizeof(int);iLoop++)
    {
        printf("%d ",a[iLoop] );
    }
    printf ("\n");

    Free_Sort ( p );
    return 0;
}
