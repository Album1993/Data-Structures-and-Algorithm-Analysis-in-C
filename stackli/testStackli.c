//
// Created by 张一鸣 on 2017/1/9.
//

#include "testStackli.h"
#include <stdio.h>
#include "stackli.h"

int teststackli( )
{
    PtrToNode_stali S;
    int i;

    S = CreateStack_stali( );
    for( i = 0; i < 10; i++ )
        Push_stali( i, S );

    while( !IsEmpty_stali( S ) )
    {
        printf( "%d\n", Top_stali( S ) );
        Pop_stali( S );
    }

    DisposeStack_stali( S );
    return 0;
}