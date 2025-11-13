/* shapes.h */
#pragma once
#include "gui.h"

#define MAX_X   40
#define MAX_Y   25
#define V40_25  0

typedef struct s_point {
    int16 x;
    int16 y;
    int8 color:4;
} PACKED point_t;


int8 getMaxX();
int8 getMaxY();

boolean drawPoint(point_t *);
point_t *makePoint(int16, int16);