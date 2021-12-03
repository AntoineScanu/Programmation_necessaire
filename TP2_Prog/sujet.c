#include <stdlib.h>
#include <stdio.h>

/**********************
      PARTIE I
  TA et déclarations
**********************/

/** @brief
    Les types abstraits modélisant
    un point et un segment du plan
*/
struct point2d {
    double x, y;
};

struct segment2d {
    struct point2d O, E;
};

/** @brief
    Déclarations des focniotns et procédures :
    - newPoint2d crée un point du plan
    - newSegment2d crée un segment du plan
    - viewPoint2d affiche les coordonnées du point P
    - viewSegment2d affiche les coordonnées des points
      origine et extrémité du segment S
*/
struct point2d newPoint2d();
struct segment2d newSegment2d();
void viewPoint2d(struct point2d P);
void viewSegment2d(struct segment2d S);


/**********************
      PARTIE II
  La fonction principale
**********************/

int main() {
    struct point2d P = newPoint2d();
    struct segment2d S = newSegment2d();
    viewPoint2d(P);
    viewSegment2d(S);
    return 0;
}


/*************************
        PARTIE III
      Définitions des
  fonctions et procédures
**************************/

struct point2d newPoint2d() {
    struct point2d P;
    P.x = 0;
    P.y = 0;
    return P;
}

struct segment2d newSegment2d() {
    struct segment2d S;
    S.O.x = 1;
    S.O.y = 1;
    S.E.x = 2;
    S.E.y = 2;
    return S;
}

void viewPoint2d(struct point2d P) {
    printf("Le point de coordonnées (%lf,%lf)\n", P.x, P.y);
}

void viewSegment2d(struct segment2d S) {
    printf("Le segment\n\td'origine : ");
    viewPoint2d(S.O);
    printf("Le segment\n\td'éxtremité : ");
    viewPoint2d(S.E);
}
