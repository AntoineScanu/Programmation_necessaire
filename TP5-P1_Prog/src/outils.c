#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "outils.h"

/** affichage d'une valeur entière */
void printInteger(int *i) {
    printf("La valeur est entière et vaut : %d\n", (*i));
}

/** suppression d'une mémoire de type entier */
void rmInteger(int *i) {
    free(i);
}

/** comparaison de 2 entiers */
bool intcmp(int *i, int *j) {
    return (*i) < (*j);
}

/** affichage d'une valeur réelle */
void printDouble(double *d) {
    printf("La valeur est réelle et vaut : %lf\n", (*d));
}

/** suppression d'une mémoire de type réel */
void rmDouble(double *d) {
    free(d);
}

/** comparaison de 2 réels */
bool reelcmp(double *u, double *v) {
    return (*u) < (*v);
}
