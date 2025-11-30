#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 1000000

int main() {
    FILE *fptr;
    double arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = 1.0;
    }
    
    fptr = fopen("q4_ASCII.txt", "w");
    clock_t start = clock();

  for (int i = 0; i < ARRAY_SIZE; i++) {
        fprintf(fptr, "%f\n", arr[i]);
    }
    clock_t end = clock();
    double time_taken = (double)(end - start);
    printf("Time taken: %f",time_taken);

    fclose(fptr);
    return 0;
}
