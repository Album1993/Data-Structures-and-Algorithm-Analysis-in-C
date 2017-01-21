//
// Created by 张一鸣 on 2017/1/15.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_BINHEAP_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_BINHEAP_H

typedef int ElementType;

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize_binheap( int MaxElements );
void Destroy_binheap( PriorityQueue H );
void MakeEmpty_binheap( PriorityQueue H );
void Insert_binheap( ElementType X, PriorityQueue H );
ElementType DeleteMin_binheap( PriorityQueue H );
ElementType FindMin_binheap( PriorityQueue H );
int IsEmpty_binheap( PriorityQueue H );
int IsFull_binheap( PriorityQueue H );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_BINHEAP_H
