#include <lib.h>
#include <stdarg.h> //Nueva librería incluida para myprintf

int strcmp(char * str1, char * str2);

int strlen(const char* str){
    int i=0;
    while(str[i++]);
    return i-1;
}

int strcmp( char * str1, char * str2) {
    while(*str1 || *str2)
        if (*(str1++) ^ *(str2++)) return *(str2-1) - *(str1-1);
    return 0;
}

//TODO: should be erased and replaced by myprintf
void printf(const char * str) {
    print(STDOUT, str, strlen(str));
}

/* void Myprintf(char* format,...) 
{ 
    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
} 

char *convert(unsigned int num, int base) 
{ 
    static char Representation[]= "0123456789ABCDEF";
    static char buf[50]; 
    char *ptr; 

    ptr = &buf[49]; 
    *ptr = '\0'; 

    do 
    { 
        *--ptr = Representation[num%base]; 
        num /= base; 
    }while(num != 0); 

    return(ptr); 
} */

int getchar() {
    char c = 0;
    read(STDIN, &c, 1);
    return c;
}

void putchar(char c) {
    print(STDOUT, &c, 1);
}
