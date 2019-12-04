#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDistinct(char * s, char * t)
{
    int UsefullLen = 0;
    int UsefullNum = 0;
    int TmpNum = 0;
    int TmpLen = 0;
    int iLoopTag = 1;
    int iLoopSrc = 0;
    int iLoopTmp = 0;
    int iLenOfSrc = strlen ( s );
    int iLenOfTag = strlen ( t );
    int * UsefullPosition = malloc ( 2*(iLenOfSrc + 1) * sizeof (int) );
    int * TmpPosition = malloc ( 2*(iLenOfSrc + 1) * sizeof(int) );
     
    // M * N    
    //find first position in src string
    for ( iLoopSrc = 0; iLoopSrc < iLenOfSrc; iLoopSrc++ )
    {
        if ( s[iLoopSrc] == t[0])
        {
            UsefullPosition[2*UsefullLen+1] = iLoopSrc;
            UsefullPosition[2*UsefullLen] = 1;
            UsefullLen++;
            UsefullNum++;
        }
    }

    // do M * N check 
    for ( ;iLoopTag < iLenOfTag; iLoopTag++ )
    {

        if ( UsefullNum == 0 )
        {
            return 0;
        }
        TmpLen = UsefullLen;
        TmpNum = UsefullNum;

        //Get Num
        memcpy ( TmpPosition, UsefullPosition, 2 * TmpLen * sizeof(int));
        UsefullLen = 0;
        UsefullNum = 0;

        for ( iLoopSrc = 0; iLoopSrc < iLenOfSrc; iLoopSrc++ )
        {
            if ( s[iLoopSrc] == t[iLoopTag] )
            {
                //add num to UsefullPosition
                if ( iLoopSrc <= TmpPosition[1] )
                {
                    continue;
                }
                else if ( iLoopSrc <= TmpPosition[2*TmpLen-1] )
                {
                    UsefullPosition[ 2*UsefullLen ] = 0;
                    // during the position 
                    for ( iLoopTmp = 0; iLoopTmp < TmpLen; iLoopTmp++ ) 
                    {
                        if ( iLoopSrc > TmpPosition[2*iLoopTmp+1] )
                        {
                            UsefullPosition[ 2*UsefullLen ] += TmpPosition[2*iLoopTmp];
                            UsefullNum += TmpPosition[2*iLoopTmp];
                        }
                        else
                        {
                            break;
                        }
                    }
                    if ( UsefullPosition[ 2*UsefullLen ] > 0 )
                    {
                        UsefullPosition[ 2*UsefullLen + 1 ] = iLoopSrc;
                        UsefullLen++;
                    }
                }
                else
                {
                    UsefullPosition[ 2*UsefullLen ] = 0;
                    UsefullPosition[ 2*UsefullLen ] += TmpNum;
                    UsefullNum += TmpNum;
                    UsefullPosition[ 2*UsefullLen + 1 ] = iLoopSrc;
                    UsefullLen++;
                }
            }
        }
    }
    return UsefullNum;
}

int main()
{
    int res;
    res = numDistinct("rarabbbit", "rabbit");
    printf ( "%d\n", res );
    return 0;
}
