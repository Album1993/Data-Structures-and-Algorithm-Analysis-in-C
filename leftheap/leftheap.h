//
// Created by 张一鸣 on 2017/1/16.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_LEFTHEAP_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_LEFTHEAP_H

#include <MacTypes.h>

typedef int ElementType;

struct TreeNode_lefttree;
typedef struct TreeNode_lefttree *PriorityQueue_lefttree;

/* Minimal set of priority queue operations */
/* Note that nodes will be shared among several */
/* leftist heaps after a merge; the user must */
/* make sure to not use the old leftist heaps */

PriorityQueue_lefttree Initialize_leftheap( void );
ElementType FindMin_leftheap( PriorityQueue_lefttree H );
Boolean IsEmpty_leftheap( PriorityQueue_lefttree H );
PriorityQueue_lefttree Merge_leftheap( PriorityQueue_lefttree H1, PriorityQueue_lefttree H2 );

#define Insert_leftheap( X, H ) ( H = Insert1_leftheap( ( X ), H ) )
/* DeleteMin macro is left as an exercise */

PriorityQueue_lefttree Insert1_leftheap( ElementType X, PriorityQueue_lefttree H );
PriorityQueue_lefttree DeleteMin1_leftheap( PriorityQueue_lefttree H );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_LEFTHEAP_H
