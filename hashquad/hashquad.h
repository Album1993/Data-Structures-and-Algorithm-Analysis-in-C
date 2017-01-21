//
// Created by 张一鸣 on 2017/1/13.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_HASHQUAD_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_HASHQUAD_H

typedef int ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable_hashquad( int TableSize );
void DestroyTable_hashquad( HashTable H );
Position Find_hashquad( ElementType Key, HashTable H );
void Insert_hashquad( ElementType Key, HashTable H );
ElementType Retrieve_hashquad( Position P, HashTable H );
HashTable Rehash_hashquand( HashTable H );
/* Routines such as Delete are MakeEmpty are omitted */


#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_HASHQUAD_H
