#include <interrupts.h>
#include <lib.h>
#include <time.h>
#include <keyboard.h>
#define STDERR 2

static void int_00();

typedef void (*PException)(void);
static PException exceptions[0x20] = {&int_00};

static void int_00() {
    print(STDERR, "Division by zero", 16);
    show_registers();
    print(STDERR, "Presione enter para continuar...", 33);
    uint8_t sc;
    do{
        sc = kbRead();
    } while(sc != 0x1C);

    // TODO: find a way to restart the process after the exc is called.
}

void exceptionDispatcher(int exception) {
    PException exc = exceptions[exception];
    if (exc != 0) exc();
    return;
}
