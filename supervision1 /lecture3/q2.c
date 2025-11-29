#include <stdio.h>
const char *strfind(const char *needle, const char *hay);


int str_cmp(const char *haypos, const char *needle) {
    while (*haypos == *needle && *needle != '\0') {
        haypos++;
        needle++;
    }
    return (*needle == '\0');
}

const char *strfind(const char *needle, const char *hay) {
    while (*hay) {
        if (str_cmp(hay, needle)){return hay;}
        hay++;
    }
    return 0;
}



int main(){
    const char* e = strfind("llo","hello");
    printf("%c",*e);
    return 0;
}