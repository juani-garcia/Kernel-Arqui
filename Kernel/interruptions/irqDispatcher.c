#include <time.h>
#include "keyboard.h"
#include <stdint.h>

static void int_20();

typedef void (*Pinterruption)(void);

void int_20() {
    timer_handler();
}

void int_21() {
    set_time_0();
}

void irqDispatcher(uint64_t irq) {
    Pinterruption interruptions[255]={0};
    interruptions[0] = &int_20;
    interruptions[1] = &int_21;
    Pinterruption interruption = interruptions[irq];
    if (interruption != 0)
        interruption();
    return;
}
