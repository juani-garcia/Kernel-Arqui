#include <lib.h>
#include <shell.h>
#include <cpuid.h>
#define COMMANDS 4
#define MAX_BUFFER_LENGTH 256

char buffer[MAX_BUFFER_LENGTH] = {0};

int get_com();
int get_correct_command();
void command_listener();
void ayuda(void);
void inforeg(void);
void available(uint64_t reg, char moves);
void features_support(void);

typedef void (*Pcommands)(void);

// TODO: should be compared with strcmp
static char * commands[COMMANDS] = {"ayuda", "inforeg", "support"};

// TODO: implement printf along with scanf, putChar and getChar in order for this functionality to work
void ayuda() {
    printf("Los comandos disponibles son los siguientes:\n\n");
    printf("inforeg       -imprime en pantalla el valor de todos los registros.\n");
    printf("printmem      -realiza un volcado de memoria de 32 bytes a partir de la\n");
    printf("               direccion que se recibe como argumento.\n");
    printf("fechayhora    -desplega en pantalla el dia y la hora del sistema.\n");
    printf("ayuda         -muestra todos los comandos disponibles.\n");
}

// TODO: after merging, this function should call show_registers
void inforeg(){
    get_info_reg();
}

void features_support(){
    printf("cpuid support: ");
    if(check_cpuid_support()){
        printf("yes.\n");
        uint32_t f_arg = 1, s_arg = 1, t_arg = 0;
        get_cpuid_info(&f_arg, &s_arg, &t_arg);

        printf("sse support: ");
        available(s_arg, 25);
        printf("sse2 support: ");
        available(s_arg, 26);
        printf("sse3 support: ");
        available(f_arg, 0);
        printf("sse4.1 support: ");
        available(f_arg, 19);
        printf("sse4.2 support: ");
        available(f_arg, 20);
        printf("aesni support: ");
        available(f_arg, 25);
        printf("pclmulqdq support: ");
        available(f_arg, 1);
        printf("avx support: ");
        available(f_arg, 28);
        printf("f16c support: ");
        available(f_arg, 29);
        printf("fma support: ");
        available(f_arg, 12);

        f_arg = 7; s_arg = 0;
        get_cpuid_info(&f_arg, &s_arg, &t_arg);
        printf("avx2 support: ");
        available(t_arg, 6);
        printf("vpclmulqdq support: ");
        available(f_arg, 10);
        printf("vaesni support: ");
        available(t_arg, 0000000000000000000); // TODO

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

int get_com() {
     int i = 0;
     while ( i < COMMANDS ) {
         if(strcmp(commands[i], buffer) == 0)
             return i;
         i++;
     }
    return -1;
}

void command_listener() {
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

int get_correct_command(){
    int idx = 0;
    while(idx < COMMANDS){
        if(strcmp(commands[idx], buffer) == 0)
            return idx;
        idx++;
    }
    return -1;
}

static Pcommands command_codes[] = {&ayuda, &inforeg, &features_support};

int run_shell() {
    printf("\n");
    while(1) {
        printf(">> ");
        command_listener();
        //ayuda();
        //printf(buffer);
        int idx = get_correct_command();
        if(idx == -1)
            printf("No such command. Run command help to see all commands.\n");
        else {
           Pcommands command = command_codes[idx];
           command();
        }
    }
    return 0; // TODO: Manage what we return.
}
