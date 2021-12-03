#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include"matrix.h"
#include"pair.h"

int main()
{
    int a;
    bool add=false,mult=false;
    //struct matrix *A=scanMatrix();
    //struct matrix *B=scanMatrix();
    struct matrix *A=matrixInput("data/A.txt");
    struct matrix *B=matrixInput("data/B.txt");
    viewMatrix(A,"A");
    viewMatrix(B,"B");
    if (A->m==B->m&&A->n==B->n)
    {
        add=true;
    }
    if (A->n==B->m)
    {
        mult=true;
    }
    if (add&&mult)
    {
        printf("\nQue voulez-vous faire de ces matrices ?\n  [1]\tadditionner\n  [2]\tmultiplier\n  [3]\tadditionner et multiplier\n");
        scanf("%d",&a);
    }
    if (add&&mult==false)
    {
        printf("\nLa seul opération possible est l'addition\n");
        a=1;
    }
    if (mult&&add==false)
    {
        printf("\nLa seul opération possible est la multiplication\n");
        a=2;
    }
    
    if (a==1||a==3)
    {
        viewMatrix(addMatrix(A,B),"A+B");
    }
    if (a==2||a==3)
    {
        viewMatrix(multMatrix(A,B),"AxB");
        viewMatrix(multMatrix(B,A),"BxA");
    }
	return EXIT_SUCCESS;
}