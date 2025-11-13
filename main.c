/*main*/

asm(
    ".code16gcc\n"
    "call main\n"
    "call exit\n"
);

#include "gui.h"
#include "assembly.h"

void *heap_ptr;

void main()
{
    int8 *p;
    heap_ptr = heap1;

    p = alloc(8);

    if (!p)
    {
        print((int8*) "Failed to allocate mem");
        return;
    }

    p[0] = 'H';
    p[1] = 'e';
    p[2] = 'l';
    p[3] = 'l';
    p[4] = 'o';
    p[5] = 0;

    print((int8*) p);
    freeall();

    return;
}

void putchar(int8 c)
{
    xputchar(c);

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