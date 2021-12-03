#include "segment2d.h"

#include <stdlib.h>
#include <stdio.h>

struct segment2d newSegment2d() {
    struct segment2d S;
    S.O.x = 1;
    S.O.y = 1;
    S.E.x = 2;
    S.E.y = 2;
    return S;
}

void viewSegment2d(struct segment2d S) {
    printf("Le segment\n\td'origine : ");
    viewPoint2d(S.O);
    printf("Le segment\n\td'éxtremité : ");
    viewPoint2d(S.E);
}