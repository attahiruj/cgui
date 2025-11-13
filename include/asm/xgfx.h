; xgfx.h

bits 16

%macro arg 2
    %%offset equ ((4 * %2) + 6)
        mov %1, [bp+%%offset]
%endmacro