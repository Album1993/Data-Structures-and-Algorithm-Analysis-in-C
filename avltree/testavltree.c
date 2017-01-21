//
// Created by 张一鸣 on 2017/1/11.
//

#include "testavltree.h"
#include "avltree.h"
#include <stdio.h>

void testavltree() {
    AvlTree_avl T;
    Position_avl P;
    int i;
    int j = 0;

    T = MakeEmpty_avl( NULL );
    for( i = 0; i < 50; i++, j = ( j + 7 ) % 50 )
        T = Insert_avl( j, T );
    for( i = 0; i < 50; i++ )
        if( ( P = Find_avl( i, T ) ) == NULL || Retrieve_avl( P ) != i )
            printf( "Error at %d\n", i );

    /* for( i = 0; i < 50; i += 2 )
           T = Delete( i, T );

       for( i = 1; i < 50; i += 2 )
           if( ( P = Find( i, T ) ) == NULL || Retrieve( P ) != i )
               printf( "Error at %d\n", i );
       for( i = 0; i < 50; i += 2 )
           if( ( P = Find( i, T ) ) != NULL )
               printf( "Error at %d\n", i );
   */
    printf( "Min is %d, Max is %d\n", Retrieve_avl( FindMin_avl( T ) ),
            Retrieve_avl( FindMax_avl( T ) ) );

}