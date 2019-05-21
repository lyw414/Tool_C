#ifndef SORT_FUNC_LYW_CODE
#define SORT_FUNC_LYW_CODE
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum _CompareResultForSort
{
    GREATERTHAN = -1,
    EQUAL,
    LESSTHAN 
} TCompareResultForSort;
typedef TCompareResultForSort ( * TCompareForSort ) ( void * data1,void * data2 );
bool Func_INSERT_SORT ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func);
bool Func_Bubble_SORT ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func);
bool Func_Select_Sort ( void * DataArray, size_t DataSize, size_t ArraySize, TCompareForSort compare_func);
bool Func_Shell_Sort ( void * DataArray, size_t DataSize, size_t ArraySize,TCompareForSort compare_func );
bool Func_Quick_Sort ( void * DataArray, size_t DataSize, size_t ArraySize,TCompareForSort compare_func );
bool direct_insert_sort ( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func);
bool Func_Merge_Sort( void * DataArray,size_t DataSize,size_t ArraySize,TCompareForSort compare_func);
#endif
