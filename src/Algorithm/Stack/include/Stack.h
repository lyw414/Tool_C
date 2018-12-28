#ifndef LYW_code_STACK
#define LYW_code_STACK
#include "Log.h"
#include "FixedLengthList.h"

typedef struct _stack
{
    TFixedLengthList DataList;

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
        _FixedLengthList(.DataList,m_type,Size),\
        .push=push_for_Stack,\
        .get=get_for_Stack,\
        .pop=pop_for_Stack,\
        .empty=empty_for_Stack,\
        .full=full_for_Stack,\
        .size=size_for_Stack,\
        .clear=clear_for_Stack,\
        .free=free_for_Stack,\
        .init=init_for_Stack\
    };

#define _Stack(p,m_type,Size) \
    p = \
    {\
        _FixedLengthList(.DataList,m_type,Size),\
        .push=push_for_Stack,\
        .get=get_for_Stack,\
        .pop=pop_for_Stack,\
        .empty=empty_for_Stack,\
        .full=full_for_Stack,\
        .size=size_for_Stack,\
        .clear=clear_for_Stack,\
        .free=free_for_Stack,\
        .init=init_for_Stack\
    }



#endif
