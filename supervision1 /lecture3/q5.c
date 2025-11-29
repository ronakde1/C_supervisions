#include <stdio.h>
int main(){
    size_t i;
    i = sizeof(char);
    printf("a: %zu \n",i);
    i = sizeof(int);
    printf("b: %zu \n",i);
     int a; i = sizeof a;
    printf("c: %zu \n",i);
    char b[5]; i = sizeof(b);
    printf("d: %zu \n",i);
    char *c=b; i = sizeof(c);
    printf("e: %zu \n",i);
    struct {int d;char e;} s; i = sizeof s;
    printf("f: %zu \n",i);
    int j[5];
    i = sizeof j;
    printf("g: %zu \n",i);
    int j1[1][10];
    i = sizeof j1;
    printf("h: %zu \n",i);
    return 0;
}