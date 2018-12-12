#include "Log.h"
int main () 
{
    Init_Log("LYW_TEST","./log",DEBUG_LEVEL,1024,PTHREAD_MODE);
    return 0;
}
