// Created from bdf2c Version 3, (c) 2009, 2010 by Lutz Sammer
//	License AGPLv3: GNU Affero General Public License version 3
// Retrived from: https://github.com/pixelmatix/bdf2c & https://sourceforge.net/projects/bdf2c/

#include <font.h>

uint8_t * getCharMapping(uint8_t c) {
	return pixel_chars + CHAR_HEIGHT * (c-31);
}