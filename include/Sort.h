#ifndef SORT_LYW_CODE
#define SORT_LYW_CODE
#include <stdio.h>
#include "Sort_Func.h"
#include <string.h>
typedef bool ( *TSortFuncForSort ) ( void * DataArray,size_t DataSize, size_t ArraySize,TCompareForSort compare_func);

//enum 类型 为 _g_SortFuncArray 函数指针所在下标

typedef enum _SortAlgorithmForSort
{
    INSERT_SORT,
    Bubble_SORT
}TSortAlgorithmForSort;

static TSortFuncForSort _g_SortFuncArray[] = 
{
    Func_INSERT_SORT,
    Func_Bubble_SORT
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
} TSort,*pSort;

#define Sort(Name,CompareFunc) \
    TSort Name = {\
        .Compare = CompareFunc,\
        .SortFunc = SortForSort,\
        .SetCompare = SetCompareForSort \
    };

#define New_Sort(Name,CompareFunc) \
    pSort Name = (pSort)malloc ( sizeof(TSort) );\
    Name -> Compare = CompareFunc;\
    Name -> SortFunc = SortForSort;\
    Name -> SetCompare = SetCompareForSort;

#endif
