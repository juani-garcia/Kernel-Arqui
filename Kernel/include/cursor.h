#ifndef __CURSOR__H_
#define __CURSOR__H_

#include <stdint.h>


typedef struct cursor {
    uint16_t x;
    uint16_t y;
} Tcursor;

static Tcursor cursor;

typedef Tcursor * Pcursor;

uint16_t getX(Pcursor cursor);
uint16_t getY(Pcursor cursor);

void setX(Pcursor cursor, uint16_t x);
void setY(Pcursor cursor, uint16_t y);

#endif