/* sampleCodeModule.c */

char * v = (char*)0xB8000 + 79 * 2;

#include <lib.h>

static int var1 = 0;
static int var2 = 0;


int main() {

	print(STDOUT, "Hola mundo!", 11);

	return 0;
}