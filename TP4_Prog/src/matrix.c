#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"
#include "pair.h"

struct matrix * consMatrix ( int n, int m ){
    struct matrix *M = (struct matrix *) calloc (1,sizeof(struct matrix));

    M->values = (double *) calloc(n*m,sizeof(double));

    M->n = n;
    M->m = m;
    return M;
}

struct matrix * cpyMatrix ( struct matrix * M ){
    int i;
    struct matrix *M2 = consMatrix(M->n,M->m);
    M2->n = M->n;
    M2->m = M->m;

    for(i=0;i<(M->n)*(M->m);i++){
        M2->values[i] = M->values[i];
        
    }

    return M2;
}

void freeMatrix (struct matrix ** M){
    int i;

    for(i=0;i<((*M)->n)*((*M)->m);i++){
        free(*M);
    }

    *M = NULL;
}

void viewMatrix (struct matrix * M, char * entete ){
    int i;

    printf("Matrice : %s\n", entete);

    for(i=0;i<(M->n)*(M->m);i++){
        printf("|%f|",M->values[i]);
        if((i+1) % M->m == 0){
            printf("\n");
        }
    }
    printf("\n");

}

struct matrix * scanMatrix (){
    int i,n,m;

    printf("Donnez le nombre de lignes : ");
    scanf("%d",&(n));

    printf("Donnez le nombre de colonnes : ");
    scanf("%d",&(m));

    struct matrix *M = consMatrix(n,m);

    for(i=0;i<(M->n)*(M->m);i++){
        printf("A :");
        scanf("%lf",&(M->values[i]));
    }

    return M;

}

struct matrix * addMatrix ( struct matrix * A, struct matrix * B ){
    int i;
    struct matrix *Res = consMatrix(A->n,A->m);

    for(i=0;i<(A->n)*(A->m);i++){
        Res->values[i] = A->values[i] + B->values[i];
    }

    return Res;
}

struct matrix * multMatrix ( struct matrix * A, struct matrix * B ){

    struct matrix *C = consMatrix(A->n,B->m);

    for(int i = 0  ; i < C->n ; i++){

        for(int j = 0 ; j < C->m ; j++){
            struct pair *Pindij = consPair(i,j);
            int indij = pair2ind(Pindij,C);

            for(int k = 0; k < A->m ; k++){

                struct pair *Pindik = consPair(i,k);
                int indik = pair2ind(Pindik,A);

                struct pair *Pindkj = consPair(k,j);
                int indkj =  pair2ind(Pindkj,B);

                C->values[indij] += (A->values[indik]) * (B->values[indkj]);
            }
        }
    }
    return C;
}