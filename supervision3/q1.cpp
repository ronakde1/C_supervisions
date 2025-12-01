#include <iostream>
using namespace std;
class LinkList{
    public: 
    unsigned int head;
    LinkList* next;
    LinkList(int head_val = -1, LinkList* next_val = nullptr): head(head_val), next(next_val){}

    LinkList(int* arr, int size){
        if (size == 0){
            head = -1;
            next = nullptr;
            return;
        }
        LinkList* prev_next = nullptr;
        int prev_head = arr[size-1];
        for (int i = size-2; i >= 0; i--){
            prev_next = new LinkList(prev_head, prev_next);;
            prev_head = arr[i];
        }
        this->head = prev_head;
        this->next = prev_next;
    }
    int pop(){
        int old_head = this->head;
        if (this->next){
            this->head = this->next->head;
            this->next = this->next->next;
            }
        return old_head;
    }

    void printall(){
        cout << head <<"\n";
        if (next){
        next->printall();
        }
    }
    void insert(int value) {
        this->next = new LinkList(this->head, this->next);;
        this->head = value;
    }
};
int main(){
    int test[] = {1,2,3,4,5};
    LinkList l1(test,5);
    LinkList l4;
    cout << l1.pop() << endl;
    cout << l1.pop() << endl;

    l1.printall();

    return 0;
}