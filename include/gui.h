/* gui.h */
#pragma once

#define true 1
#define false 0

#define PACKED __attribute__((packed))

typedef unsigned char int8;
typedef unsigned short int16;
typedef unsigned char boolean;

extern void *heap1;

void print(int8 *);
void putchar(int8);
int8 getchar(void);
void videomode(int8);

void *alloc(int16);
void freeall(void);