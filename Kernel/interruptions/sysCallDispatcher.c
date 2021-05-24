#include <time.h>
#include <keyboard.h>
#include <stdint.h>
#include <stddef.h>
#include <naiveConsole.h>
#include <lib.h>

typedef uint64_t (*PSysCall)(uint64_t, uint64_t, uint64_t);

static int write(unsigned int fd, const char * buf, size_t count);

static PSysCall sysCalls[255] = {&write};

int write(unsigned int fd, const char * buf, size_t count) {
    if (buf == NULL)
        return -1;
    char att = fd==STDERR? 0x0C : 0x07;
    int i;
    for(i = 0; buf[i] && i < count; i++){
        ncPrintCharAtt(buf[i], att);
    }
    ncNewline();
    return i == 0? -1 : i;  // TODO: see if this return value is valid. Or should we send codes?
}

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax) {  // TODO: Depending on how many sysCalls we have we have to see wich regiters we use.
    PSysCall sysCall = sysCalls[rax];
    if (sysCall != 0) return sysCall(rdi, rsi, rdx);
    return 0;
}
