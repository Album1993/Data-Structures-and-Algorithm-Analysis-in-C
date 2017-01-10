
#include <stdio.h>
#include "cursor.h"

void PrintList_cur( const List L )
{
    Position P = Header_cur( L );

    if( IsEmpty_cur( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance_cur( P );
            printf( "%d ", Retrieve_cur( P ) );
        } while( !IsLast_cur( P, L ) );
        printf( "\n" );
    }
}

void testcurs( )
{
    List L;
    Position P;
    int i;

    InitializeCursorSpace( );
    L = MakeEmpty_cur( 0 );
    P = Header_cur( L );
    PrintList_cur( L );

    for( i = 0; i < 10; i++ )
    {
        Insert_cur( i, L, P );
        PrintList_cur( L );
        P = Advance_cur( P );
    }
    for( i = 0; i < 10; i+= 2 )
        Delete_cur( i, L );

    for( i = 0; i < 10; i++ )
        if( ( i % 2 == 0 ) == ( Find_cur( i, L ) != 0 ) )
            printf( "Find fails\n" );

    printf( "Finished deletions\n" );

    PrintList_cur( L );

    DeleteList_cur( L );

    return ;
}