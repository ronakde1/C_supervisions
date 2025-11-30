#include <stdio.h>

int main() {
    double arr[10];
    FILE *f = fopen("data.bin", "rb");
    size_t read = fread(arr, sizeof(double), 10, f);
    fclose(f);
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %f\n", i, arr[i]);
    }
    return 0;
}
