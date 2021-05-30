#ifndef __LIB_ASM__H__
#define __LIB_ASM__H__

#include <stddef.h>
#define STDOUT 1
#define STDERR 2

void print(unsigned int fd, const char * buf, size_t count);
long read(unsigned int fd, char * buf, size_t count);


#endif