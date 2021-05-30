include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
MODULE_DEBUG=0000-sampleCodeModule.elf
SOURCES=$(wildcard *.c)
SOURCES_ASM=$(wildcard asm/*.asm)
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)

ALL_OBJECTS= $(OBJECTS) $(OBJECTS_ASM)

debug: $(MODULE_DEBUG)

$(MODULE_DEBUG): $(ALL_OBJECTS)
	$(GCC) -g $(GCCFLAGS) -T sampleCodeModule.ld -Wl,--oformat=elf64-x86-64 -o $@ $^

%.o: %.c
	$(GCC) -g $(GCCFLAGS) -I./include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@


all: $(MODULE)

$(MODULE): $(ALL_OBJECTS)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld -o $@ $^

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o *.bin *.elf

.PHONY: all clean print
