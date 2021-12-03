#include<stdio.h>
#include<stdlib.h>
#include "pair.h"
#include "matrix.h"


int main(){
    struct matrix *A;
    struct matrix *B;
    struct matrix *C;

    A = scanMatrix();
    B = scanMatrix();

    viewMatrix(A,"A =");
    viewMatrix(B,"B =");

    printf("Addition de matrice : \n");
    C = addMatrix(A,B);
    viewMatrix(C,"A+B=");

    printf("Multiplication de matrice : \n");
    C = multMatrix(A,B);
    viewMatrix(C,"A*B=");
    return 0;
}