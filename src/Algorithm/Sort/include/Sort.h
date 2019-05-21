#ifndef SORT_LYW_CODE
#define SORT_LYW_CODE
#include <stdio.h>
#include "Sort_Func.h"
#include <string.h>
typedef bool ( *TSortFuncForSort ) ( void * DataArray,size_t DataSize, size_t ArraySize,TCompareForSort compare_func);

//enum 类型 为 _g_SortFuncArray 函数指针所在下标

typedef enum _SortAlgorithmForSort
{
    DIRECT_INSERT_SORT, // direct insert sort 
    INSERT_SORT, //binary insert sort 
    Bubble_SORT,
    SELECT_SORT,
    SHELL_SORT,
    QUICK_SORT,
    MERGE_SORT
}TSortAlgorithmForSort;

static const TSortFuncForSort _g_SortFuncArray[] = 
{
    direct_insert_sort,
    Func_INSERT_SORT,
    Func_Bubble_SORT,
    Func_Select_Sort,
    Func_Shell_Sort,
    Func_Quick_Sort,
    Func_Merge_Sort
};

struct _Sort;
//typedef bool ( * TSwapForSort ) ( void ** DataArray,size_t i,size_t j );
typedef bool ( * TSortForSort ) ( struct _Sort * this, void * DataArray,size_t DataSize, size_t ArraySize,TSortAlgorithmForSort SortAlgorithm);
typedef bool ( * TSetCompareForSort ) ( struct _Sort * this,TCompareForSort Compare);



bool SortForSort ( struct _Sort * this, void * DataArray,size_t DataSize,size_t ArraySize,TSortAlgorithmForSort SortAlgorithm);
bool SetCompareForSort ( struct _Sort * this,TCompareForSort Compare);
typedef struct _Sort
{
    TCompareForSort Compare;
    //用户接口
    TSortForSort SortFunc;
    TSetCompareForSort SetCompare;
} TSort,*PSort;

PSort Init_Sort(TCompareForSort CompareFunc );
int Free_Sort(PSort pSort );


#define Sort(Name,CompareFunc) \
    TSort Name = {\
        .Compare = CompareFunc,\
        .SortFunc = SortForSort,\
        .SetCompare = SetCompareForSort \
    };

#define New_Sort(Name,CompareFunc) \
    PSort Name = (PSort)malloc ( sizeof(TSort) );\
    Name -> Compare = CompareFunc;\
    Name -> SortFunc = SortForSort;\
    Name -> SetCompare = SetCompareForSort;

#endif
