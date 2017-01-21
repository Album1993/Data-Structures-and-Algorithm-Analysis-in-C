//
// Created by 张一鸣 on 2017/1/16.
//

#include "leftheap.h"
#include "../fatal.h"
#include <stdlib.h>

struct TreeNode_lefttree
{
    ElementType Element;
    PriorityQueue_lefttree Left;
    PriorityQueue_lefttree Right;
    int Npl;
};

PriorityQueue_lefttree Initialize_leftheap( void ) {
    return NULL;
}

static PriorityQueue_lefttree Merge1_leftheap(PriorityQueue_lefttree H1,PriorityQueue_lefttree H2);

ElementType FindMin_leftheap( PriorityQueue_lefttree H ) {
    if (!IsEmpty_leftheap(H))
    {
        printf("find min:%d\n",H->Element);
        return H->Element;
    }
    Error( "Priority Queue is Empty" );
    return 0;
}

Boolean IsEmpty_leftheap( PriorityQueue_lefttree H ) {
    return H == NULL;
}

PriorityQueue_lefttree Merge_leftheap( PriorityQueue_lefttree H1, PriorityQueue_lefttree H2 ) {
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1_leftheap(H1,H2);
    else
        return Merge1_leftheap(H2,H1);
}

void SwapChildren_leftheap(PriorityQueue_lefttree H) {
    PriorityQueue_lefttree Tmp;
    Tmp = H->Left;
    H->Left = H->Right;
    H->Right = Tmp;
}

static PriorityQueue_lefttree Merge1_leftheap(PriorityQueue_lefttree H1,PriorityQueue_lefttree H2) {
    if (H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge_leftheap(H1->Right,H2);
        if  (H1->Left->Npl < H1->Right->Npl)
            SwapChildren_leftheap(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

#define Insert_leftheap( X, H ) ( H = Insert1_leftheap( ( X ), H ) )
/* DeleteMin macro is left as an exercise */

PriorityQueue_lefttree Insert1_leftheap( ElementType X, PriorityQueue_lefttree H ) {
    PriorityQueue_lefttree SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode_lefttree));
    if (SingleNode == NULL)
          FatalError( "Out of space!!!" );
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge_leftheap(SingleNode,H);
    }
    return H;

}

PriorityQueue_lefttree DeleteMin1_leftheap( PriorityQueue_lefttree H ) {
    PriorityQueue_lefttree LeftHeap,RightHeap;

    if(IsEmpty_leftheap(H))
    {
        Error( "Priority queue is empty" );
        return H;
    }

    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge1_leftheap(LeftHeap,RightHeap);
}