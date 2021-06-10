#include <lib.h>
#include <shell.h>
#include <cpuid.h>
#define COMMANDS 5
#define MAX_BUFFER_LENGTH 256

int get_com(char * buffer);
int get_correct_command(char * buffer);
void command_listener(char * buffer);
void ayuda(void);
void inforeg(void);
void available(uint64_t reg, char moves);
void features_support(void);
void wrongop(void);
void zerodiv(void);

typedef void (*Pcommands)(void);

// TODO: should be compared with strcmp
static char * commands[COMMANDS] = {"ayuda", "inforeg", "support", "zerodiv", "wrongop"};

// TODO: implement printf along with scanf, putChar and getChar in order for this functionality to work
void ayuda() {
    printf("\nLos comandos disponibles son los siguientes:\n\n");
    printf("inforeg       -imprime en pantalla el valor de todos los registros.\n");
    printf("printmem      -realiza un volcado de memoria de 32 bytes a partir de la\n");
    printf("               direccion que se recibe como argumento.\n");
    printf("fechayhora    -desplega en pantalla el dia y la hora del sistema.\n");
    printf("ayuda         -muestra todos los comandos disponibles.\n");
    printf("zerodiv       -lanza una excepcion de codigo 00. Division by zero.\n");
    printf("wrongop       -lanza una excepcion de codigo 06. Wrong Operand Code.\n");
}

// TODO: after merging, this function should call show_registers
void inforeg(){
    get_info_reg();
}

void features_support(){
    printf("cpuid support: ");
    if(check_cpuid_support()){
        printf("yes.\n");
        uint32_t ecx = 1, edx, ebx;
        get_cpuid_info(&ecx, &edx, &ebx);

        printf("sse support: ");
        available(edx, 25);
        printf("sse2 support: ");
        available(edx, 26);
        printf("sse3 support: ");
        available(ecx, 0);
        printf("sse4.1 support: ");
        available(ecx, 19);
        printf("sse4.2 support: ");
        available(ecx, 20);
        printf("aesni support: ");
        available(ecx, 25);
        printf("pclmulqdq support: ");
        available(ecx, 1);
        printf("avx support: ");
        available(ecx, 28);
        printf("f16c support: ");
        available(ecx, 29);
        printf("fma support: ");
        available(ecx, 12);

        ecx = 7; edx = 0;
        get_cpuid_info(&ecx, &edx, &ebx);
        printf("avx2 support: ");
        available(ebx, 6);
        printf("vpclmulqdq support: ");
        available(ecx, 10);
        printf("vaesni support: ");
        available(ebx, 0000000000000000000); // TODO

    } else {
        printf("no.\n");
    }
    return;
}

void available(uint64_t reg, char moves) {
    if(((reg >> moves) & 0x01) == 1)
        printf("yes.\n");
    else
        printf("no.\n");
}

int get_com(char * buffer) {
     int i = 0;
     while ( i < COMMANDS ) {
         if(strcmp(commands[i], buffer) == 0)
             return i;
         i++;
     }
    return -1;
}

void command_listener(char * buffer) {
    int i = 0;
    unsigned char c;
    while((c = getchar()) != '\n') {
        if(c == '\t'){
            change_shell();
        } else if (c == '\b' && i>0) {
            putchar(c);
            i--;
        } else if (c != '\b') {
            putchar(buffer[i++] = c);
        }
    }
    if (c == '\n') {
        putchar(c);
    }
    buffer[i] = 0;
}

/* int get_correct_command(char * buffer){
    int idx = 0;
    while(idx < COMMANDS){
        if(strcmp(commands[idx], buffer) == 0)
            return idx;
        idx++;
    }
    return -1;
} */

static Pcommands command_codes[] = {&ayuda, &inforeg, &features_support, &zerodiv, &wrongop};

void zerodiv(){
    try_catch_zerodiv();
}

void wrongop(){
    try_catch_ud();
}

int run_shell() {
    printf("\n");
    char buffer[MAX_BUFFER_LENGTH] = {0};
    while(1) {
        printf(">> ");
        command_listener(buffer);
        int idx = get_com(buffer);
        if(idx == -1)
            printf("No such command. Run command help to see all commands.\n");
        else {
           Pcommands command = command_codes[idx];
           command();
        }
    }
    return 0; // TODO: Manage what we return.
}
