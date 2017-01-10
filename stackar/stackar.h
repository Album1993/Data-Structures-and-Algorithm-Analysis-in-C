//
// Created by 张一鸣 on 2017/1/9.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_STACKER_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_STACKER_H

typedef int ElementType;

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty_stka( Stack S );
int IsFull_stka( Stack S );
Stack CreateStack_stka( int MaxElements );
void DisposeStack_stka( Stack S );
void MakeEmpty_stka( Stack S );
void Push_stka( ElementType X, Stack S );
ElementType Top_stka( Stack S );
void Pop_stka( Stack S );
ElementType TopAndPop_stka( Stack S );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_STACKER_H
