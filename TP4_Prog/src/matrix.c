#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "pair.h"
#include "matrix.h"

struct matrix * consMatrix ( int n, int m )
{
    struct matrix *mat=(struct matrix*)calloc(1,sizeof(struct matrix));
    mat->m=m;
    mat->n=n;
    mat->values=(double*)calloc(m*n,sizeof(double));
    return mat;
}

struct matrix * cpyMatrix ( struct matrix * M )
{
    struct matrix *Mcpy=consMatrix(M->n,M->m);
    return Mcpy;
}

void freeMatrix (struct matrix ** M)
{
    free(M);
    M=NULL;
}

void viewMatrix (struct matrix * M,char *entete)
{
    int i,j;
    printf("\n%s =\n",entete);
    for ( i = 0; i < M->m; i++)
    {
        for ( j = 0; j < M->n; j++)
        {
            printf("\t%.2lf",M->values[pair2ind(consPair(i,j),M)]);
        }
        printf("\n");
    }
}

struct matrix * scanMatrix ()
{
    int n,m,i;
    printf("Combien de colonne dans la Matrice ?\n");
    scanf("%d",&n);
    printf("Combien de lignes dans la Matrice ?\n");
    scanf("%d",&m);
    struct matrix *M=consMatrix(n,m);
    for ( i = 0; i < m*n; i++)
    {
        printf("(%d,%d)=",i/n+1,i%n+1);
        scanf("%lf",&M->values[i]);
    }
    return M;
}

struct matrix * addMatrix ( struct matrix * A, struct matrix * B )
{
    int i;
    struct matrix *res=consMatrix(A->n,A->m);
    for ( i = 0; i < A->m*A->n; i++)
    {   
        res->values[i]=A->values[i]+B->values[i];
    }
    return res;
}

struct matrix * multMatrix ( struct matrix * A, struct matrix * B )
{
    int i,j,k;
    struct matrix *res=consMatrix(A->m,B->n);

    for ( i = 0; i < res->m; i++)
    {
        for ( j = 0; j < res->n; j++)
        {
            for ( k = 0; k < B->m; k++)
            {
                res->values[pair2ind(consPair(i,j),res)]+=A->values[pair2ind(consPair(i,k),A)]*B->values[pair2ind(consPair(k,j),B)];
            }
            
        }
        
    }
    return res;
}

struct matrix * matrixInput ( char * filename )
{
    int l,c,i,j;
    FILE *F=fopen(filename,"r");
    assert(F!=NULL);
    fscanf(F,"%d %d\n",&l,&c);
    struct matrix *res=consMatrix(c,l);
    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < c; j++)
        {
            fscanf(F,"%lf ",&res->values[pair2ind(consPair(i,j),res)]);
        }
        fscanf(F,"\n");
    }
    return res;
}