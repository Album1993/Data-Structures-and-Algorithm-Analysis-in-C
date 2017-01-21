//
// Created by 张一鸣 on 2017/1/13.
//

#include "hashsep.h"
#include "../fatal.h"
#include <stdlib.h>

#define MinTableSize (10)

struct ListNode
{
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl{
    int TableSize;
    List * TheLists;
};

// 求素数的
static int NextPrime ( int N ) {
    int i;

    if ( N % 2 == 0)
        N++;
    for (; ; N += 2) {
        for (i = 3; i * i <= N; i += 2) {
            if (N % i == 0)
                goto ContOuter;
        }
        return N;
        ContOuter: ;
    }
}

Index Hash(ElementType key, int TableSize) {
    return (Index)key % TableSize;
}

HashTable InitializeTable_hash( int TableSize ) {
    HashTable H;
    int i;

    if (TableSize < MinTableSize) {
        Error( "Table size too small" );
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));

    H->TableSize = NextPrime(TableSize);

    H->TheLists = malloc(sizeof( List) * H->TableSize);

    if (H == NULL)
        FatalError( "Out of space!!!" );

    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError( "Out of space!!!" );
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

void DestroyTable_hash( HashTable H ) {
    int i;
    for (i = 0; i < H->TableSize; i++) {
        Position P = H->TheLists[i];
        Position Tmp;

        while (P != NULL)
        {
            Tmp = P->Next;
            free(P);
            P = Tmp;
        }
    }

    free(H->TheLists);
    free(H);

}

Position Find_hash( ElementType Key, HashTable H ) {
    Position p ;
    List L;

    L = H->TheLists[Hash(Key,H->TableSize)];
    p = L->Next;

    while (p != NULL && p->Element != Key)
        p = p->Next;
    return p;
}

void Insert_hash( ElementType Key, HashTable H ) {
    Position Pos,NewCell;
    List L;

    Pos = Find_hash(Key,H);
    if (Pos == NULL) {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError( "Out of space!!!" );
        else
        {
            L = H->TheLists[Hash(Key,H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}

ElementType Retrieve_hash( Position P ) {
    return P->Element;
}


