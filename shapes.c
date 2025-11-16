/* shapes.c */

#include "shapes.h"

#include "assembly.h"
#include "gui.h"

boolean video_init;

int16 getMaxX() { return (MAX_X - 1); }

int16 getMaxY() { return (MAX_Y - 1); }

boolean inRange(int16 x, int16 y) {
  int16 max_x, max_y;
  max_x = getMaxX();
  max_y = getMaxY();

  if (x > max_x || y > max_y)
    return false;

  return true;
}

boolean drawPoint(point_t *point) {
  if (!point)
    return false;

  if (!video_init)
    return false;

  if (!inRange(point->x, point->y))
    return false;

  return (xdrawpoint(point->x, point->y));
}

point_t *makePoint(int16 x, int16 y, int8 color) {
  point_t *p = alloc(sizeof(point_t));
  if (!p)
    return (point_t *)0;

  p->x = x;
  p->y = y;
  p->color = color;

  return p;
}

line_t *makeLine(point_t *p1, point_t *p2, int8 color, int16 thickness) {
  if (!p1 || !p2 || !thickness)
    return (line_t *)0;

  line_t *l = alloc(sizeof(line_t));
  if (!l)
    return (line_t *)0;

  l->p1 = p1;
  l->p2 = p2;
  l->color = color;
  l->thickness = thickness;

  return l;
}

boolean drawLine(line_t *line) {
  point_t *p;
  int16 start_x, start_y, end_x, end_y;
  //, thickness;

  if (!line)
    return false;

  if (!video_init)
    return false;

  // p1 comes first for ease
  if (line->p1->x > line->p2->x || line->p1->y > line->p2->y) {
    print((int8 *)"Ensure P1 is comes before P2\r\n");

    return false;
  }

  // only support vertical and horicontal lines
  if (line->p1->x != line->p2->x && line->p1->y != line->p2->y) {
    print((int8 *)"Sorry only vertical and horzontal line supported\r\n");

    return false;
  }

  if (line->p1->x == line->p2->x) {
    start_x = line->p1->x;
    int16 xl_t = line->p2->x + line->thickness;
    end_x = (xl_t < getMaxX()) ? xl_t : getMaxX();

    start_y = line->p1->y;
    end_y = line->p2->y < getMaxY() ? line->p2->y : getMaxY();
  } else if (line->p1->y == line->p2->y) {
    start_x = line->p1->x;
    end_x = line->p2->x < getMaxX() ? line->p2->x : getMaxX();

    start_y = line->p1->y;
    int16 yl_t = line->p2->y + line->thickness;
    end_y = (yl_t < getMaxY()) ? yl_t : getMaxY();
  }

  for (int x = start_x; x < end_x; x++) {
    for (int y = start_y; y < end_y; y++) {
      p = makePoint(x, y, line->color);
      if (p)
        drawPoint(p);
    }
  }

  return true;
}