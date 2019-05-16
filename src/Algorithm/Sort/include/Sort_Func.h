#ifndef SORT_FUNC_LYW_CODE
#define SORT_FUNC_LYW_CODE
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum _CompareResultForSort
{
    LESSTHAN = -1,
    EQUAL,
    GREATERTHAN
} TCompareResultForSort;
typedef TCompareResultForSort ( * TCompareForSort ) ( void * data1,void * data2 );
bool Func_INSERT_SORT ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func);
bool Func_Bubble_SORT ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func);
bool Func_Select_Sort ( void * DataArray, size_t DataSize, size_t ArraySize, TCompareForSort compare_func);
bool Func_Shell_Sort ( void * DataArray, size_t DataSize, size_t ArraySize,TCompareForSort compare_func );
#endif
