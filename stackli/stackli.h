//
// Created by 张一鸣 on 2017/1/9.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_STACKLI_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_STACKLI_H

struct Node_stali;
typedef struct Node_stali * PtrToNode_stali;
typedef PtrToNode_stali Stack_stali;

typedef int ElementType;

int IsEmpty_stali( Stack_stali S );
Stack_stali CreateStack_stali( void );
void DisposeStack_stali( Stack_stali S );
void MakeEmpty_stali( Stack_stali S );
void Push_stali( ElementType X, Stack_stali S );
ElementType Top_stali( Stack_stali S );
void Pop_stali( Stack_stali S );


#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_STACKLI_H
