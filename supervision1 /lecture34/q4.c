#include <stdio.h>
const char OPERATORS[] = {'-', 'x', '/', '+'};
typedef struct {
    char optr;
    int intVal;
} StackVal;



void printall(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf(" %d ", arr[i] );
    }
    printf("\n");
}

int isInt(char* str){
    for (int i = 0; i < 5; i++){
        if (str[0] == OPERATORS[i]){
            return 0;
        }
    }
    return 1;
}
int countSize(char* str){
    int countVal = 0;
    while (*str++){
        countVal ++;
    }
    return countVal;
}
int toInt(char* str){
    int start = 1;
    int acc = 0;
    for (int i = countSize(str)-1; i >=0; i--){
        acc += (str[i]-48) * start;
        start *= 10;

    }
    return acc;
}
int eval(char optr, int arg1, int arg2){
    switch(optr) 
     {
    case '+': return arg1 + arg2;
    case '-': return arg1 - arg2;
    case 'x': return arg1 * arg2;
    case '/':  
        if (arg2 != 0){
            return arg1 / arg2;
        } 
        else{
            printf("division by 0 error \n");
            return 0;
        }
    default: return 0;

    }
}
int solve(StackVal* argArr, int argnum){
    int stack[argnum];
    for (int i = 1; i < argnum; i++){
        stack[i] = 0;
    }
    int top = 0;
    for (int i = 0; i <( argnum * 2) -1 ; i++){
        if (argArr[i].optr == 'n'){
            stack[top] = argArr[i].intVal;
            top++;
        } else{
            stack[top-2] = eval(argArr[i].optr, stack[top-2], stack[top-1]); 
            top --;
        }
    printall(stack, argnum); 
    printf("%d \n", top);
    };
    return stack[0];
}

int reversePolishSolver(int argc, char *argv[]){
    StackVal argArr[argc-1];
    int intcount = 0;
    int opcount = 0;
    
    for (int i = 1; i < argc; i++) {
        //printf("Argument %d: %s\n", i, argv[i]);
        if (isInt(argv[i])){
            argArr[i-1].optr = 'n';
            argArr[i-1].intVal =toInt(argv[i]);
            intcount ++;
        } else{
            argArr[i-1].optr = *argv[i];
            argArr[i-1].intVal = 0;
            opcount++;
        }
    }

    if(opcount != intcount - 1){
        printf("Invalid reverse polish format \n");
        return 0;
    }
    if(argArr[0].optr != 'n' || argArr[1].optr != 'n' ){
        printf("Invalid reverse polish format \n");
        return 0;
    }
    int answer = solve(argArr, intcount);
    printf("ANSWER: %d \n", answer);
    return answer;
}

int main(int argc, char *argv[]) {
    reversePolishSolver(argc, argv);
    return 0;
}
