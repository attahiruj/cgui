flags := -fno-stack-protector -fno-pie -O0 -Wall -std=gnu2x -m16
flags += -ffreestanding -nostdlib -I include

ldflags := --nmagic --script=gui.ld

NASMENV := -i include/asm/
export NASMENV

objects := main.o
xobjects := xgfx.o


.PHONY: clean

all: gui.com

gui.com: $(objects) $(xobjects)
	ld -m elf_i386 $(ldflags) $^ -o $@

main.o: main.c
	cc $(flags) -c $^

xgfx.o: xgfx.asm
	nasm -f elf $^ -o $@

objdump:
	objdump -M intel -D -b binary -m i8086 gui.com

clean:
	rm -f *.o *.com