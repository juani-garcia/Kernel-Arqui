include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
SOURCES_ASM=$(wildcard asm/*.asm)

all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T -I./include -c sampleCodeModule.ld _loader.c $(SOURCES) -o ../$(MODULE)

%.o : %.asm
	$(ASM) $(ASMFLAGS) asm/libasm.asm $(SOURCES_ASM) -o asm/libasm.o

clean:
	rm -rf *.o

.PHONY: all clean print
