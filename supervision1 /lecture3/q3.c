#include <stdio.h>
struct hi{int a; int b; int c;};

int main(){
    struct hi hello = {1,3,5};
    struct hi* p = &hello;
    int i = 0;
    printf("%d",p->a);
    return 0;
}