#include "KMP.h"
bool find_matchStr_Next_Array_for_KMP ( const char * sMatchStr, size_t iLenOfMatchStr, int NextArray[] )
{
    int iLoop = 1;
    int k = 0;
    NextArray[0] = 0;
    while ( iLoop < iLenOfMatchStr )
    {
        if ( sMatchStr[iLoop] == sMatchStr[k] )
        {
            NextArray[iLoop] = ++k;
            iLoop++;
        }
        else
        {
            if ( k != 0 )
            {
                k = 0;
            }
            else
            {
                NextArray[iLoop] = 0;
                iLoop++;
            }
       }

    }
    return true;
}

int find_First_Str_KMP ( const char * sSrcStr, size_t iLenOfSrcStr, const char * sMatchStr, size_t iLenOfMatchStr )
{
    int * NextArray = 0;
    int iLoop = 0;
    int jLoop = 0;
    NextArray = malloc ( sizeof ( int ) * iLenOfMatchStr );
    find_matchStr_Next_Array_for_KMP ( sMatchStr,iLenOfMatchStr,NextArray );
    while ( iLoop < iLenOfSrcStr )
    {
        if ( sSrcStr [iLoop] == sMatchStr[jLoop] )              
        {
            jLoop++;
            iLoop++;

            if ( jLoop == (int)iLenOfMatchStr )
            {
                return ( iLoop - jLoop );
            }
        }
        else
        {
            if ( jLoop == 0 )
            {
                iLoop++;
            }
            else
            {
                jLoop = NextArray[jLoop];
            }
        }

    }
    free ( NextArray );
    UserDebug("in %s :: Not Match!",__func__);
    return -1;
}

