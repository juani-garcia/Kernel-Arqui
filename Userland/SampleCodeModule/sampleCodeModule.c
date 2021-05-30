/* sampleCodeModule.c */

char * v = (char*)0xB8000 + 79 * 2;

#include <lib.h>

static int var1 = 0;
static int var2 = 0;


int main() {
	try_catch_ud();
	return 6;
}