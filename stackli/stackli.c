//
// Created by 张一鸣 on 2017/1/9.
//

#include "stackli.h"
#include "../fatal.h"
#include <stdlib.h>

struct Node_stali
{
    ElementType Element;
    Stack_stali Next;
};


int IsEmpty_stali( Stack_stali S ) {
    return S->Next == NULL;
}

Stack_stali CreateStack_stali( void ) {
    Stack_stali S;
    S = malloc(sizeof(struct Node_stali));
    if (S == NULL)
        FatalError("out of space");
    S->Next = NULL;
    S->Element = 0;
    MakeEmpty_stali(S);
    return S;
}

void DisposeStack_stali( Stack_stali S ) {
    MakeEmpty_stali(S);
    free(S);
}

void MakeEmpty_stali( Stack_stali S ) {
    if (S == NULL)
        Error( "Must use CreateStack first" );
    else
        while (!IsEmpty_stali(S))
            Pop_stali(S);
}

void Push_stali( ElementType X, Stack_stali S ) {
    PtrToNode_stali tmpcell;
    tmpcell = malloc(sizeof(struct Node_stali));
    if( tmpcell == NULL )
        FatalError( "Out of space!!!" );
    else
    {
        tmpcell->Next = S->Next;
        tmpcell->Element = X;
        S->Next = tmpcell;
    }
}

ElementType Top_stali( Stack_stali S ) {
    if( !IsEmpty_stali( S ) )
        return S->Next->Element;
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}

void Pop_stali( Stack_stali S ) {
    PtrToNode_stali FirstCell;

    if( IsEmpty_stali( S ) )
        Error( "Empty stack" );
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free( FirstCell );
    }
}