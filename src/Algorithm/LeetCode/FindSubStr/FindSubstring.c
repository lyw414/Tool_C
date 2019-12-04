#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize)
{
    int StrLen = strlen(words[0]);
    int LenOfs = strlen ( s );
    int maxSize = LenOfs - wordsSize * StrLen + 1;
    int maxChildStrSize = strlen ( s ) - StrLen + 3;
    int count = 0;
    int iLoop1 = 0;
    int iLoop2 = 0;
    int iLoop3 = 0;
    int iLoop4 = 0;
    int iLoop5 = 0;
    int tmp = 0;
    *returnSize = 0;
    unsigned int beginAddr;
    
    unsigned int * res = ( unsigned int *) malloc ( sizeof (unsigned int ) * maxSize );
    unsigned int * childStrArray = ( unsigned int *) malloc ( sizeof (unsigned int ) * wordsSize * maxChildStrSize );
    unsigned int * EndIndexArray = ( unsigned int *) malloc ( sizeof (unsigned int ) * maxChildStrSize * 2 );
    
    // get all childstr location and can use kmp, use simple childstr find
    for ( iLoop1 = 0; iLoop1 < wordsSize; iLoop1 ++ )
    {
        //check has do it 
        for ( iLoop5 = 0; iLoop5 < iLoop1; iLoop5 ++ )
        {
            if ( memcmp ( words[iLoop5],words[iLoop1],StrLen) == 0 )
            {
                memcpy ( childStrArray + iLoop1 * maxChildStrSize, childStrArray + iLoop5 * maxChildStrSize,maxChildStrSize * sizeof(unsigned int) );
                break;
            }
        }
        if ( iLoop5 != iLoop1 )
        {
            continue;
        }
        childStrArray[iLoop1 * maxChildStrSize] = 0;
        iLoop3 = 0;
        for ( iLoop2 = 0; iLoop2 <  LenOfs; iLoop2++ )
        {
            if ( s[iLoop2] != words[iLoop1][iLoop3] )
            {
                iLoop2 = iLoop2 - iLoop3;
                iLoop3 = 0;
                continue;
            }
            else
            {
                iLoop3++;
                if ( iLoop3 == StrLen )
                {
                    //find child Str
                    childStrArray[iLoop1 * maxChildStrSize]++;
                    childStrArray[iLoop1 * maxChildStrSize + childStrArray[iLoop1*maxChildStrSize]] = iLoop2;
                    iLoop3 = 0;
                    
                    //record all end Index
                    for ( iLoop4 = 0; iLoop4 < count; iLoop4++ )
                    {
                        if ( EndIndexArray[iLoop4*2] == iLoop2 )
                        {
                            break;
                        }
                    }

                    if ( iLoop4 == count && iLoop2 < maxSize + StrLen)
                    {
                        EndIndexArray[iLoop4*2] = iLoop2;
                        EndIndexArray[iLoop4*2+1] = iLoop1;
                        count++;
                    }
                    iLoop2 = iLoop2 - StrLen + 1;
                }
            }
        }
    }

    // endIndex check
    for ( iLoop1 = 0; iLoop1 < count; iLoop1 ++ )
    {
        //set all check
        for ( iLoop2 = 0; iLoop2 < wordsSize; iLoop2++ )
        {
            childStrArray[ ( iLoop2 + 1)* maxChildStrSize - 1] = 1;
        }
        //childStrArray set not check
        childStrArray[(EndIndexArray[iLoop1*2 + 1] + 1)* maxChildStrSize - 1] = 0;
        //next Index
        tmp = iLoop4 = EndIndexArray[iLoop1*2] + StrLen;
        for ( iLoop2 = 0; iLoop2 < wordsSize - 1; iLoop2++ )
        {
            //find next Index
            //tmp = iLoop4 += StrLen;
            for ( iLoop3 = 0; iLoop3 < wordsSize; iLoop3++ )
            {
                beginAddr = iLoop3 * maxChildStrSize;
                if ( childStrArray[ beginAddr + maxChildStrSize - 1] == 1 )
                {
                    for ( iLoop5 = 0; iLoop5 < childStrArray[beginAddr]; iLoop5++ )
                    {

                        if ( childStrArray[beginAddr + iLoop5 + 1 ] < iLoop4 )
                        {
                            continue;
                        }
                        else if ( childStrArray[beginAddr + iLoop5 + 1 ] == iLoop4 )
                        {
                            tmp += StrLen;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    } 
                }
                else
                {
                    continue;
                }

                if ( tmp != iLoop4 )
                {
                    //iLoop4 = tmp;
                    childStrArray[ beginAddr +  maxChildStrSize - 1] = 0;
                    break;
                }
            }

            if ( tmp != iLoop4 )
            {
               iLoop4 = tmp;
               //not found
            }
            else
            {
                break;
            }
        }

        if ( iLoop2 == wordsSize - 1 )
        {
            //found one
            res[*returnSize] = EndIndexArray[iLoop1*2] - StrLen + 1;
            (*returnSize)++;
        }

    }
    printf("OK\n");
    return res;
}

int main()
{
    char * s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
    char *words[] = {"ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba"};

    int * z = NULL;
    int  res ;
    int iLoop = 0;
    z = findSubstring(s, words, 200, &res);

    printf ("%d\n",res);
    for ( iLoop = 0; iLoop < res; iLoop++ )
    {
        printf ("%d ",z[iLoop]);
    }
    printf ("\n");
    return 0;
}

