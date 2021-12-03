#ifndef _MATRIX_
#define _MATRIX_

#include"pair.h"

struct matrix {
double * values;
int n, m;
};

//@brief Alloue la mémoire et initialise les champs m et n.
struct matrix * consMatrix ( int n, int m );
//@brief Créer une copie exacte de la matrice M.
struct matrix * cpyMatrix ( struct matrix * M );
//@brief Libère toute la mémoire occupée par *M et mais celle-ci à NULL.
void freeMatrix (struct matrix ** M);
//@brief Visualise la matrice M après avoir affiché son entête
void viewMatrix (struct matrix * M, char *entete);
//@brief saisit au clavier les données.
struct matrix * scanMatrix ();
struct matrix * addMatrix ( struct matrix * A, struct matrix * B );
struct matrix * multMatrix ( struct matrix * A, struct matrix * B );
struct matrix * matrixInput ( char * filename );

#endif