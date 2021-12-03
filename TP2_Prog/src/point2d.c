#include "point2d.h"

#include <stdlib.h>
#include <stdio.h>

struct point2d newPoint2d() {
    struct point2d P;
    P.x = 0;
    P.y = 0;
    return P;
}

void viewPoint2d(struct point2d P) {
    printf("Le point de coordonnées (%lf,%lf)\n", P.x, P.y);
}
