/* shapes.h */

#pragma once
#include "gui.h"

#define MAX_X 40
#define MAX_Y 25
#define V40_25 0

typedef struct s_point {
  int16 x;
  int16 y;
  int8 color : 4;
} PACKED point_t;

typedef struct s_line {
  point_t *p1;
  point_t *p2;
  int8 color : 4;
  int16 thickness;
} PACKED line_t;

int16 getMaxX();
int16 getMaxY();

boolean drawPoint(point_t *);
point_t *makePoint(int16, int16, int8);

boolean drawLine(line_t *);
line_t *makeLine(point_t *, point_t *, int8, int16);