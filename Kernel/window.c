#include <window.h>
#include <process.h>

typedef struct cursor {
    uint16_t x;
    uint16_t y;
} Tcursor;

static Tcursor cursor;

Pcursor initCursor() {
    cursor.x = 0; cursor.y = 0;
}

uint16_t getX(Pcursor cursor) {
    return cursor->x;
}

uint16_t getY(Pcursor cursor) {
    return cursor->y;
}

void setX(Pcursor cursor, uint16_t x){
    cursor->x = x;
}

void setY(Pcursor cursor, uint16_t y){
    cursor->y = y;
}