#include "RBTree.h"

int sp ( void * Data1, void * Data2,size_t DataSize )
{
    if ( *(int *)Data1 > *(int *) Data2 )
    {
        return 1;
    }

    if ( *(int *)Data1 < *(int *) Data2 )
    {
        return 2;
    }

    return 0;
}
int main()
{
    TCompareFunction_RBTree Cmp = NULL;
    TRBTreeNode outNodeArray[1024] = {0};
    PRBTree rbTree = RBTree_New(sizeof ( int ),sp);
    int tmp = 0;
    RBTree_Add ( rbTree,&tmp);
    tmp = 1;
    RBTree_Add ( rbTree,&tmp);
    tmp = 2;
    RBTree_Add ( rbTree,&tmp);
    tmp = 3;
    RBTree_Add ( rbTree,&tmp);
    tmp = 4;
    RBTree_Add ( rbTree,&tmp);
    tmp = 5;
    RBTree_Add ( rbTree,&tmp);
    tmp = 6;
    RBTree_Add ( rbTree,&tmp);
    tmp = 7;
    RBTree_Add ( rbTree,&tmp);
    tmp = Breadth_First_Travel ( rbTree->RootNode,outNodeArray, 1024);
    return 0;
}
