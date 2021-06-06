include ../Makefile.inc

LOADER=_loader
MODULE=0000-sampleCodeModule.bin
MODULE_DEBUG=0000-sampleCodeModule.elf
SOURCES=$(shell find -type f -name "*.c" ! -name "$(LOADER).c")
SOURCES_ASM=$(wildcard asm/*.asm)
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)

ALL_OBJECTS= $(OBJECTS) $(OBJECTS_ASM)

debug: $(MODULE_DEBUG)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@


all: $(MODULE)

$(MODULE): $(MODULE_DEBUG)
	objcopy -O binary $^ $@

$(MODULE_DEBUG): $(LOADER).o $(ALL_OBJECTS) 
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld -static -Wl,--oformat=elf64-x86-64,--build-id=none -o $@ $(ALL_OBJECTS)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o *.bin *.elf asm/*.o

.PHONY: all clean print
