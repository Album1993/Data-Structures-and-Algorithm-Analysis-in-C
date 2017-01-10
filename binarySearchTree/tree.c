//
// Created by 张一鸣 on 2017/1/10.
//

#include "tree.h"
#include <stdlib.h>
#include "../fatal.h"

struct TreeNode {
    ElementType Element;
    SearchTree_tree left;
    SearchTree_tree right;
};

SearchTree_tree MakeEmpty_tree( SearchTree_tree T ) {
    if (T != NULL)
    {
        MakeEmpty_tree(T->left);
        MakeEmpty_tree(T->right);
        free(T);
    }
    return NULL;
}

Position_tree Find_tree( ElementType X, SearchTree_tree T ) {
    if(T != NULL) {
        if (X > T->Element) {
            return Find_tree(X,T->right);
        } else if (X < T->Element) {
            return Find_tree(X,T->left);
        } else {
            return T;
        }
    } else {
        return NULL;
    }
}

Position_tree FindMin_tree( SearchTree_tree T ) {
    if (T != NULL)
    {
        if (T->left != NULL)
            return FindMin_tree(T->left);
        else
            return T;
    }
    return NULL;
}

Position_tree FindMax_tree( SearchTree_tree T ) {
    if (T != NULL) {
        while (T->right != NULL)
            T = T->right;
    }
    return T;
}

SearchTree_tree Insert_tree( ElementType X, SearchTree_tree T ) {
    if (T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        if( T == NULL )
            FatalError( "Out of space!!!" );
        else
        {
            T->Element = X;
            T->left = NULL;
            T->right = NULL;
        }
    }
    else if (X < T->Element)
        T->left = Insert_tree(X,T->left);
    else if (X > T->Element)
        T->right = Insert_tree(X,T->right);
    return T;
}

SearchTree_tree Delete_tree( ElementType X, SearchTree_tree T ) {
    Position_tree Tmpcell;

    if (T == NULL) {
        Error( "Element not found" );
    } else if ( X < T->Element ) {
        T->left = Delete_tree(X,T->left);
    } else if ( X > T->Element) {
        T->right = Delete_tree(X,T->right);
    } else if ( T->left && T->right) {
        Tmpcell = FindMin_tree(T->right);
        T->Element = Tmpcell->Element;
        T->right = Delete_tree(T->Element,T->right);
    } else {
        Tmpcell = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        free(Tmpcell);
    }
    return T;
}

ElementType Retrieve_tree( Position_tree P ) {
    return P->Element;
}