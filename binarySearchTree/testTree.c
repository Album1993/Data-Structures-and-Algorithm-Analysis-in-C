//
// Created by 张一鸣 on 2017/1/10.
//

#include "testTree.h"
#include "tree.h"
#include <stdio.h>

int testtree( )
{
    SearchTree_tree T;
    Position_tree P;
    int i;
    int j = 0;

    T = MakeEmpty_tree( NULL );
    for( i = 0; i < 50; i++, j = ( j + 7 ) % 50 )
        T = Insert_tree( j, T );
    for( i = 0; i < 50; i++ )
        if( ( P = Find_tree( i, T ) ) == NULL || Retrieve_tree( P ) != i )
            printf( "Error at %d\n", i );

    for( i = 0; i < 50; i += 2 )
        T = Delete_tree( i, T );

    for( i = 1; i < 50; i += 2 )
        if( ( P = Find_tree( i, T ) ) == NULL || Retrieve_tree( P ) != i )
            printf( "Error at %d\n", i );
    for( i = 0; i < 50; i += 2 )
        if( ( P = Find_tree( i, T ) ) != NULL )
            printf( "Error at %d\n", i );

    printf( "Min is %d, Max is %d\n", Retrieve_tree( FindMin_tree( T ) ),
            Retrieve_tree( FindMax_tree( T ) ) );

    return 0;
}
