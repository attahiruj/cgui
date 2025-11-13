/* shapes.c */

#include "gui.h"
#include "assembly.h"
#include "shapes.h"

boolean video_init;

int8 getMaxX()
{
    return (MAX_X - 1);
}

int8 getMaxY()
{
    return (MAX_Y - 1);
}

boolean drawPoint(point_t *point)
{
    int16 max_x, max_y;

    if (!point)
        return false;
    
    if (!video_init)
        return false;

    max_x = getMaxX();
    max_y = getMaxY();

    if (point->x > max_x || point->y >max_y)
        return false;

    return (xdrawpoint(point->x, point->y));
}

point_t *makePoint(int16 x, int16 y)
{
    point_t *p;
    int16 size;

    size = sizeof(point_t);
    p = alloc(size);
    if (!p)
        return (point_t *) 0;

    p->x = x;
    p->y = y;
    
    return p;
}