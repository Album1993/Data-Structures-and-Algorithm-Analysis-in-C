//
// Created by 张一鸣 on 2017/1/13.
//

#include "testhash.h"

//#ifdef SepChain
//#include "hashsep.h"
//#endif
//
//#ifdef QuadProb
#include "../hashquad/hashquad.h"
//#endif

#include <stdio.h>

#define NumItems 400

int testhash( )
{
    HashTable H;
    Position P;
    int i;
    int j = 0;
    int CurrentSize;

    H = InitializeTable_hashquad( CurrentSize = 13 );

    for( i = 0; i < NumItems; i++, j += 71 )
    {
//#ifdef QuadProb
        if( i > CurrentSize / 2 )
        {
            H = Rehash_hashquand( H );
            printf( "Rehashing...\n" );
            CurrentSize *= 2;
        }
//#endif
        Insert_hashquad( j, H );
    }

    for( i = 0, j = 0; i < NumItems; i++, j += 71 )
#ifdef SepChain
        if( ( P = Find_hash( j, H ) ) == NULL || Retrieve_hash( P ) != j )
#endif
//#ifdef QuadProb
        if( Retrieve_hashquad( ( P = Find_hashquad( j, H ) ), H ) != j )
//#endif
            printf( "Error at %d\n", j );

    printf( "End of program.\n" );
    return 0;
}