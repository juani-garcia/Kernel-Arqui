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
    //print(STDOUT, str, strlen(str));
}

/* 
int myprintf (char * str, ...)
{
	va_list vl;
	int i = 0, j=0;
		char buff[100]={0}, tmp[20];
		va_start( vl, str ); 
		while (str && str[i])
		{
		  	if(str[i] == '%')
		  	{
 		    i++;
 		    switch (str[i]) 
 		    {
	 		    case 'c': 
	 		    {
	 		        buff[j] = (char)va_arg( vl, int );
	 		        j++;
	 		        break;
	 		    }
	 		    case 'd': 
	 		    {
	 		        itoa(va_arg( vl, int ), tmp, 10);
	 		        strcpy(&buff[j], tmp);
	 		        j += strlen(tmp);
		           break;
		        }
		        case 'x': 
		        {
		           itoa(va_arg( vl, int ), tmp, 16);
		           strcpy(&buff[j], tmp);
		           j += strlen(tmp);
		           break;
		        }
        	}
     	} 
     	else 
	    {
	       	buff[j] =str[i];
	       	j++;
	    }
	    i++;
	} 
    fwrite(buff, j, 1, stdout); 
    va_end(vl);
    return j;
 } */


int getchar() {
    char c = 0;
    read(STDIN, &c, 1);
    return c;
}

void putchar(char c) {
    print(STDOUT, &c, 1);
}
