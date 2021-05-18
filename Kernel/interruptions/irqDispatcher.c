#include <time.h>
#include "keyboard.h"
#include <stdint.h>

typedef void (*PInterruption)(void);
static void int_20();
static PInterruption[255] = {&int_20, };

void int_20() {
    timer_handler();
}



void irqDispatcher(uint64_t irq) {
    Pinterruption interruptions[255]={0};
    interruptions[0] = &int_20;
    Pinterruption interruption = interruptions[irq];
    if (interruption != 0)
        interruption();
    return;
}
