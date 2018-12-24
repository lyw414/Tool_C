#ifndef LYW_code_STACK
#define LYW_code_STACK
#include "Log.h"
#include "FixedLengthList.h"

typedef struct _stack
{
    TFixedLengthList DataList;
    char szListName [ 64 ];

    bool ( * push ) ( struct _stack * self, void * value );
    bool ( * get ) ( struct _stack * self, void * value );
    bool ( * pop ) ( struct _stack * self, void * value );

    bool ( * empty ) ( struct _stack * self );
    bool ( * full ) ( struct _stack * self );
    int ( * size ) ( struct _stack * self );

    bool ( * clear) ( struct _stack * self );
    bool ( * free ) ( struct _stack * self );
    bool ( * init ) ( struct _stack * self );

}TStack, * PStack;

bool push_for_Stack ( struct _stack * self, void * value );
bool get_for_Stack ( struct _stack * self, void * value );
bool pop_for_Stack ( struct _stack * self, void * value );

bool empty_for_Stack ( struct _stack * self );
bool full_for_Stack ( struct _stack * self );
int size_for_Stack ( struct _stack * self );

bool clear_for_Stack ( struct _stack * self );
bool free_for_Stack ( struct _stack * self );
bool init_for_Stack ( struct _stack * self );



#define Stack(p,m_type,Size) \
    struct _stack p = \
    {\
        .DataList = \
        {\
            .dataArray = NULL,\
            .data_size = sizeof(m_type),\
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
        },\
        .push=push_for_Stack,\
        .get=get_for_Stack,\
        .pop=pop_for_Stack,\
        .empty=empty_for_Stack,\
        .full=full_for_Stack,\
        .size=size_for_Stack,\
        .clear=clear_for_Stack,\
        .free=free_for_Stack,\
        .init=init_for_Stack\
    };\

#endif
