//
// Created by 张一鸣 on 2017/1/10.
//

#include "queue.h"
#include "../fatal.h"
#include <stdlib.h>

#define MinQueueSize ( 5 )

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType * array;
};

int IsEmpty_queue( Queue Q ) {
    return Q->Size == 0;
}

int IsFull_queue( Queue Q ) {
    return Q->Capacity == Q->Size;
}

Queue CreateQueue_queue( int MaxElements ) {
    Queue Q;

    if (MaxElements < MinQueueSize)
        Error("Queue size is too small");

    Q = malloc(sizeof(struct QueueRecord));

    if (Q == NULL)
        FatalError("out of space");

    Q->array = malloc(sizeof( ElementType ) * MaxElements);

    if (Q->array == NULL)
        FatalError("out of space");

    Q->Capacity = MaxElements;
    MakeEmpty_queue(Q);
    return Q;
}

void DisposeQueue_queue( Queue Q ) {
    if (Q != NULL) {
        free(Q->array);
        free(Q);
    }
}

void MakeEmpty_queue( Queue Q ) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int succ (int value,Queue Q) {
    if (++value > Q->Capacity - 1)
        return 0;
    else
        return value;
}

void Enqueue_queue( ElementType X, Queue Q ) {
    if (IsFull_queue(Q))
        Error( "Full queue" );
    else
    {
        Q->Size ++;
        Q->Rear = succ(Q->Rear,Q);
        Q->array[Q->Rear] = X;
    }
}

ElementType Front_queue( Queue Q ) {
    if(!IsEmpty_queue(Q))
        return Q->array[Q->Front];
    Error("empty queue");
    return 0;
}

void Dequeue_queue( Queue Q ) {
    if (!IsEmpty_queue(Q))
    {
        Q->Size--;
        Q->Front = succ(Q->Front,Q);
    } else {
        Error("empty Queue");
    }
}

ElementType FrontAndDequeue_queue( Queue Q ) {
    ElementType e = 0;
    if( IsEmpty_queue( Q ) )
        Error( "Empty queue" );
    else {
        e = Front_queue(Q);
        Dequeue_queue(Q);
    }
    return e;
}