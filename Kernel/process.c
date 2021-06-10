#include <stdint.h>
#include <process.h>
// Debug includes
#include <time.h>
#include <naiveConsole.h>

uint8_t activeProcess = 0;
uint64_t rsps[2] = {};

void load_processes(ProcessPtr p1, ProcessPtr p2) {
    // processes[0] = p1;
    // processes[1] = p2;
    // processes[0]->sp = init_process(processes[0]->stack_base, processes[0]->ip);
    // processes[1]->sp = init_process(processes[1]->stack_base, processes[1]->ip);
    rsps[0] = init_process(200 * 1024 * 1024, 0x400000);
    rsps[1] = init_process(300 * 1024 * 1024, 0x400000);
}

uint64_t set_up_process(uint64_t rsp) {
    // processes[activeProcess]->sp = rsp;
    // activeProcess = 1 - activeProcess;
    // return processes[activeProcess]->sp;
    rsps[activeProcess] = rsp;
    activeProcess = 1 - activeProcess;
    return rsps[activeProcess];
}

void begin() {
    // if(processes[0] != 0) run_process(processes[0]->sp);
    if(rsps[0] != 0) run_process(rsps[0]);
}

void restart_process(){
    // processes[activeProcess]->sp = init_process(processes[activeProcess]->stack_base, processes[activeProcess]->ip);
    uint64_t sb = activeProcess == 0? 200 * 1024 * 1024 : 300 * 1024 * 1024; 
    rsps[activeProcess] = init_process(sb, 0x400000);
}

uint64_t get_current_rsp() {
    // return processes[activeProcess]->sp;
    return rsps[activeProcess];
}

uint8_t get_current_process() {
    return activeProcess;
}