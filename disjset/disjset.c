//
// Created by 张一鸣 on 2017/2/6.
//

#include <stdio.h>
#include "disjset.h"

void DisjSet_Initialize (DisjSet S)
{
  int i;

  for (i = NumSets; i > 0; i--)
    {
      S[i] = 0;
    }
}

//#ifdef SlowAlg

void DisjSet_SetUnion (DisjSet S, Disjset_SetType Root1, Disjset_SetType Root2)
{
  S[Root2] = Root1;
}

Disjset_SetType DisjSet_Find (Disjset_ElementType X, DisjSet S)
{
  if (S[X] <= 0)
    return X;
  else
    return DisjSet_Find (S[X], S);
}

//#else
//
//void DisjSet_SetUnion (DisjSet S, Disjset_SetType Root1, Disjset_SetType Root2)
//{
//  if (S[Root2] < S[Root1])
//    S[Root1] = Root2;
//  else
//    {
//      if (S[Root1] == S[Root2])
//        S[Root1]--;
//      S[Root2] = Root1;
//    }
//}
//
//Disjset_SetType DisjSet_Find (Disjset_ElementType X, DisjSet S)
//{
//  if (S[X]<=0)
//    return X;
//  else
//    return S[X] = DisjSet_Find (S[X],S);
//}
//
//
//#endif

void testDisjSet () {
  DisjSet S;
  int i,j,k,Set1,Set2;

  DisjSet_Initialize (S);
  j=k=1;
  while ( k<=8) {
      j = 1;
      while ( j < NumSets) {
          Set1 = DisjSet_Find (j,S);
          Set2 = DisjSet_Find (j+k,S);
          DisjSet_SetUnion (S,Set1,Set2);
          j += 2 * k;
        }
      k *= 2;
    }
  i = 1;
  for (i = 1; i <= NumSets ; i++)
    {
      Set1 = DisjSet_Find (i,S);
      printf ("%d**",Set1);
    }
  printf ("\n");
  return;
}
