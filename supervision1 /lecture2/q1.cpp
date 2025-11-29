#include <stdio.h>

int cntlower(char str[]) {
    int pos = 0;
    int count = 0;
    while (str[pos] != '\0') {
        if ('a' <= str[pos] && str[pos] <= 'z') {
            count++;
        }
        pos++;
    }
    return count;
}

int main() {
    printf("%d \n", 'a');
    printf("%d \n", 'z');
    printf("%d \n", 'A');
    printf("%d \n", 'Z');
    printf("%d \n", cntlower("HelloWorld"));
    return 0;
}
