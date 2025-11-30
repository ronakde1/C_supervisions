#include <stdio.h>
#define DATASIZE 1048575

typedef struct ll {int pair_idx; short free;} ll;
ll memory[DATASIZE] = {0};
void initialise(){
    if (memory[0].free == 0 && memory[0].pair_idx == 0){
    memory[0].free = 1;
    memory[0].pair_idx = DATASIZE-1;
    memory[DATASIZE-1].free = 1;
    memory[DATASIZE-1].pair_idx = 0;
    }
}

void* assign(int pos1, int space){
    int old_idx = memory[pos1].pair_idx;

    if (old_idx - pos1 - 1 == space) {
        memory[pos1].free = 0;
        memory[old_idx].free = 0;
        return (void*)&memory[pos1];
    }
    int new_idx = pos1 + space + 1;

    memory[pos1].free = 0;
    memory[pos1].pair_idx = new_idx;

    memory[new_idx].free = 0;
    memory[new_idx].pair_idx = pos1;

    new_idx ++;
    memory[new_idx].free = 1;
    memory[new_idx].pair_idx = old_idx;
    memory[old_idx].free = 1;
    memory[old_idx].pair_idx = new_idx;
    
    return (void*)&memory[pos1];
}
void* malloc_(int size_){
    initialise();
    if (size_ <= 0) return NULL;
    int bytes_assign = (size_ + 7) / 8;
    int pos = 0;
    while (pos < DATASIZE) {
        int pair = memory[pos].pair_idx;
        if (memory[pos].free == 1) {
            int usable = pair - pos - 1;
            if (usable >= bytes_assign) {
                return assign(pos, bytes_assign);
            }
        }
        pos = pair + 1;
    }
    return NULL;
}

void free_(int pos){
    initialise();
    if (pos < 0 || pos >= DATASIZE) return;
    if (memory[pos].free == 0) {
        int after_pos = memory[pos].pair_idx;
        int after_free = 0;
        int after_idx = 0;
        int before_free = (pos > 0 && memory[pos-1].free == 1);
        if (after_pos + 1 < DATASIZE && memory[after_pos + 1].free == 1) {
            after_free = 1;
            after_idx = memory[after_pos + 1].pair_idx;
        } 

        if (!before_free && !after_free){
            memory[pos].free = 1;
            memory[after_pos].free = 1;
            return;
        } 
        if (!before_free && after_free){

            memory[pos].free = 1;
            memory[pos].pair_idx = after_idx;

            memory[after_idx].free = 1;
            memory[after_idx].pair_idx = pos;
            return;
        }
        if (before_free && !after_free){
            int before_pos = memory[pos-1].pair_idx;

            memory[before_pos].free = 1;
            memory[before_pos].pair_idx = after_pos;

            memory[after_pos].free = 1;
            memory[after_pos].pair_idx = before_pos;
            return;
        }
        if (before_free && after_free){
            int before_pos = memory[pos-1].pair_idx;

            memory[before_pos].free = 1;
            memory[before_pos].pair_idx = after_idx;

            memory[after_idx].free = 1;
            memory[after_idx].pair_idx = before_pos;
            return;
        }
    }
}




int main() {
}