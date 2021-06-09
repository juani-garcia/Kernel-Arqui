#include <stdint.h>
#include <process.h>
// Debug includes
#include <time.h>
#include <naiveConsole.h>

static uint8_t activeProcess = 0;

void load_processes(ProcessPtr p1, ProcessPtr p2) {
    processes[0] = p1;
    processes[1] = p2;
    processes[0]->sp = init_process(processes[0]->stack_base, processes[0]->ip);
    processes[1]->sp = init_process(processes[1]->stack_base, processes[1]->ip);
}

// void switch_process() {
//     processes[activeProcess]->sp = get_rsp();
//     activeProcess = 1 - activeProcess;
//     set_rsp(processes[activeProcess]->sp);
//     ncPrint("Going to process "); ncPrintDec(activeProcess);
//     ncNewline();
// }

uint64_t set_up_process(uint64_t rsp) {
    processes[activeProcess]->sp = rsp;
    activeProcess = 1 - activeProcess;
    ncPrint("Me muevo al proceso "); ncPrintDec(activeProcess);
    ncNewline();
    return processes[activeProcess]->sp;
}

void begin() {
    if(processes[0] != 0) run_process(processes[0]->sp);
}