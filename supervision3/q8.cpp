#include <iostream> 
using namespace std;
template<typename T> class Stack{
    public:
    Stack* prev;
    T top;
    Stack(T top_val = -1, Stack* prev_val = nullptr): top(top_val), prev(prev_val){}
    void insert(T new_top){
        this->prev = new Stack(top,prev);
        top = new_top;
    }
    ~Stack(){
        Stack* prev_copy = prev;
        while(prev_copy){
            Stack* next = prev_copy -> prev;
            prev_copy->prev = nullptr; 
            delete prev_copy;
            prev_copy = next;
        }
    }
    Stack(const Stack& s): top(s.top), prev(nullptr){
        Stack* s_new = this;
        Stack* s_prev = s.prev;
        while(s_prev){
            s_new->prev = new Stack(s_prev->top);
            s_new = s_new->prev;
            s_prev = s_prev -> prev;
        } 
    }
Stack& operator=(const Stack& s){
    if (this == &s) return *this;
    Stack* current = prev;
    while (current) {
        Stack* next = current->prev;
        delete current;
        current = next;
    }
    top = s.top;
    prev = nullptr;
    Stack* this_copy = this;
    Stack* s_copy = s.prev;
    while (s_copy) {
        this_copy->prev = new Stack(s_copy->top);
        this_copy = this_copy->prev;
        s_copy = s_copy->prev;
    }
    return *this;
}


    T pop(){
        T old_top = top;
        if (prev) {
            Stack* old_prev = prev;
            top = prev->top;
            prev = prev->prev;
            old_prev->prev = nullptr;
            delete old_prev;
        }
        return old_top;
    }
    void printall(){
        Stack* thiscpy = this;
        while (thiscpy){
            cout<<thiscpy->top<<" ";
            thiscpy = thiscpy-> prev;
        }
        cout << endl;
    }
};
int main(){
    Stack<double> hi(0.1);
    hi.insert(0.2);
    hi.insert(0.3);
    hi.insert(0.4);
    hi.printall();
    Stack<double> hi2 = hi;
    cout << hi.pop() << endl;
    hi.printall();
    hi2.printall();
}