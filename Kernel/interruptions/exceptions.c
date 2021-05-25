#include <interrupts.h>
#include <naiveConsole.h>

static void int_00();

typedef void (*PException)(void);
static PException exceptions[0x20] = {&int_00};

static void int_00() {
    ncPrint("Division by zero");
}

void exceptionDispatcher(int exception) {
    PException exc = exceptions[exception];
    if (exc != 0) exc();
    return;
}
