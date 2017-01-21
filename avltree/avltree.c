//
// Created by 张一鸣 on 2017/1/11.
//

#include "avltree.h"
#include "../fatal.h"
#include <stdlib.h>

struct AvlNode
{
    ElementType Element;
    AvlTree_avl Left;
    AvlTree_avl Right;
    int Height;
};

AvlTree_avl MakeEmpty_avl( AvlTree_avl T ) {
    if (T != NULL)
    {
        MakeEmpty_avl(T->Left);
        MakeEmpty_avl(T->Right);
        free(T);
    }
    return NULL;
}

Position_avl Find_avl( ElementType X, AvlTree_avl T ) {
    if ( T == NULL )
        return NULL;
    if (X < T->Element)
        return Find_avl(X,T->Left);
    else if (X > T->Element)
        return Find_avl(X,T->Right);
    else
        return T;
}

Position_avl FindMin_avl( AvlTree_avl T ) {
    if (T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin_avl(T->Left);
}

Position_avl FindMax_avl( AvlTree_avl T ) {
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

static int Height_avl(Position_avl P) {
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

static int Max_avl( int Lhs , int RHS) {
    return Lhs > RHS ? Lhs : RHS;
}

static Position_avl SingleRotateWithLeft_avl (Position_avl K2) {
    Position_avl K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max_avl( Height_avl(K2->Left) , Height_avl(K2->Right)) + 1;
    K1->Height = Max_avl( Height_avl(K1->Left) , K2->Height) + 1;

    return K1;
}

static Position_avl SingleRotateWithRight_avl(Position_avl K1) {
    Position_avl  K2;

    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max_avl(Height_avl(K1->Left),Height_avl(K1->Right)) + 1;
    K2->Height = Max_avl(Height_avl(K2->Right),K1->Height) + 1;

    return K2;

}

static Position_avl DoubleRotateWithLeft_avl(Position_avl K3) {
    K3->Left = SingleRotateWithRight_avl(K3->Left);
    return SingleRotateWithLeft_avl(K3);
}

static Position_avl DoubleRotateWithRight_avl(Position_avl K3) {
    K3->Right = SingleRotateWithLeft_avl(K3->Right);
    return SingleRotateWithRight_avl(K3);
}

AvlTree_avl Insert_avl( ElementType X, AvlTree_avl T ) {
    if (T == NULL)
    {
        T = malloc(sizeof(struct AvlNode));
        if (T == NULL)
            FatalError("out of space !!!");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if ( X < T->Element) {
        T->Left = Insert_avl(X,T->Left);
        if (Height_avl(T->Left) - Height_avl(T->Right) == 2) {
            if (X < T->Left->Element) {
                T = SingleRotateWithLeft_avl(T);
            } else {
                T = DoubleRotateWithLeft_avl(T);
            }
        }
    }
    else if (X > T->Element) {
        T->Right = Insert_avl(X,T->Right);
        if (Height_avl(T->Right)- Height_avl(T->Left) == 2){
            if (X > T->Right->Element)
                T = SingleRotateWithRight_avl(T);
            else
                T = DoubleRotateWithRight_avl(T);

        }
    }

    T->Height = Max_avl(Height_avl(T->Left),Height_avl(T->Right)) + 1;
    return T;
}

AvlTree_avl Delete_avl( ElementType X, AvlTree_avl T )
{
    printf( "Sorry; Delete is unimplemented; %d remains\n", X );
    return T;
}

ElementType Retrieve_avl( Position_avl P ) {
    return P->Element;
}
