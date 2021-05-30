/* sampleCodeModule.c */

char * v = (char*)0xB8000 + 79 * 2;

#include <lib.h>

static int var1 = 0;
static int var2 = 0;


int main() {
	char buf[200];
	read(STDOUT, buf, 200);
	print(STDERR, buf, 200);
	return 6;
}