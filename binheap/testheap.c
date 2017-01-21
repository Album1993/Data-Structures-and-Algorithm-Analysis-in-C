//
// Created by 张一鸣 on 2017/1/16.
//

#include "testheap.h"
#include "binheap.h"
#include <stdio.h>

#define MaxSize (1000)

void testheap() {
    PriorityQueue H;
    int i, j;

    H = Initialize_binheap( MaxSize );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
        Insert_binheap( j, H );

    j = 0;
    while( !IsEmpty_binheap( H ) )
        if( DeleteMin_binheap( H ) != j++ )
            printf( "Error in DeleteMin, %d\n", j );
    printf( "Done...\n" );
    return ;
}