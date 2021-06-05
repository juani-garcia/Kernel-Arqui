#include <naiveConsole.h>
#include <font.h>
#include <videoDriver.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);
static void scrollUp();
static void checkPosition();
static int numlen(uint64_t val);

static char buffer[128] = { '0' };
static uint8_t * const video = ( uint8_t *) ((uint64_t)(screen->framebuffer);
static uint8_t * currentVideo = video;
static const uint32_t width = screen->width;
static const uint32_t height = screen->height;
static const uint8_t bpp = screen->bpp;

void ncPrint(const char * string)
{
	int i;
	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintAtt(const char * string, uint32_t frontColor, uint32_t backColor)
{
	for (int i = 0; string[i] != 0; i++)
		ncPrintCharAtt(string[i], frontColor, backColor);
}

void ncPrintChar(char character)
{
	ncPrintCharAtt(character, 0xFF, 0x00);
}

void ncPrintCharAtt(char character, uint32_t frontColor, uint32_t backColor)
{
	uint8_t * letter = pixel_chars[character];
	for(int i = 0; i < CHAR_WIDTH; i++){
		
	}4

}

void copyPixel(int toX, int toY, int fromX, int fromY){
	char * from = (uint8_t *) ((uint64_t)(vbeInfo->framebuffer + vbeInfo->pitch *fromY + fromX* (int)(vbeInfo->bpp/8)));
	char * to = (uint8_t *) ((uint64_t)(vbeInfo->framebuffer + vbeInfo->pitch *toY + toX* (int)(vbeInfo->bpp/8)));
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
}

void ncSlideUpLine(){
	for(int i = 0; i < screen->height ;  )
}


// ----------------------------- sin editar

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

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

void ncPrintReg(uint64_t reg)
{
	ncPrint("0x");
	uint8_t len = numlen(reg);
	for(int i = 0; i < 16 - len; i++){
		ncPrintChar('0');
	}
	ncPrintHex(reg);
}

static int numlen(uint64_t val){
	int len = 0;
	while(val != 0){
		len++;
		val /= 16;
	}
	return len + (len == 0);
}

static void checkPosition()
{
	if(currentVideo - video >= width * height * 2)
		scrollUp();
} 

static void scrollUp()
{
	for(int i = 0; i < height - 1; i++){
		for(int j = 0; j < width * 2; j++){
			video[j + i * width * 2] = video[j + (i + 1) * width * 2];
		}
	}
	for(int k = 0; k < width * 2; k++)
		video[(height - 1) * width * 2 + k] = '\0';
	currentVideo = video + (height - 1) * width * 2;
}

void ncErase(uint16_t amount)
{
	for(int i = 0; i < amount * 2; i++){
		*currentVideo = '\0';
		currentVideo--;
	}
}