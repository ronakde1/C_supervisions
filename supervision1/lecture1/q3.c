#include <stdio.h>
void bubblesort(int* arr, int size){
    int sorted = 0;
    int temp;
    while (!sorted){
        sorted = 1;
        for (int i = 0; i < size-1; i++){
            if (arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = 0;
            }
        }
    }
}
void printall(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d",arr[i]);
    }
}
int main(){
    int size = 9;
    int arr[9] = {9,3,2,4,1,8,6,7,5};
    bubblesort(arr,size);
    printall(arr,size);
    return 0;
}
