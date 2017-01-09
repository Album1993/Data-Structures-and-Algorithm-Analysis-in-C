//
// Created by 张一鸣 on 2017/1/6.
//

#include "list_P.h"

#include <stdlib.h>
#include "../fatal.h"


List MakeEmpty_P( List L ) {
    if (L != NULL)
        DeleteList_P(L);
    L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("out of memory");
    L->Next = NULL;
    return L;
}

int IsEmpty_P( List L ) {
    return L->Next == NULL;
}

int IsLast_P( Position P, List L ) {
    return P->Next == NULL;
}

void Insert_P( PtrToNode X, List L, Position P ) {
    Position tmpCell;
    tmpCell = malloc(sizeof(Position));
    if (tmpCell == NULL)
        FatalError("out of space!!!");
    tmpCell->Next = X->Next;
    tmpCell->Exponent = X->Exponent;
    tmpCell->Coefficient = X->Coefficient;
    P->Next = tmpCell;
}

void DeleteList_P( List L ) {
    Position p,tmp;
    p = L->Next;
    if (p != NULL) {
        tmp = p;
        p = p->Next;
        free(tmp);
    }
}

Position Header_P( List L ) {
    return L;
}

Position First_P( List L ) {
    return L->Next;
}

Position Advance_P( Position P ) {
    return P->Next;
}





