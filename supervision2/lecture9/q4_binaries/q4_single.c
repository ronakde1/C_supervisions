#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 1000000

int main() {
    FILE *fptr;
    float arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = 1;
    }
    fptr = fopen("single.bin", "wb");
    clock_t start = clock();

    fwrite(arr, sizeof(float), ARRAY_SIZE, fptr);
    clock_t end = clock();
    double time_taken = (double)(end - start);
    printf("Time taken: %f",time_taken);
    fclose(fptr);
    return 0;
}