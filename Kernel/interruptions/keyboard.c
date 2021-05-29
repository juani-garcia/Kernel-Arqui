#include <stdint.h>
#include "keyboard.h"
#include <naiveConsole.h>
#include <stddef.h>

static int kbdus[128] = {
	0,  0, '1', '2', '3', '4', '5', '6', '7', '8',
	'9', '0', '-', -1, -1, '\t', 'q', 'w', 'e', 
	'r', 't', 'y', 'u', 'i', 'o', 'p', 0, 0, 
	'\n', 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 
	'k', 'l', 0, '\'', '`', 0, '\\', 'z', 'x', 
	'c', 'v', 'b', 'n', 'm', 0, 0, 0, 0,
	0,
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
    0,    /* Minus Sign*/
    0,    /* Left Arrow */
    0,
    0,    /* Right Arrow */
    0,    /* Plus Sign*/
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
    uint8_t scanCode = kbRead();

    if (scanCode > 0x80) return;  // return if scanCode is BREAK.

    /* TODO: Further develop here if we accept more characters. */

    char character = kbdus[scanCode];

    if (character == 0) return;

    /* -------------------------------------------------------- */

    if (character == -1) {
      if (w_pointer != r_pointer) {
        ncErase(1);
        w_pointer--;
        // TODO: If needed we should add support for deleting \n;
      }
      return;
    }
    
    if (character == '\n') {
      ncNewline();
    } else {
      ncPrintChar(character);
    }

    buffer[w_pointer++] = character; // Add the character to the ciclic buffer and increment the w_pointer.
    return;
}

long copy_from_buffer(char * buf, size_t count) {
  if (r_pointer == w_pointer || buffer[w_pointer-1] != '\n') return -1;
  
  if (count > BUFFER_LENGTH) {} // TODO: what do we do.
  
  long i = 0;

  while (i < count && r_pointer != w_pointer)  // TODO: Check if we keep the last \n
    buf[i++] = buffer[r_pointer++];

  if (count < i) buf[i] = 0;
  
  return i;
}