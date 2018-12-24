#include "Stack.h"
bool push_for_Stack ( struct _stack * self, void * value )
{
    return self->DataList.push_back(& (self->DataList), value);
}
bool get_for_Stack ( struct _stack * self, void * value )
{
    return self->DataList.get_back(& (self->DataList), value);
}
bool pop_for_Stack ( struct _stack * self, void * value )
{
    return self->DataList.pop_back(& (self->DataList), value);
}
bool empty_for_Stack ( struct _stack * self )
{
    return self->DataList.empty(& (self->DataList));
}
bool full_for_Stack ( struct _stack * self )
{
    return self->DataList.full(& (self->DataList));
}
int size_for_Stack ( struct _stack * self )
{
    return self->DataList.size(& (self->DataList));
}
bool clear_for_Stack ( struct _stack * self )
{
    return self->DataList.clear(& (self->DataList));
}
bool free_for_Stack ( struct _stack * self )
{
    return self->DataList.free(& (self->DataList));
}
bool init_for_Stack ( struct _stack * self )
{
    return self->DataList.init(&(self->DataList));
}
