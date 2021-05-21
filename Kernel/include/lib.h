#ifndef LIB_H
#define LIB_H

#include <stdint.h>
#include <stddef.h>

void * memset(void * destination, int32_t character, uint64_t length);
void * memcpy(void * destination, const void * source, uint64_t length);

char *cpuVendor(char *result);

uint32_t getVideoModeInformation(uint64_t rdi, int mode);

int print(unsigned int fd, const char * buf, size_t count);

#endif