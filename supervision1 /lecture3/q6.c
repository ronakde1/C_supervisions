#include <stdio.h>
#define BUFSIZE 1024
int main(void) {
    FILE *fp;
    char buffer[BUFSIZE];
    long long count = 0;
    if ((fp=fopen("rockyou.txt","rb")) == 0) {
        perror("fopen error:");
        return 1;
    }

    while(!feof(fp)) {
        int r = fread(buffer,sizeof(char),BUFSIZE,fp);
        for (int i = 0; i < r; i++){
            count += (unsigned char) buffer[i];
        }
    }
    fclose(fp);
    printf("%lld",count);
    return 0;
}