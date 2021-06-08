include Makefile.inc

all: sampleCodeModule

sampleCodeModule_debug:
	cd SampleCodeModule; make debug

sampleCodeModule:
	cd SampleCodeModule; make all

clean:
	cd SampleCodeModule; make clean
	rm -rf *.bin
	rm -rf *.elf


.PHONY: sampleCodeModule all clean
