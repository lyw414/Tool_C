#ifndef LYW_CODE_FixedLengthList
#define LYW_CODE_FixedLengthList
#include "Log.h"
#include <stdlib.h>

typedef struct _fixed_length_list_info
{
    void ** dataArray;
    size_t data_size;
    //size_t fixedSize;
    size_t totalSize;

    char szListName [ 64 ];

    int headIndex;
    int endIndex;

    bool (* push_back) ( struct _fixed_length_list_info * self, void * value );
    bool (* get_back) ( struct _fixed_length_list_info * self, void * value );
    bool (* pop_back) ( struct _fixed_length_list_info * self, void * value );

    bool (* push_front) ( struct _fixed_length_list_info * self, void * value );
    bool (* get_front) ( struct _fixed_length_list_info * self, void * value );
    bool (* pop_front) ( struct _fixed_length_list_info * self, void * value );

    bool (* full) ( struct _fixed_length_list_info * self );
    bool (* empty) ( struct _fixed_length_list_info * self );
    bool (* clear) ( struct _fixed_length_list_info * self );
    
    int (* size) (struct _fixed_length_list_info * self );
    bool (* free) (struct _fixed_length_list_info * self);
    bool (* init) (struct _fixed_length_list_info * self);

}TFixedLengthList,*PFixedLengthList;


bool init_for_FixedLengthList ( struct _fixed_length_list_info * self );

bool push_back_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value );
bool get_back_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value );
bool pop_back_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value );

bool push_front_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value );
bool get_front_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value );
bool pop_front_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value );

bool full_for_FixedLengthList ( struct _fixed_length_list_info * self );
bool empty_for_FixedLengthList ( struct _fixed_length_list_info * self );
bool clear_for_FixedLengthList ( struct _fixed_length_list_info * self );
bool free_for_FixedLengthList ( struct _fixed_length_list_info * self );
int size_for_FixedLengthList ( struct _fixed_length_list_info * self );

#define FixedLengthList(p,type,Size)\
    TFixedLengthList  p = \
    {\
        .dataArray = NULL,\
        .data_size = sizeof(type),\
        .totalSize = Size,\
        .szListName = #p,\
        .headIndex = 0,\
        .endIndex = 1,\
        .push_back = push_back_for_FixedLengthList,\
        .get_back = get_back_for_FixedLengthList,\
        .pop_back = pop_back_for_FixedLengthList,\
        .push_front = push_front_for_FixedLengthList,\
        .get_front = get_front_for_FixedLengthList,\
        .pop_front = pop_front_for_FixedLengthList,\
        .full = full_for_FixedLengthList,\
        .empty = empty_for_FixedLengthList,\
        .clear = clear_for_FixedLengthList,\
        .free = free_for_FixedLengthList,\
        .size = size_for_FixedLengthList, \
        .init = init_for_FixedLengthList\
    };
#define _FixedLengthList(p,type,Size)\
    p = \
    {\
        .dataArray = NULL,\
        .data_size = sizeof(type),\
        .totalSize = Size,\
        .szListName = #p,\
        .headIndex = 0,\
        .endIndex = 1,\
        .push_back = push_back_for_FixedLengthList,\
        .get_back = get_back_for_FixedLengthList,\
        .pop_back = pop_back_for_FixedLengthList,\
        .push_front = push_front_for_FixedLengthList,\
        .get_front = get_front_for_FixedLengthList,\
        .pop_front = pop_front_for_FixedLengthList,\
        .full = full_for_FixedLengthList,\
        .empty = empty_for_FixedLengthList,\
        .clear = clear_for_FixedLengthList,\
        .free = free_for_FixedLengthList,\
        .size = size_for_FixedLengthList, \
        .init = init_for_FixedLengthList\
    }

#endif
