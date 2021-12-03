#ifndef _OUTILS_
#define _OUTILS_

#include <stdbool.h>

/** affichage d'une valeur entière */
void printInteger(int *i);

/** suppression d'une mémoire de type entier */
void rmInteger(int *i);

/** comparaison de 2 entiers */
bool intcmp(int *i, int *j);

/** affichage d'une valeur réelle */
void printDouble(double *d);

/** suppression d'une mémoire de type réel */
void rmDouble(double *d);

/** comparaison de 2 réels */
bool reelcmp(double *u, double *v);

#endif // _OUTILS_
