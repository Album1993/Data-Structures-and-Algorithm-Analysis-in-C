//
// Created by 张一鸣 on 2017/1/13.
//

#include "hashfunc.h"
typedef unsigned int Index;

static Index Hash(const char * key, int TableSize) {
    unsigned int HashVal = 0;
    while ( * key != '\0')
        HashVal += *key ++;
    return HashVal % TableSize;
}

static Index Hash2(const char * Key,int TableSize) {
    return (Index)(Key[0] + 27 * Key[1] + 729 * Key[2]) % TableSize;
}

static Index Hash3(const char * Key,int TableSize) {
    unsigned  int HashVal = 0;
    while (*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % TableSize;
}