#ifndef __PROCESS__H_
#define __PROCESS__H_

#include <stdint.h>

#define STACK_SIZE 512
#define DEFAULT_STDIN 0
#define DEFAULT_STDOUT 1
#define AMMOUNT_FDS 2

typedef struct process * proc;

struct process {
    uint16_t offset_x;
    uint16_t offset_y;
};

static struct process curr_process = {0, 0};

#endif