#ifndef __PROCESS__H_
#define __PROCESS__H_

#include <stdint.h>

#define STACK_SIZE 512
#define DEFAULT_STDIN 0
#define DEFAULT_STDOUT 1
#define AMMOUNT_FDS 2

typedef struct process * proc;

static struct process curr_process = {0, 0};
void init_process(uint64_t stack_base, uint64_t rip);

#endif