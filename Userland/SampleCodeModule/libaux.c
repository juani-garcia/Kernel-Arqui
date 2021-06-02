

int strcmp(const char * str1, const char * str2);

int strlen(const char* str){
    int i=0;
    while(str[i++]);
    return i-1;
}

int strcmp(const char * str1, const char * str2){
    while(*str1 || *str2)
        if (*(str1++) ^ *(str2++)) return *(str2-1) - *(str1-1);
    return 0;
}

