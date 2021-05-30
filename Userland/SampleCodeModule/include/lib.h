#ifndef __LIB_ASM__H__
#define __LIB_ASM__H__

#include <stddef.h>

void print(unsigned int fd, const char * buf, size_t count);
void try_catch_ud(void);

#endif