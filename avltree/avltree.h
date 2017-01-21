//
// Created by 张一鸣 on 2017/1/11.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_AVLTREE_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_AVLTREE_H

typedef int ElementType;

struct AvlNode;
typedef struct AvlNode *Position_avl;
typedef struct AvlNode *AvlTree_avl;

AvlTree_avl MakeEmpty_avl( AvlTree_avl T );
Position_avl Find_avl( ElementType X, AvlTree_avl T );
Position_avl FindMin_avl( AvlTree_avl T );
Position_avl FindMax_avl( AvlTree_avl T );
AvlTree_avl Insert_avl( ElementType X, AvlTree_avl T );
AvlTree_avl Delete_avl( ElementType X, AvlTree_avl T );
ElementType Retrieve_avl( Position_avl P );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_AVLTREE_H
