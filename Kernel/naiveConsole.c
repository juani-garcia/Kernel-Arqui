#include <naiveConsole.h>
#include <font.h>
#include <videoDriver.h>
#include <cursor.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);
static void scrollUp();
static int numlen(uint64_t val);

static char buffer[128] = { '0' };
static uint8_t * video;
static uint32_t width;
static uint32_t height;
static uint8_t bpp;

void initScreen(void) {
	video = (uint8_t *)((uint64_t)(screen->framebuffer));
	width = screen->width;
	height = screen->height;
	bpp = screen->bpp;
	// TODO: init screen.
}

void ncPrint(const char * string) {
	int i;
	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintAtt(const char * string, uint32_t frontColor, uint32_t backColor) {
	for (int i = 0; string[i] != 0; i++)
		ncPrintCharAtt(string[i], frontColor, backColor);
}

void ncPrintChar(char character) {
	ncPrintCharAtt(character, WHITE, BLACK);
}

void ncPrintCharAtt(char character, uint32_t frontColor, uint32_t backColor) {
	if (getX(&cursor) >= width) {
		setX(&cursor, 0);
		if (getY(&cursor) >= height - CHAR_HEIGHT) {
			scrollUp();
		} else {
			uint16_t y = getY(&cursor);
			setY(&cursor, y + CHAR_HEIGHT);
		}
	}

	uint8_t * letter = getCharMapping(character);
	for(int i = 0; i < CHAR_HEIGHT; i++) {
		for(int j = 0; j < CHAR_WIDTH; j++) {
			if(letter[i] & (1 << j))
				draw_pixel(CHAR_WIDTH - 1 - j + getX(&cursor), i + getY(&cursor), frontColor);
			else
				draw_pixel(CHAR_WIDTH - 1 - j + getX(&cursor), i + getY(&cursor), backColor);
		}
	}
	uint16_t x = getX(&cursor);
	setX(&cursor, x + CHAR_WIDTH);
}

void cpyPixel(int x_dst, int y_dst, int x_src, int y_src) {
	uint8_t * from = (uint8_t *) ((uint64_t)(video + screen->pitch *y_src + x_src* (int)(screen->bpp/8)));
	uint8_t * to = (uint8_t *) ((uint64_t)(video + screen->pitch *y_dst + x_dst* (int)(screen->bpp/8)));
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
}

void scrollUp() {
	for (int j = 0; j < height ; j++ ) {
		for(int i = 0; i < width ; i++) {
			cpyPixel(i, j, i, j + CHAR_HEIGHT);
		}
	}
}

void ncNewline() {
	do {
		ncPrintChar(' ');
	}	while((getX(&cursor) < width));
	setX(&cursor, 0);
	if (getY(&cursor) > height - CHAR_HEIGHT) {
		scrollUp();
	}
	setY(&cursor, getY(&cursor) + CHAR_HEIGHT);
}

void ncPrintDec(uint64_t value) {
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value) {
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value) {
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base) {
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear() {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			draw_pixel(i, j, BLACK);
		}
	}

	setX(&cursor, 0);
	setY(&cursor, 0);
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base) {
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do {
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}

void ncPrintReg(uint64_t reg) {
	ncPrint("0x");
	uint8_t len = numlen(reg);
	for(int i = 0; i < 16 - len; i++){
		ncPrintChar('0');
	}
	ncPrintHex(reg);
}

static int numlen(uint64_t val) {
	int len = 0;
	while(val != 0){
		len++;
		val /= 16;
	}
	return len + (len == 0);
}

void ncErase(uint32_t amount) {
	for (uint32_t c = 0; c < amount; c++) {
		if (getX(&cursor) == 0) {
			if (getY(&cursor) != 0) {
				setY(&cursor, getY(&cursor) - CHAR_HEIGHT);
				setX(&cursor, width);
			} else {
				return;
			}
		}
		for (uint16_t x = getX(&cursor) - 1; x < getX(&cursor) - CHAR_WIDTH ; x--) {
			for (uint16_t y = getY(&cursor); y > getY(&cursor) + CHAR_HEIGHT; y++){
				draw_pixel(x, y, BLACK);
			}
		}
		setX(&cursor, getX(&cursor) - CHAR_WIDTH);
	}
}