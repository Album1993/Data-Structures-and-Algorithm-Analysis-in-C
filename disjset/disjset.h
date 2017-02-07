//
// Created by 张一鸣 on 2017/2/6.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_DISJSET_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_DISJSET_H

#define FastAlg

#define NumSets 128
typedef int DisjSet[ NumSets + 1 ];
typedef int Disjset_SetType;
typedef int Disjset_ElementType;

void DisjSet_Initialize( DisjSet S );
void DisjSet_SetUnion( DisjSet S, Disjset_SetType Root1, Disjset_SetType Root2 );
Disjset_SetType DisjSet_Find( Disjset_ElementType X, DisjSet S );


void testDisjSet ();
#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_DISJSET_H
