rebuild: clean all

debug: kernel_debug userland_debug

all:  bootloader kernel userland image

bootloader:
	cd Bootloader; make all

kernel:
	cd Kernel; make all

kernel_debug:
	cd Kernel; make debug

userland:
	cd Userland; make all

userland_debug:
	cd Userland; make debug

image: kernel bootloader userland
	cd Image; make all

clean:
	cd Bootloader; make clean
	cd Image; make clean
	cd Kernel; make clean
	cd Userland; make clean

.PHONY: bootloader image collections kernel userland all clean
