#ifndef SORT_FUNC_LYW_CODE
#define SORT_FUNC_LYW_CODE
#include <stdbool.h>
#include <stdio.h>
typedef enum _CompareResultForSort
{
    LESSTHAN = -1,
    EQUAL,
    GREATERTHAN
} TCompareResultForSort;
typedef TCompareResultForSort ( * TCompareForSort ) ( void * data1,void * data2 );
bool Func_INSERT_SORT ( void ** DataArray,size_t ArraySize,TCompareForSort compare_func);
#endif
