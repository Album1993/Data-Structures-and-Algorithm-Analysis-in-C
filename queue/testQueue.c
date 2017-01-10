//
// Created by 张一鸣 on 2017/1/10.
//

#include "testQueue.h"
#include <stdio.h>
#include "queue.h"

int testqueue( )
{
    Queue Q;
    int i;

    Q = CreateQueue_queue( 12 );

    for( i = 0; i < 10; i++ )
        Enqueue_queue( i, Q );

    while( !IsEmpty_queue( Q ) )
    {
        printf( "%d\n", Front_queue( Q ) );
        Dequeue_queue( Q );
    }
    for( i = 0; i < 10; i++ )
        Enqueue_queue( i, Q );

    while( !IsEmpty_queue( Q ) )
    {
        printf( "%d\n", Front_queue( Q ) );
        Dequeue_queue( Q );
    }

    DisposeQueue_queue( Q );
    return 0;
}