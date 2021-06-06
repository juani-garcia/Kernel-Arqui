include Makefile.inc

KERNEL=kernel.bin
SOURCES=$(wildcard *.c)
SOURCES_INTERRUPTIONS=$(wildcard interruptions/*.c)
SOURCES_INTERRUPTIONS_ASM=$(wildcard interruptions/*.asm)
SOURCES_ASM=$(wildcard asm/*.asm)
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_INTERRUPTIONS=$(SOURCES_INTERRUPTIONS:.c=.o)
OBJECTS_INTERRUPTIONS_ASM=$(SOURCES_INTERRUPTIONS_ASM:.asm=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)
LOADERSRC=loader.asm

LOADEROBJECT=$(LOADERSRC:.asm=.o)
STATICLIBS=

ALL_OBJECTS= $(LOADEROBJECT) $(OBJECTS) $(OBJECTS_ASM) $(OBJECTS_INTERRUPTIONS) $(OBJECTS_INTERRUPTIONS_ASM)



debug: $(KERNEL_DEBUG) # TODO Develop debug mode

%.o: %.c
	$(GCC) -g $(GCCFLAGS) -I./include -I./interruptions -c $< -o $@ 

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

$(LOADEROBJECT):
	$(ASM) $(ASMFLAGS) $(LOADERSRC) -o $(LOADEROBJECT)



all: $(KERNEL)

$(KERNEL).elf: $(STATICLIBS) $(ALL_OBJECTS)
	$(GCC) $(GCCFLAGS) -T kernel.ld -static -Wl,--oformat=elf64-x86-64,--build-id=none -o $@ $^

$(KERNEL): $(KERNEL).elf
	objcopy -O binary $^ $@

clean:
	rm -rf $(ALL_OBJECTS) *.bin
	rm -rf *.elf

.PHONY: all clean
