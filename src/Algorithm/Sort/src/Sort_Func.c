#include "Sort_Func.h"
static bool swap(void ** DataArray,size_t ArraySize, int i, int j )
{
    void * tmp = NULL;
    if ( i > ArraySize || j > ArraySize )
    {
        return false;
    }
    tmp = DataArray[i];
    DataArray[i] = DataArray[j];
    DataArray[j] = tmp;
    return true;
}

bool Func_INSERT_SORT ( void ** DataArray,size_t ArraySize,TCompareForSort compare_func)
{
    printf ("in %s :: %s \n",__func__,__FILE__);
    return true;
}

