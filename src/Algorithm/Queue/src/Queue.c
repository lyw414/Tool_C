#include "Queue.h"

bool push_for_Queue ( struct _queue * self, void * value )
{
    return self->DataList.push_back( &(self->DataList), value );
}
bool get_for_Queue ( struct _queue * self, void * value )
{
    return self->DataList.get_front( &(self->DataList), value );
}
bool pop_for_Queue ( struct _queue * self, void * value )
{
    return self->DataList.pop_front( &(self->DataList), value );
}
bool empty_for_Queue ( struct _queue * self )
{
    return self->DataList.empty( &(self->DataList) );
}
bool full_for_Queue ( struct _queue * self )
{
    return self->DataList.full( &(self->DataList) );
}
int size_for_Queue ( struct _queue * self )
{
    return self->DataList.size( &(self->DataList) );
}

bool clear_for_Queue ( struct _queue * self )
{
    return self->DataList.clear( &(self->DataList) );
}
bool free_for_Queue ( struct _queue * self )
{
    return self->DataList.free( &(self->DataList) );
}
bool init_for_Queue ( struct _queue * self )
{
    return self->DataList.init( &(self->DataList) );
}

