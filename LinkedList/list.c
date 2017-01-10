//
// Created by 张一鸣 on 2017/1/6.
//

#include "list.h"

#include <stdlib.h>
#include "../fatal.h"

struct Node
{
    ElementType ELement;
    Position Next;
};


List MakeEmpty( List L ) {
    if (L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("out of memory");
    L->Next = NULL;
    return L;
}

int IsEmpty( List L ) {
    return L->Next == NULL;
}

int IsLast( Position P, List L ) {
    return P->Next == NULL;
}

Position Find( ElementType X, List L ) {
    Position p;

    p = L->Next;
    while(p != NULL && p->ELement != X) {
        p = p->Next;
    }
    return p;
}

void Delete( ElementType X, List L ) {
    Position  p ,tmp;
    p = FindPrevious(X,L);

    if (!IsLast(p,L)) {
        tmp = p->Next;
        p->Next = tmp->Next;
        free(tmp);
    }
}

Position FindPrevious( ElementType X, List L ) {
    Position p;
    p = L;
    while (p->Next != NULL && p->Next->ELement != X) {
        p = p->Next;
    }
    return p;
}

void Insert( ElementType X, List L, Position P ) {
    Position tmpCell;
    tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL)
        FatalError("out of space!!!");
    tmpCell->Next = P->Next;
    tmpCell->ELement = X;
    P->Next = tmpCell;
}

void DeleteList( List L ) {
    Position p,tmp;
    p = L->Next;
    if (p != NULL) {
        tmp = p;
        p = p->Next;
        free(tmp);
    }
}

Position Header( List L ) {
    return L;
}

Position First( List L ) {
    return L->Next;
}

Position Advance( Position P ) {
    return P->Next;
}

ElementType Retrieve( Position P ) {
    return P->ELement;
}



