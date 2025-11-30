#define ARRAY_SIZE 100000000
#include <stdio.h>
#include <time.h>

int adata[ARRAY_SIZE];
int i; int j;
int initialise(int dasize){
    for (j=0; j!=dasize; j++)
    for (i=0; i!=dasize; i++)
    adata[ i + (j*dasize)] = i;
    return 0;
}
int cacheload(){
    int volatile sum = 0;
    for (i = ARRAY_SIZE; i != 0; i--){
        sum += adata[i];
    }
    return sum;
}

int dm_sumarray0(int dasize){ 
    int sum = 0; 
    for (i=0; i!=dasize; i++)
    for (j=0; j!=dasize; j++){
        sum += adata[ j + (i*dasize)];
    }
return sum;}

int dm_sumarray1(int dasize){ 
    int sum=0; for (i=0; i!=dasize; i++)
    for (j=0; j!=dasize; j++){
        sum += adata[ i + (j*dasize)];
    }
    return sum; }

int dm_sumarray2(int dasize){ 
        int sum=0; for (j=0; j!=dasize; j++){ 
            int i=0;
        while (i!=dasize){
            int v = adata[ i + (j*dasize)];
            sum += v;
            // Data-dependent loop - cannot unroll at compile time or prefetch during execution?
            i = v+1;
        }
    }
    return sum; }

int main(){
    volatile int dasize = 8000;
    int iterations = 1000;
    initialise(dasize);
    int load = cacheload();
    clock_t start = clock();
    int result0 = dm_sumarray0(dasize);
    
    clock_t time0 = clock();
    int result1 = dm_sumarray1(dasize);

    clock_t time1 = clock();

    int result2 = dm_sumarray2(dasize);

    
    clock_t time2 = clock();
    double time_taken0 = (double)(time0 - start);
    double time_taken1 = (double)(time1 - time0);
    double time_taken2 = (double)(time2 - time1);
    printf("0: %f \n1: %f \n2: %f",time_taken0,time_taken1,time_taken2);

}