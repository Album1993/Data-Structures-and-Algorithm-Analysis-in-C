//
// Created by 张一鸣 on 2017/1/13.
//

#include "hashquad.h"
#include "../fatal.h"
#include <stdlib.h>

#define MinTableSize (10)

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry
{
    ElementType      Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

/* Cell *TheCells will be an array of */
/* HashEntry cells, allocated later */
struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};


static int
NextPrime( int N )
{
    int i;

    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 )
    {
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
        return N;
        ContOuter: ;
    }
}

Index Hash_hashquad (ElementType Key, int TableSize) {
    return Key % TableSize;
}

HashTable InitializeTable_hashquad( int TableSize ) {
    HashTable H;
    int i;

    if (TableSize < MinTableSize)
    {
        Error( "Table size too small" );
        return NULL;
    }

    H = malloc(sizeof( struct HashTbl));
    if (H == NULL)
        FatalError( "Out of space!!!" );

    H->TableSize = NextPrime(TableSize);

    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL)
        FatalError( "Out of space!!!" );

    for (i = 0; i < H->TableSize; i++) {
        H->TheCells[i].Info = Empty;
    }
    return H;

}

void DestroyTable_hashquad( HashTable H ) {
    free(H->TheCells);
    free(H);
}

Position Find_hashquad( ElementType Key, HashTable H ) {
    Position CurrentPos;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPos = Hash_hashquad(Key,H->TableSize);
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos += 2 * ++ CollisionNum - 1;
        if (CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert_hashquad( ElementType Key, HashTable H ) {
    Position Pos;

    Pos = Find_hashquad(Key,H);
    if (H->TheCells[Pos].Info != Legitimate)
    {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

ElementType Retrieve_hashquad( Position P, HashTable H ) {
    return H->TheCells[P].Element;
}

HashTable Rehash_hashquand( HashTable H ){
    int i,OldSize;
    Cell *OldCells;
    OldCells = H->TheCells;
    OldSize = H->TableSize;

    H = InitializeTable_hashquad(2 * OldSize);

    for (i = 0; i < OldSize; i++) {
        if (OldCells [i].Info == Legitimate)
            Insert_hashquad(OldCells[i].Element,H);
    }
    free(OldCells);
    return H;
}