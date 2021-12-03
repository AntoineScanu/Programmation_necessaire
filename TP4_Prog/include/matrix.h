#ifndef _MATRIX_
#define _MATRIX_


struct matrix {
    double *values;
    int n, m;
};

struct matrix *consMatrix(int n, int m);

//Alloue la mémoire et initialise les champs m et n.
struct matrix *cpyMatrix(struct matrix *M);

//Créer une copie exacte de la matrice M.
void freeMatrix(struct matrix **M);

//Libère toute la mémoire occupée par *M et mais celle-ci à NULL.
void viewMatrix(struct matrix *M, char *entete);

//Visualise la matrice M après avoir affiché son entête.
struct matrix *scanMatrix(char *filename);

//saisit au clavier les données.
struct matrix *addMatrix(struct matrix *A, struct matrix *B);

struct matrix *multMatrix(struct matrix *A, struct matrix *B);

#endif // _MATRIX_