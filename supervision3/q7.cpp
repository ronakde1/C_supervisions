#include <iostream> 


enum result{SUCCESS,ERR_NOTFOUND, ERR_MALFORMED};
int process_file(char *name) {}
class files{
    FILE *p; 
    files(char *name):p(fopen(name, "r")){}
    ~files(){
        if (p){
            fclose(p);
        }
    }
    int process_file(){
        if (p == NULL) return ERR_NOTFOUND;
        while(...){
            ...
            if (...) return ERR_MALFORMED;
            process_one_option();
            ...
        }
        return SUCCESS;
    }
};
