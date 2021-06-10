#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <clock.h>
#include <interrupts.h>
#include <time.h>
#include <videoDriver.h>
#include <process.h>
#include <window.h>

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss; 
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static uint64_t stackBase1 = 200 * 1024 * 1024;
static uint64_t stackBase2 = 300 * 1024 * 1024;
typedef int (*EntryPoint)();

void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];
	initScreen();
	
	void * moduleAddresses[] = {
		sampleCodeModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);

	clearBSS(&bss, &endOfKernel - &bss);

	return getStackBase();
}

int main() {
	initScreen();
	split();
	load_idt();
	Process p1 = {stackBase1, (uint64_t) sampleCodeModuleAddress, 0x0};
	Process p2 = {stackBase2, (uint64_t) sampleCodeModuleAddress, 0x0};
	load_processes(&p1, &p2);
	ncPrintAtt("Arquitectura de las Computadoras", WHITE, BLACK);
	ncNewline();
	ncPrint("[Kernel Main]");
	ncNewline();
	ncPrint("  Sample code module at 0x");
	ncPrintHex((EntryPoint)sampleCodeModuleAddress);
	ncNewline();

	//begin();

	ncPrint("  Calling the sample code module returned: ");
	ncPrintHex(((EntryPoint)sampleCodeModuleAddress)());
	//ncNewline();
	ncPrint("[Finished]");
	ncNewline();

	ncNewline();
	//show_registers();
	
	ncNewline();
	char date[9] = {0};
	dateToStr(date);
	char time[9] = {0};
	timeToStr(time);
	ncPrint(date); ncPrint("; "); ncPrint(time);

	uint8_t  changeDetected = 0;

	while(1){
		if(!changeDetected && ticks_elapsed() % (18) == 0){
			changeDetected = 1;
			// ncErase(18);
			timeToStr(time);
			dateToStr(date);
			ncPrint(date); ncPrint("; "); ncPrint(time);
		}
		if(changeDetected && ticks_elapsed() % (18) != 0)
			changeDetected = 0;
	}
    
	return 0;
}
