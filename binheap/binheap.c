//
// Created by 张一鸣 on 2017/1/15.
//

#include "binheap.h"
#include "../fatal.h"
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)

struct HeapStruct {
    int Capacity;
    int Size;
    ElementType * Elements;
};

PriorityQueue Initialize_binheap( int MaxElements ) {
    PriorityQueue H;

    if (MaxElements < MinPQSize)
        Error( "Priority queue size is too small" );

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError( "Out of space!!!" );

    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL)
        FatalError("out of space");

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    return H;
}

void Destroy_binheap( PriorityQueue H ) {
    free(H->Elements);
    free(H);
}

void MakeEmpty_binheap( PriorityQueue H ) {
    H->Size = 0;
}

void Insert_binheap( ElementType X, PriorityQueue H ) {
    int i;
    if (IsFull_binheap(H)) {
        Error( "Priority queue is full" );
        return;
    }
    for ( i = ++H->Size; H->Elements[i / 2] > X ; i /= 2) {
        H->Elements [i] = H->Elements[i / 2];
    }
    H->Elements[i] = X;
}

ElementType DeleteMin_binheap( PriorityQueue H ) {
    int i, Child;
    ElementType MinElement,LastElement;

    if (IsEmpty_binheap(H))
    {
        Error("Priority queue is empty");
        return H->Elements[H->Size--];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    for (i = 1; i * 2 <= H->Size ; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;

        if (LastElement > H->Elements[Child]) {
            H->Elements[i] = H->Elements[Child];
        } else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

ElementType FindMin_binheap( PriorityQueue H ) {
    if (!IsEmpty_binheap(H))
        return H->Elements[1];
    Error( "Priority Queue is Empty" );
    return H->Elements[0];
}

int IsEmpty_binheap( PriorityQueue H ) {
    return H->Size == 0;
}

int IsFull_binheap( PriorityQueue H ) {
    return H->Size == H->Capacity;
}