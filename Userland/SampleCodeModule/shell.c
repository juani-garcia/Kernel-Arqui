#include <lib.h>
#define COMMANDS 5

typedef void (*Pcommnads);

static Pcommands commands_code[] = {&ayuda, &print_mem, &inforeg, &fecha_y_hora, &divbyzero};
// TODO: should be compared with strcmp
const char * commands[] = {"ayuda", "printmem", "inforeg", "fechayhora", "divbyzerocheck"};


// TODO: implement printf along with scanf, putChar and getChar in order for this functionality to work
void ayuda(){    
    printf("Los comandos disponibles son los siguientes:\n\n");
    printf("inforeg     -imprime en pantalla el valor de todos los registros.\n");
    printf("printmem    -realiza un volcado de memoria de 32 bytes a partir de la direccion que se recibe como argumento.\n");
    printf("fechayhora  -desplega en pantalla el día y la hora del sistema.\n");
    printf("ayuda       -muestra todos los comandos disponibles.\n");
}

// TODO: after merging, this function should call show_registers
void print_mem(){
    
}

static uint8_t get_command(const char * str){
    int i;
    for(i = 0; i < COMMANDS; i++){
        if(strcmp(commands[i], str) == 0)
            return i;
    }
    return -1;
}