#include "matrix.h"

#ifndef _PAIR_
#define _PAIR_
struct pair{
    int l,c;
};


struct pair * consPair ( int l, int c );

struct pair * cpyPair ( struct pair * P );

void freePair ( struct pair * P );

int pair2ind ( struct pair * p, struct matrix * M );

struct pair * ind2pair ( int k, struct matrix * M );

#endif//_PAIR_