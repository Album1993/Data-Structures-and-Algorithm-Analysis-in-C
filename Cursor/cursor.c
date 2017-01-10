//
// Created by 张一鸣 on 2017/1/9.
//

#include "cursor.h"
#include <stdlib.h>
#include "../fatal.h"

struct Node {
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];

static Position CursorAlloc(void) {
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    return P;
}

static void CursorFree (Position P) {
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

void InitializeCursorSpace( void ) {
    int i;
    for (i = 0; i < SpaceSize; i++ ) {
        CursorSpace[i].Next = i+1;
    }
    CursorSpace[SpaceSize - 1].Next = 0;
}

List MakeEmpty_cur( List L ) {
    if (L != 0)
        DeleteList_cur(L);
    L = CursorAlloc();
    if (L == 0)
        FatalError("Out of memory!");
    CursorSpace[L].Next = 0;
    return L;
}

int IsEmpty_cur( const List L ) {
    return CursorSpace[L].Next == 0;
}

int IsLast_cur( const Position P, const List L ) {
    return CursorSpace[P].Next == 0;
}

Position Find_cur( ElementType X, const List L ) {
    Position P;

    P = CursorSpace[L].Next;

    while(P && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

void Delete_cur( ElementType X, List L ) {
    Position P,TmpCell;

    P = FindPrevious_cur(X,L);
    if (!IsLast_cur(L,P)) {
        Position TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

Position FindPrevious_cur( ElementType X, const List L ) {
    Position P;
    P = L;
    if (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;

    return P;
}

void Insert_cur( ElementType X, List L, Position P ) {
    Position TmpCell;
    TmpCell = CursorAlloc();
    if (TmpCell == 0)
        FatalError( "Out of space!!!" );
    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

void DeleteList_cur( List L ) {
    Position P,Tmp;
    P = CursorSpace[L].Next;
    CursorSpace[L].Next = 0;
    while (P != 0)
    {
        Tmp = CursorSpace[P].Next;
        CursorFree(P);
        P = Tmp;
    }
}

Position Header_cur( const List L ) {
    return L;
}

Position First_cur( const List L ) {
    return CursorSpace[L].Next;
}

Position Advance_cur( const Position P ) {
    return CursorSpace[P].Next;
}

ElementType Retrieve_cur( const Position P ) {
    return CursorSpace[P].Element;
}