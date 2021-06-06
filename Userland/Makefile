include Makefile.inc

SAMPLE_DATA=0001-sampleDataModule.bin

all: sampleCodeModule sampleDataModule

debug: sampleCodeModule_debug sampleCodeModule

sampleCodeModule_debug:
	cd SampleCodeModule; make debug

sampleCodeModule: 
	cd SampleCodeModule; make all

sampleDataModule:
	printf "This is sample data." >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)

clean:
	cd SampleCodeModule; make clean
	rm -rf *.bin
	rm -rf *.elf


.PHONY: sampleCodeModule all clean
