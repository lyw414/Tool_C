#ifndef LYW_CODE_HEAP
#define LYW_CODE_HEAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * return data1 == data2 0
 *        data1 > data2  1
 *        data1 < data2  2
 *
 */
typedef int ( * TCompare_Function_For_Heap ) ( void * data1, void * data2 );

typedef struct _Heap
{
    //it's circle Array
    void ** DataArray;
    size_t DataSize;
    size_t Num;
    size_t MaxSize;
    TCompare_Function_For_Heap compare_func;
    int ( * PopFront ) (struct _Heap * self, void * data );
    int ( * PushBack ) (struct _Heap * self, void * data );
    int ( * SinkDown ) (struct _Heap * self, size_t index );
    int ( * FloatUp ) (struct _Heap * self, size_t index );
    int ( * Size ) ( struct _Heap * self );
    int ( * Empty ) ( struct _Heap * self );
}THeap_st,* PHeap_st;

//int PopFront_For_Heap (struct _Heap * self, void * data1 );
//int PUshBack_For_Heap (struct _Heap * self, void * data1 );
//int TSize_For_Heap (struct _Heap * self);
//int SinkDown_For_Heap (struct _Heap * self, size_t index );
//int FloatUp_For_Heap  (struct _Heap * self, size_t index );
//int Empty_For_Heap ( struct _Heap * self );
 

/*
 * @brief  初始化长度 用于设置初始化的堆空间大小 预估值用于减少堆的动态分配代价
 *
 * @param[in] InitSize 
 *
 * return  堆指针
 */
PHeap_st Create_Heap( size_t DataSize, size_t InitSize, TCompare_Function_For_Heap compare_func);

/*
 * @brief 释放堆资源
 *
 */
int Free_Heap( PHeap_st pHeap);

#endif
