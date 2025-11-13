; xgfx.asm

bits 16
%include "xgfx.h"

global exit
global xputchar
global heap1

heap1: dd _heap
_heap: times 0x1000 db 0x00

exit:
    push bp
    mov bp, sp

    xor ax, ax
    int 0x21

    .halt:
        cli
        hlt
        jmp .halt

        mov sp, bp
        pop bp
        ret
    
; INT 10,E - Write Text in Teletype Mode
; AH = 0E
; AL = ASCII character to write
; BH = page number (text modes)
; BL = foreground pixel color (graphics modes)
xputchar:
    push bp
    mov bp, sp

    arg ax, 0
    mov ah, 0x0e
    xor bx, bx
    int 0x10

    mov sp, bp
    pop bp

    ret