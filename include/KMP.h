#ifndef LYW_CODE_KMP
#define LYW_CODE_KMP
#include <stdlib.h>
#include "Log.h"

bool find_matchStr_Next_Array_for_KMP ( const char * sMatchStr, size_t iLenOfMatchStr, int NextArray[] );
int find_First_Str_KMP ( const char * sSrcStr, size_t iLenOfSrcStr, const char * sMatchStr, size_t iLenOfMatchStr );

//char * find_All_Str_KMP ( const char * sSrcStr, size_t iLenOfSrcStr, const char * sMatchStr, size_t iLenOfMatchStr );

#endif
