/*main*/

asm(
    ".code16gcc\n"
    "call main\n"
    "call exit\n"
);

#include "gui.h"
#include "assembly.h"
#include "shapes.h"

void *heap_ptr;

void main()
{
    freeall();
    videomode(V40_25);
    getchar();

    return;
}

void putchar(int8 c)
{
    xputchar(c);

    return;
}

int8 getchar(void)
{
    int8 ax, al, ah;

    ax = xgetchar();
    al = (ax & 0xf);
    ah = ((ax & 0xf0) >> 4);

    return (al) ? al : ah;
}

void videomode(int8 mode)
{
    if (mode > 0x9f)
        return;

    xvideomode(mode);

    return;
}

void print(int8* str)
{
    int8 *p;

    for(p=str; *p; p++)
        putchar(*p);

    return;
}

void *alloc(int16 size)
{
    void *p;

    if(!size)
        return (void *) 0;
    
    p = heap_ptr;
    heap_ptr += size;

    return p;
}

void freeall()
{
    heap_ptr = heap1;

    return;
}