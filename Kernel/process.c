#include <stdint.h>
#include <process.h>
// Debug includes
#include <time.h>
#include <naiveConsole.h>

static uint8_t activeProcess = 0;

void load_processes(ProcessPtr p1, ProcessPtr p2) {
    p1->sp = init_process(processes[0]->stack_base, processes[0]->ip);
    ncPrintHex(p1->sp);
    p2->sp = init_process(processes[1]->stack_base, processes[1]->ip);
    ncPrintHex(*((uint64_t*) 0x700000 - 0 * 8));
    ncPrintHex(*((uint64_t*) 0x700000 - 1 * 8));
    ncPrintHex(*((uint64_t*) 0x700000 - 2 * 8));
    ncPrintHex(*((uint64_t*) 0x700000 - 3 * 8));
    ncPrintHex(*((uint64_t*) 0x700000 - 4 * 8));
    ncPrintHex(p2->sp);
    processes[0] = p1;
    processes[1] = p2;
    while(1);
}

void switch_process(){
    // processes[activeProcess]->sp = get_rsp();
    // activeProcess = 1 - activeProcess;
    // set_rsp(processes[activeProcess]->sp);
}

void begin(){
    if(processes[0] != 0) run_process(processes[0]->sp);
}