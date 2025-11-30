#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(t, x,y) {t temp = (x); (x) = (y); (y) = (temp);};
// #define SWAP(x,y) {(x) = ((x)^(y)); (y) = ((x)^(y)); (x) = ((x)^(y));};

// a = a ^ b
// b = a ^ b
// a = a ^ b
int f(int x){
    return x * x;
}

void swap_test(){
    int v[3] = {1,2,3};
    int w[5] = {4,5,6,7,8};
    int i = 0;
    int x = 2;
    int a = 15;
    int b  = 12;
    printf("%d \n",v[i+1]);
    printf("%d \n",w[f(x)]);
    SWAP(int, a,b)
    printf("%d %d",a,b);
}

int main(){
    swap_test();
}


void merge(int* arr, int start, int middle, int end){
    int pos = start;
    int leftidx = 0;
    int rightidx = middle;
    int length = middle - start;
    int *copy_arr = (int *)malloc(length * sizeof(int));
    memcpy(copy_arr, &arr[start], length * sizeof(int));

    while (leftidx < length && rightidx < end){
        if (copy_arr[leftidx] < arr[rightidx]){
            arr[pos++] = copy_arr[leftidx++];
        } else{
            arr[pos++] = arr[rightidx++];
        }
    }
    while (leftidx < length){arr[pos++] = copy_arr[leftidx++];}
    free(copy_arr);
}

void mergesort_rec(int* arr, int start, int end){
    if (end - start <= 1){return;}
    int middle = (start + end)/2;
    mergesort_rec(arr,start,middle);
    mergesort_rec(arr,middle,end);
    merge(arr,start,middle,end);
}