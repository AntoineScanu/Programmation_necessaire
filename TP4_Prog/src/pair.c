#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "pair.h"
#include "matrix.h"

struct pair * consPair ( int l, int c )
{
    struct pair *pair=(struct pair *)calloc(1,sizeof(struct pair));
    pair->c=c;
    pair->l=l;
    return pair;
}

struct pair * cpyPair ( struct pair * P )
{
    struct pair *copy=consPair(P->l,P->c);
    return copy;
}

void freePair ( struct pair * P )
{
    free(P);
    P=NULL;
}

int pair2ind ( struct pair * p, struct matrix * M )
{
    return (p->l)*(M->n)+(p->c);
}

struct pair * ind2pair ( int k, struct matrix * M )
{
    struct pair *P=consPair(k/M->n,k%M->n);
    return P;
}