//
// Created by 张一鸣 on 2017/1/19.
//

#include "testleftheap.h"
#include <stdio.h>
#include "leftheap.h"

#define MaxSize 5000

void testleftheap() {
    PriorityQueue_lefttree H;
    int i, j;

    H = Initialize_leftheap( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+17)%MaxSize )
    {
        Insert_leftheap( j, H );
    }

    j = 0;
    while( !IsEmpty_leftheap( H ) )
    {
        if( FindMin_leftheap( H ) != j++ )
            printf( "Error in DeleteMin, %d\n", j );
        else
            H = DeleteMin1_leftheap( H );
    }
    printf( "Done...\n" );
}