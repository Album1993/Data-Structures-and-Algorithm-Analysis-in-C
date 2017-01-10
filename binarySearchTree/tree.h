//
// Created by 张一鸣 on 2017/1/10.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_TREE_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_TREE_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position_tree;
typedef struct TreeNode *SearchTree_tree;

SearchTree_tree MakeEmpty_tree( SearchTree_tree T );
Position_tree Find_tree( ElementType X, SearchTree_tree T );
Position_tree FindMin_tree( SearchTree_tree T );
Position_tree FindMax_tree( SearchTree_tree T );
SearchTree_tree Insert_tree( ElementType X, SearchTree_tree T );
SearchTree_tree Delete_tree( ElementType X, SearchTree_tree T );
ElementType Retrieve_tree( Position_tree P );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_TREE_H
