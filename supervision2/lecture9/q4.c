#include <stdio.h>

int main() {
    FILE *fptr;
    double arr[10] = {0.1,2.0,2.0,3.5,4.0,5.0,6.0,7.0,8.0,9.0};

    fptr = fopen("data.bin", "wb");

    size_t written = fwrite(arr, sizeof(double), 10, fptr);
    fclose(fptr);
    return 0;
}
