#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>

void ncPrint(const char * string);
void ncPrintAtt(const char * string, char frontColor, char backColor, char blink);
void ncPrintChar(char character);
void ncPrintCharAtt(char character, char attribute);
void ncNewline();
void ncErase(uint16_t pos);
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();

#endif