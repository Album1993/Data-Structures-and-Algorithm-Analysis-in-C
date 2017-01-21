//
// Created by 张一鸣 on 2017/1/13.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_HASHSEP_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_HASHSEP_H

typedef int ElementType;

typedef unsigned int Index;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable_hash( int TableSize );
void DestroyTable_hash( HashTable H );
Position Find_hash( ElementType Key, HashTable H );
void Insert_hash( ElementType Key, HashTable H );
ElementType Retrieve_hash( Position P );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_HASHSEP_H
