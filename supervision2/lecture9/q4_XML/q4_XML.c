#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 1000000

int main() {
    FILE *f = fopen("q4_XML.xml", "w");
    clock_t start = clock();

    fprintf(f, "<?xml version=\"1.0\"?>");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        fprintf(f, "<V>1.0</V>");
    }
    clock_t end = clock();
    double time_taken = (double)(end - start);
    printf("Time taken: %f",time_taken);

    fclose(f);
    return 0;
}
