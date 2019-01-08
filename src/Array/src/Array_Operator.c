#include "Array_Operator.h"
int ArrayFind ( void * array, size_t array_len, void *data, size_t dataSize )
{
    int iLoop = 0;
    while ( iLoop < array_len )
    {
        if ( memcmp ( array + iLoop * dataSize,data,dataSize ) == 0 )
        {
            return iLoop;
        }
        iLoop ++;
    } 
    return -1;
}
