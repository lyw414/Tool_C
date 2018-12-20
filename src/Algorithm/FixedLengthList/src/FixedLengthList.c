#include "FixedLengthList.h"
bool init_for_FixedLengthList ( struct _fixed_length_list_info * self )
{
    int iLoop = 0;
    self -> dataArray = malloc ( ( self ->  totalSize + 2 ) * sizeof ( void * ) );
    for ( iLoop = 0; iLoop < ( self -> totalSize + 2 ); iLoop ++ )
    {
        self -> dataArray[iLoop] = malloc ( self -> data_size );
    }
    return true;
}

bool push_back_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value )
{
    if ( value == NULL )
    {

        UserError ( "in %s :: FixedLengthList [%s] pointor value is NULL",__func__,self -> szListName );
        return false;
    }
 
    if ( !self -> full ( self ) )         
    {
        //get end index 
        memcpy ( self -> dataArray [ self -> endIndex ], value, self -> data_size );
        self -> endIndex = ( self -> endIndex + 1 ) % ( self -> totalSize + 2 );
        return true;
    }
    else
    {
        //List is full
        UserError ( "in %s :: FixedLengthList [%s] is full!", __func__,self -> szListName );
        return false;
    }
}

bool get_back_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value )
{
    int tmpIndex = 0;
    if ( value == NULL )
    {
        UserError ( "in %s :: FixedLengthList [%s] pointor value is NULL",__func__,self -> szListName );
        return false;
    }
    
    if ( !self -> empty ( self ) )    
    {
        tmpIndex  = (self -> endIndex - 1 + self -> totalSize + 2 ) % ( self -> totalSize + 2 );
        memcpy ( value, self -> dataArray [ tmpIndex ], self -> data_size );
        return true;
    }
    else
    {
        UserError ( "in %s :: FixedLengthList [%s] is empty!", __func__,self -> szListName );
        return false ;
    }
    
}

bool pop_back_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value )
{
    if ( value == NULL )
    {
        UserError ( "in %s :: FixedLengthList [%s] pointor value is NULL",__func__,self -> szListName );
        return false;
    }
    
    if ( !self -> empty ( self ) )    
    {
        self -> endIndex = (self -> endIndex - 1 + self -> totalSize + 2 ) % ( self -> totalSize + 2 );
        memcpy ( value, self -> dataArray [ self -> endIndex ], self -> data_size );
        return true;
    }
    else
    {
        UserError ( "in %s :: FixedLengthList [%s] is empty!", __func__,self -> szListName );
        return false ;
    }
}

bool push_front_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value )
{
    if ( value == NULL )
    {
        UserError ( "in %s :: FixedLengthList [%s] pointor value is NULL",__func__,self -> szListName );
        return false;
    }
 
    if ( !self -> full ( self ) )         
    {
        //get head index 
        memcpy ( self -> dataArray [ self -> headIndex ], value, self -> data_size );
        self -> headIndex = ( self -> headIndex - 1  + self -> totalSize + 2 ) % ( self -> totalSize + 2 );
        return true;
    }
    else
    {
        //List is full
        UserError ( "in %s :: FixedLengthList [%s] is full!", __func__,self -> szListName );
        return false;
    }

}
bool get_front_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value )
{
    int tmpIndex = 0;
    if ( value == NULL )
    {
        UserError ( "in %s :: FixedLengthList [%s] pointor value is NULL",__func__,self -> szListName );
        return false;
    }
    
    if ( !self -> empty ( self ) )    
    {
        tmpIndex  = (self -> headIndex + 1 ) % ( self -> totalSize + 2 );
        memcpy ( value, self -> dataArray [ tmpIndex ], self -> data_size );
        return true;
    }
    else
    {
        UserError ( "in %s :: FixedLengthList [%s] is empty!", __func__,self -> szListName );
        return false ;
    }


}
bool pop_front_for_FixedLengthList ( struct _fixed_length_list_info * self, void * value )
{
    if ( value == NULL )
    {
        UserError ( "in %s :: FixedLengthList [%s] pointor value is NULL",__func__,self -> szListName );
        return false;
    }
    if ( !self -> empty ( self ) )    
    {
        self -> headIndex = (self -> headIndex + 1 ) % ( self -> totalSize + 2 );
        memcpy ( value, self -> dataArray [ self -> headIndex ], self -> data_size );
        return true;
    }
    else
    {
        UserError ( "in %s :: FixedLengthList [%s] is empty!", __func__,self -> szListName );
        return false ;
    }
}

bool full_for_FixedLengthList ( struct _fixed_length_list_info * self )
{
    if ( ( self -> endIndex + 1 ) % ( self->totalSize + 2 ) == self -> headIndex )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool empty_for_FixedLengthList ( struct _fixed_length_list_info * self )
{
    if ( ( self -> headIndex + 1 ) % ( self->totalSize + 2 ) == self -> endIndex )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool clear_for_FixedLengthList ( struct _fixed_length_list_info * self )
{
    int iLoop = 0;
    for ( iLoop = 0; iLoop < ( self -> totalSize + 2 ); iLoop ++ )
    {
        memset ( self -> dataArray[iLoop],0x00, self->data_size);
    }
    self -> headIndex = 0;
    self -> endIndex = 1;
    return true;
}

int size_for_FixedLengthList ( struct _fixed_length_list_info * self )
{
    int size = 0;
    size = ( size = ( self -> endIndex - self -> headIndex ) ) > 0 ? size - 1 : size + 1 + self -> totalSize;
    return size;
}

bool free_for_FixedLengthList ( struct _fixed_length_list_info * self )
{
    int iLoop = 0;
    self -> dataArray = malloc ( ( self ->  totalSize + 2 ) * sizeof ( void * ) );
    for ( iLoop = 0; iLoop < ( self -> totalSize + 2 ); iLoop ++ )
    {
        free ( self -> dataArray[iLoop] );
    }
    free ( self -> dataArray );
    self -> dataArray = NULL;
    self -> data_size = 0;
    self -> headIndex = 0;
    self -> endIndex = 1;
    memset ( self -> szListName, 0x00, sizeof ( self -> szListName ) );
    return true;
}
