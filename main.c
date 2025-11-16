/*main*/

asm(".code16gcc\n"
    "call main\n"
    "call exit\n");

#include "assembly.h"
#include "gui.h"
#include "shapes.h"

void *heap_ptr;
extern boolean video_init;

void main() {
  point_t *point;
  point_t *point1;

  video_init = false;
  freeall();
  videomode(V40_25);
  point = makePoint(1, 20, 0);
  point1 = makePoint(100, 20, 0);

  line_t *line = makeLine(point, point1, 0, 2);
  drawLine(line);

  getchar();
  freeall();

  return;
}

void putchar(int8 c) {
  xputchar(c);

  return;
}

int8 getchar(void) {
  int8 ax, al, ah;

  ax = xgetchar();
  al = (ax & 0xf);
  ah = ((ax & 0xf0) >> 4);

  return (al) ? al : ah;
}

void videomode(int8 mode) {
  if (mode > 0x9f)
    return;

  xvideomode(mode);
  video_init = true;

  return;
}

void print(int8 *str) {
  int8 *p;

  for (p = str; *p; p++)
    putchar(*p);

  return;
}

void *alloc(int16 size) {
  void *p;

  if (!size)
    return (void *)0;

  p = heap_ptr;
  heap_ptr += size;

  return p;
}

void freeall() {
  heap_ptr = heap1;

  return;
}