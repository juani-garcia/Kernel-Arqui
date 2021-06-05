#include <cursor.h>
#include <process.h>

Pcursor newCursor() {
    cursor.x = 0; cursor.y = 0;
    return &cursor;
}

uint16_t getX(Pcursor cursor) {
    return cursor->x;
}

uint16_t getY(Pcursor cursor) {
    return cursor->y;
}

void setX(Pcursor cursor, uint16_t x){
    cursor->x = x + curr_process.offset_x;
}

void setY(Pcursor cursor, uint16_t y){
    cursor->y = y + curr_process.offset_y;
}