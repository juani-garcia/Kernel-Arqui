#include <time.h>
#include <keyboard.h>
#include <stdint.h>
#include <naiveConsole.h>
#include <lib.h>
#include <interrupts.h>
#include <cpu_support.h>
#include <clock.h>

typedef uint64_t (*PSysCall)(uint64_t, uint64_t, uint64_t);

long write(unsigned int fd, const char * buf, size_t count); // TODO: Fix long for ssize_t
long read(unsigned int fd, char * buf, size_t count);
uint64_t cpuid_support(uint64_t rdi, uint64_t rsi, uint64_t rdx);
uint64_t info_reg(uint64_t rdi, uint64_t rsi, uint64_t rdx);
uint64_t mem_dump_32B(char * buf, uint8_t * dir, uint64_t rdx);
uint64_t fecha_y_hora(char * datebuf, char * timebuf, uint64_t rdx);

static PSysCall sysCalls[255] = {(PSysCall)&read, (PSysCall)&write, (PSysCall)&cpuid_support, (PSysCall)&info_reg, (PSysCall)&mem_dump_32B, (PSysCall)&fecha_y_hora};

long write(unsigned int fd, const char * buf, size_t count) {
    if (buf == NULL)
        return -1;
    int i;
    uint32_t front = fd == STDERR ? RED : WHITE;
    for(i = 0; buf[i] && i < count; i++) {
        if (buf[i] == '\n')     // TODO: idk why this creates an exception.
            ncNewline();
        else if (buf[i] == '\b')
            ncErase(1);
        else
            ncPrintCharAtt(buf[i], front, BLACK);
    }
    return i == 0? -1 : i;  // TODO: see if this return value is valid. Or should we send codes?
}

long read(unsigned int fd, char * buf, size_t count) {
    // TODO: What could we use fd for¿?
    long read_count = -1;
    while ( read_count == -1 ) {
        if ((read_count = copy_from_buffer(buf, count)) == -1)
            _hlt();
    }
    return read_count;
}

uint64_t info_reg(uint64_t rdi, uint64_t rsi, uint64_t rdx) {
    show_registers();
    return 0;
}

uint64_t cpuid_support(uint64_t rdi, uint64_t rsi, uint64_t rdx) {
    return _cpuid_support();
}

uint64_t mem_dump_32B(char * buf, uint8_t *  dir, uint64_t rdx) {
    int value;
    for (int i = 0; i < 32; i++) {
        value = *dir >> 4;
        buf[i] = value > 9 ? (10 - value) + 'A' : value + '0';
        value = *dir & 0xF;
        buf[i+1] = value > 9 ? (10 - value) + 'A' : value + '0';
        dir+=1;
    }
    return 0;
}

uint64_t fecha_y_hora(char * datebuf, char * timebuf, uint64_t rdx){
	dateToStr(datebuf);
	timeToStr(timebuf);
    return 0;
}

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax) {  // TODO: Depending on how many sysCalls we have we have to see wich regiters we use.
    PSysCall sysCall = sysCalls[rax];
    if (sysCall != 0) return sysCall(rdi, rsi, rdx);
    return 0;
}
