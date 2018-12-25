#include "KMP.h"

int main()
{
    Init_Log ( "List_KMP","./log/",DEBUG_LEVEL,10,PTHREAD_MODE); 
    char srcstr[] = "13312acbdadeadj12312ei123123ad1231l12311311311a12dhl1231231ahdueal12312";
    char matchstr[] = "12a3a12";
    printf ( "%d\n",find_First_Str_KMP ( srcstr, strlen(srcstr), matchstr, strlen(matchstr) ) );
    return 0;
}
