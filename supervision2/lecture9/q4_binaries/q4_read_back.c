#include <stdio.h>

#define ARRAY_SIZE 1000000
#define TYPE float //options: double, float, int
#define TYPE_NAME "single" //options: double, single, int


int main() {
    FILE *f = fopen(TYPE_NAME".bin", "rb");
    TYPE arr[ARRAY_SIZE];
    size_t read = fread(arr, sizeof(TYPE), ARRAY_SIZE, f);  
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    fclose(f);

    int count = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        count += (int)arr[i];
    }

    printf("Number of %s: %d\n",TYPE_NAME, count);
    printf("Filesize: %zu", filesize);

    return 0;
}
