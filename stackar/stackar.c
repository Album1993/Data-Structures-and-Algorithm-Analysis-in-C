//
// Created by 张一鸣 on 2017/1/9.
//

#include "stackar.h"
#include "../fatal.h"
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord {
    int Capcaity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty_stka( Stack S ) {
    return S->TopOfStack == EmptyTOS;
}

int IsFull_stka( Stack S ) {
    return S->TopOfStack == S->Capcaity - 1;
}

Stack CreateStack_stka( int MaxElements ) {
    Stack S;

    if ( MaxElements < MinStackSize)
        Error( "Stack size is too small" );

    S = malloc(sizeof(struct StackRecord));
    if( S == NULL )
        FatalError( "Out of space!!!" );

    S->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( S->Array == NULL )
        FatalError( "Out of space!!!" );
    S->Capcaity = MaxElements;
    S->TopOfStack = EmptyTOS;
    MakeEmpty_stka(S);
    return S;
}

void DisposeStack_stka( Stack S ) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}

void MakeEmpty_stka( Stack S ) {
    S->Capcaity = EmptyTOS;
}

void Push_stka( ElementType X, Stack S ) {
    if (IsFull_stka(S))
        Error( "Full stack" );
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top_stka( Stack S ) {
    return S->Array[S->TopOfStack];
}

void Pop_stka( Stack S ) {
    if(IsEmpty_stka(S))
        Error( "Empty stack" );
    else
        S->TopOfStack--;
}

ElementType TopAndPop_stka( Stack S ) {
    if (!IsEmpty_stka(S))
        return S->Array[S->TopOfStack--];
    Error( "Empty stack" );
    return 0;
}