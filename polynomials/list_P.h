//
// Created by 张一鸣 on 2017/1/6.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_LIST_P_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_LIST_P_H

struct Node;
typedef struct Node *PtrToNode;
struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty_P( List L );
int IsEmpty_P( List L );
int IsLast_P( Position P, List L );
void Insert_P( PtrToNode X, List L, Position P );
void DeleteList_P( List L );
Position Header_P( List L );
Position First_P( List L );
Position Advance_P( Position P );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_LIST_P_H
