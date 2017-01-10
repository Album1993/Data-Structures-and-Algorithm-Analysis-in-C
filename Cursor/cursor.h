//
// Created by 张一鸣 on 2017/1/9.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_CURSOR_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_CURSOR_H

typedef int ElementType;
#define SpaceSize 100

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace( void );

List MakeEmpty_cur( List L );
int IsEmpty_cur( const List L );
int IsLast_cur( const Position P, const List L );
Position Find_cur( ElementType X, const List L );
void Delete_cur( ElementType X, List L );
Position FindPrevious_cur( ElementType X, const List L );
void Insert_cur( ElementType X, List L, Position P );
void DeleteList_cur( List L );
Position Header_cur( const List L );
Position First_cur( const List L );
Position Advance_cur( const Position P );
ElementType Retrieve_cur( const Position P );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_CURSOR_H
