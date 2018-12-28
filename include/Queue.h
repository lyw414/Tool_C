#ifndef LYW_CODE_QUEUE
#define LYW_CODE_QUEUE
#include "Log.h"
#include "FixedLengthList.h"

typedef struct _queue
{
    TFixedLengthList DataList;

    bool ( * push ) ( struct _queue * self, void * value );
    bool ( * get ) ( struct _queue * self, void * value );
    bool ( * pop ) ( struct _queue * self, void * value );

    bool ( * empty ) ( struct _queue * self );
    bool ( * full ) ( struct _queue * self );
    int ( * size ) ( struct _queue * self );

    bool ( * clear) ( struct _queue * self );
    bool ( * free ) ( struct _queue * self );
    bool ( * init ) ( struct _queue * self ); 

} TQueue,* PQueue;

bool push_for_Queue ( struct _queue * self, void * value );
bool get_for_Queue ( struct _queue * self, void * value );
bool pop_for_Queue ( struct _queue * self, void * value );

bool empty_for_Queue ( struct _queue * self );
bool full_for_Queue ( struct _queue * self );
int size_for_Queue ( struct _queue * self );

bool clear_for_Queue ( struct _queue * self );
bool free_for_Queue ( struct _queue * self );
bool init_for_Queue ( struct _queue * self );

#define Queue(p,m_type,Size) \
    struct _queue p = \
    {\
        _FixedLengthList(.DataList,m_type,Size),\
        .push=push_for_Queue,\
        .get=get_for_Queue,\
        .pop=pop_for_Queue,\
        .empty=empty_for_Queue,\
        .full=full_for_Queue,\
        .size=size_for_Queue,\
        .clear=clear_for_Queue,\
        .free=free_for_Queue,\
        .init=init_for_Queue\
    };

#define _Queue(p,m_type,Size) \
    p = \
    {\
        _FixedLengthList(.DataList,m_type,Size),\
        .push=push_for_Queue,\
        .get=get_for_Queue,\
        .pop=pop_for_Queue,\
        .empty=empty_for_Queue,\
        .full=full_for_Queue,\
        .size=size_for_Queue,\
        .clear=clear_for_Queue,\
        .free=free_for_Queue,\
        .init=init_for_Queue\
    }


#endif
