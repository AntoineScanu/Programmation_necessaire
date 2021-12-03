#ifndef _SEGMENT2D_
#define _SEGMENT2D_

#include "point2d.h"

struct segment2d {
    struct point2d O, E;
};
struct segment2d newSegment2d();
void viewSegment2d(struct segment2d S);

#endif // _SEGMENT2D_
