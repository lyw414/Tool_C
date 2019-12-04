#include "Heap.h"

static int PopFront_For_Heap (struct _Heap * self, void * data );
static int PUshBack_For_Heap (struct _Heap * self, void * data );
static int Size_For_Heap (struct _Heap * self);
static int SinkDown_For_Heap (struct _Heap * self, size_t index );
static int FloatUp_For_Heap  (struct _Heap * self, size_t index );
static int Empty_For_Heap ( struct _Heap * self );

PHeap_st Create_Heap( size_t DataSize, size_t InitSize ,TCompare_Function_For_Heap compare_func)
{
    size_t iLoop = 0;
    if ( DataSize == 0 )
    {
        return NULL;
    }
    //Get Heap Pointor
    PHeap_st pHeap = malloc ( sizeof ( THeap_st ) );
    //Init Array
    if ( InitSize == 0 )
    {
        pHeap->DataArray = malloc ( sizeof ( void * ) * 1024 );
        pHeap->MaxSize = 1024;
    }
    else
    {
        pHeap->DataArray = malloc ( sizeof ( void * ) * InitSize );
        pHeap->MaxSize = InitSize;
    }
    //allocate Memery for eche Member 
    for ( iLoop = 0; iLoop < pHeap->MaxSize; iLoop++ )
    {
        pHeap->DataArray[iLoop] = malloc ( DataSize );
    }
    pHeap->Num = 0;
    pHeap->DataSize = DataSize;
    pHeap->compare_func = compare_func;
    //Init Fuction Pointor
    pHeap->PopFront = PopFront_For_Heap;
    pHeap->PushBack = PUshBack_For_Heap;
    pHeap->Size = Size_For_Heap;
    pHeap->SinkDown = SinkDown_For_Heap;
    pHeap->FloatUp = FloatUp_For_Heap;
    pHeap->Empty = Empty_For_Heap;
    return pHeap;
}


int Free_Heap( PHeap_st pHeap)
{
    size_t iLoop = 0;
    if ( pHeap != NULL ) 
    {
        for ( iLoop = 0; iLoop < pHeap->MaxSize ; iLoop++ ) 
        {
            free(pHeap->DataArray[iLoop]);
        }
        free ( pHeap->DataArray );
        free ( pHeap );
    }
    return 0;
}

int PopFront_For_Heap (struct _Heap * self, void * data )
{
    void * tmp;
    if ( self->Empty(self) == 1 )
    {
        return -2;
    }
    memcpy ( data,self->DataArray[0],self->DataSize);
    self -> Num --;
    
    if ( self->Empty(self) == 1 )
    {
        return 0;
    }
    else
    {
        tmp = self->DataArray[0];
        self->DataArray[0] = self->DataArray[self->Num];
        self->DataArray[self->Num] = tmp;
        self->SinkDown(self,0);
    }
    return 0;
}

int PUshBack_For_Heap (struct _Heap * self, void * data1 )
{
    self -> Num++;
    memcpy ( self -> DataArray[self->Num - 1],data1,self->DataSize );
    self->FloatUp ( self, self->Num - 1 );
    return 0;
}

int Size_For_Heap (struct _Heap * self)
{
    return self->Num;
}

int Empty_For_Heap ( struct _Heap * self )
{
    if ( self -> Num == 0 )
    {
       return 1; 
    }
    else
    {
        return 0;
    }
}

int FloatUp_For_Heap (struct _Heap * self, size_t index )
{
    size_t RootNodeIndex;
    size_t NextNodeIndex;
    void * tmp ;
    size_t DataIndex = index;
    
    tmp = self->DataArray[index];
    if ( self->Num == 0 )
    {
        return -2;
    }
    
    //only check rightchildnode exist once
    RootNodeIndex = DataIndex / 2;
    if ( DataIndex > 0 && DataIndex % 2 != 0 && DataIndex + 1 >= self->Num )
    {
        switch ( self->compare_func( self->DataArray[ RootNodeIndex ],tmp ) )
        {
            case 0 :
            case 2 :
                return 0;
            case 1 :
                self->DataArray[DataIndex] = self->DataArray[RootNodeIndex];
                DataIndex = RootNodeIndex;
                break;
            default :
                return -1;
        }
    }

    while ( 1 )
    {
        if ( DataIndex == 0 )
        {
            self->DataArray[DataIndex] = tmp;
            return 0;
        }

        RootNodeIndex = ( DataIndex - 1 ) / 2;
        if ( DataIndex % 2 == 0 )
        {
            NextNodeIndex = DataIndex - 1;
        }
        else
        {
            NextNodeIndex = DataIndex + 1;
        }

        switch ( self -> compare_func ( self->DataArray[ NextNodeIndex ],tmp ) )
        {
            case 0:
            case 2:
                self->DataArray[DataIndex] = tmp;
                return 0;
            case 1:
                switch ( self -> compare_func ( self->DataArray[ RootNodeIndex ],tmp ) )
                {
                    case 1:
                        self->DataArray[DataIndex] = self->DataArray[RootNodeIndex];
                        DataIndex = RootNodeIndex;
                        break;
                    case 0:
                    case 2:
                        self->DataArray[DataIndex] = tmp;
                        return 0;
                    default:
                        return -1;
                }
                break;
            default :
                return -1;
       }
    }
    return 0;

    //递归实现
    //void * tmp;
    //if ( index == 0 )
    //{
    //    return 0;
    //}
    //else
    //{
    //    if ( index % 2 == 0 )
    //    {
    //        LeftChildNodeIndex = index - 1;
    //        RightChildNodeINdex = index;

    //        switch ( self->compare_func ( DataArray[LeftChildNodeIndex],DataArray[RightChildNodeIndex] ) )
    //        {
    //            case 0 :
    //            case 1 :
    //                return 0
    //            case 2 :
    //                tmp = DataArray[RightChildNodeIndex];
    //                DataArray[LeftChildNodeIndex] = DataArray[RightChildNodeIndex];
    //                DataArray[LeftChildNodeIndex] = tmp;
    //                FloatUP_For_Heap (self, LeftChildNodeIndex);
    //        }
    //    }
    //    else
    //    {
    //        RootNodeIndex = ( index - 1 ) / 2;
    //        LeftChildNOde = index;
    //        switch ( self->compare_func ( DataArray[RootChildNodeIndex],DataArray[LeftChildNodeIndex] ) )
    //        {
    //            case 0 :
    //            case 2 :
    //                return 0
    //            case 1 :
    //                tmp = DataArray[LeftChildNodeIndex];
    //                DataArray[LeftChildNodeIndex] = DataArray[RootdNodeIndex];
    //                DataArray[RootNodeIndex] = tmp;
    //                FloatUP_For_Heap (self, RootNodeIndex);
    //        }
    //    }
    //}
}

int SinkDown_For_Heap  ( struct _Heap * self, size_t index )
{
    size_t LeftChildNodeIndex;
    size_t RightChildNodeIndex;
    size_t NextNodeIndex;
    void * tmp = self->DataArray[index];
    size_t DataIndex = index;
    if ( self -> Num == 0 )
    {
        return -2;
    }

    while ( 1 )
    {
        LeftChildNodeIndex = DataIndex * 2 + 1;
        RightChildNodeIndex = DataIndex * 2 + 2;
        if ( LeftChildNodeIndex >= self->Num )
        {
            self->DataArray[DataIndex] = tmp;
            return 0;
        }
        else if ( RightChildNodeIndex >= self->Num )
        {
            switch ( self -> compare_func ( self->DataArray[ LeftChildNodeIndex],tmp ) )
            {
                case 0 :
                case 1 :
                    self->DataArray[DataIndex] = tmp;
                    return 0;
                case 2 :
                    self->DataArray[DataIndex] = self->DataArray[LeftChildNodeIndex];
                    DataIndex = LeftChildNodeIndex;
                    break;
                default :
                    return -1;
            }
        }
        else
        {
            switch ( self -> compare_func ( self->DataArray[ LeftChildNodeIndex], self->DataArray[ RightChildNodeIndex]) )
            {
                case 0 :
                    NextNodeIndex = LeftChildNodeIndex;
                    break;
                case 1 :
                    NextNodeIndex = RightChildNodeIndex;
                    break;
                case 2 :    
                    NextNodeIndex = LeftChildNodeIndex;
                    break;
                default:
                    return -1;
            }

            switch ( self -> compare_func ( self->DataArray[ NextNodeIndex ],tmp ) )
            {
                    case 0 :
                    case 1 :
                        self->DataArray[DataIndex] = tmp;
                        return 0;
                    case 2 :
                        self->DataArray[DataIndex] = self->DataArray[NextNodeIndex];
                        DataIndex = NextNodeIndex;
                        break;
                    default :
                        return -1;
            }
        }

    }

    return 0;
}



