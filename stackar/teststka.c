//
// Created by 张一鸣 on 2017/1/9.
//

#include "teststka.h"
#include <stdio.h>
#include "stackar.h"

int testStka( )
{
    Stack S;
    int i;

    S = CreateStack_stka( 12 );
    for( i = 0; i < 10; i++ )
        Push_stka( i, S );

    while( !IsEmpty_stka( S ) )
    {
        printf( "%d\n", Top_stka( S ) );
        Pop_stka( S );
    }

    DisposeStack_stka( S );
    return 0;
}