#include <lib.h>
#include <shell.h>
#define COMMANDS 4
#define MAX_BUFFER_LENGTH 1

static char buffer[MAX_BUFFER_LENGTH] = {0};

static char get_command();
static void command_listener();
void ayuda(void);
void inforeg(void);

typedef void (*Pcommands)(void);

// TODO: should be compared with strcmp
static char * commands[COMMANDS] = {"ayuda", "inforeg", "support"};

// TODO: implement printf along with scanf, putChar and getChar in order for this functionality to work
void ayuda() {
    printf("Los comandos disponibles son los siguientes:\n\n");
    printf("inforeg       -imprime en pantalla el valor de todos los registros.\n");
    printf("printmem      -realiza un volcado de memoria de 32 bytes a partir de la direccion que se recibe como argumento.\n");
    printf("fechayhora    -desplega en pantalla el día y la hora del sistema.\n");
    printf("ayuda         -muestra todos los comandos disponibles.\n");
}

// TODO: after merging, this function should call show_registers
void inforeg(){
    
}

void features_support(){
    printf("cpuid support: ");
    if(check_cpuid_support()){
        printf("yes.\n");
    } else {
        printf("no.\n");
    }
}

static Pcommands command_codes[] = {&ayuda, &inforeg, &features_support};

static char get_command() {
    int i;
    for (i = 0; i < COMMANDS; i++) {
        if(strcmp(commands[i], buffer) == 0)
            return i;
    }
    return -1;
}

static void command_listener() {
    int i = 0;
    unsigned char c;
    while((c = getchar()) != '\n' && c != '\t') {
        if (c == '\b' && i>0) {
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


int run_shell() {
    while(1) {
        printf(">> ");
        command_listener();
        int idx = get_command();
        if(idx == -1)
            printf("No such command. Run command \n>> help\n to see all commands.\n");
        else {
           Pcommands command = command_codes[idx];
           command();
        }
    }
    return 0; // TODO: Manage what we return.
}
