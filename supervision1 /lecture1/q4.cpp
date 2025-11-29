#include <stdio.h>
void bubblesort(char* arr, int size){
    int sorted = 0;
    char temp;
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
void printall(char* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%c",arr[i]);
    }
}
int main(){
    char arr[6] = {'b','c','a','y','i'};
    bubblesort(arr,6);
    printall(arr,6);
    return 0;
}
