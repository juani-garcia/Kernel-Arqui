#include <stdint.h>
#include "keyboard.h"

static uint8_t buffer[256]={0};
static uint64_t w_pointer = buffer, r_pointer = buffer;

static int kbdus[128] = {
	0,  27, '1', '2', '3', '4', '5', '6', '7', '8',
	'9', '0', '-', '=', -1, '\t', 'q', 'w', 'e', 
	'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 
	'\n', 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 
	'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 
	'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
	'*',
    0,    /* Alt */
  ' ',    /* Space bar */
    -2,    /* Caps lock */
    0,    /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,    /* < ... F10 */
    0,    /* 69 - Num lock*/
    0,    /* Scroll Lock */
    0,    /* Home key */
    0,    /* Up Arrow */
    0,    /* Page Up */
  '-',
    0,    /* Left Arrow */
    0,
    0,    /* Right Arrow */
  '+',
    0,    /* 79 - End key*/
    0,    /* Down Arrow */
    0,    /* Page Down */
    0,    /* Insert Key */
    0,    /* Delete Key */
    0,   0,   0,
    0,    /* F11 Key */
    0,    /* F12 Key */
    0,    /* All other keys are undefined */
};

void keyboard_handler(void) {
    // uint8_t character = kbRead();
    // if (character > 0x80) {
    //     ncPrintChar(kbdus[character-0x80]);
    //     ncNewline();
    //   return;
    // }
    // kbRead();
    ncPrintChar('a');
    ncNewline();
    return;
}
