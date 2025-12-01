#include <iostream>
#include <stdio.h>
using namespace std;

class LinkList {
public:
    unsigned int head;
    LinkList* next;

    LinkList(int head_val = -1, LinkList* next_val = nullptr)
        : head(head_val), next(next_val) {}

    LinkList(int* arr, int size) {
        if (size == 0) {
            head = -1;
            next = nullptr;
            return;
        }
        LinkList* prev_next = nullptr;
        int prev_head = arr[size-1];
        for (int i = size-2; i >= 0; i--) {
            prev_next = new LinkList(prev_head, prev_next);
            prev_head = arr[i];
        }
        this->head = prev_head;
        this->next = prev_next;
    }
    ~LinkList() {
        delete next;
        next = nullptr;
    }

    LinkList& operator=(const LinkList& ll) {
        if (this == &ll) return *this;
        delete next;
        next = nullptr;

        head = ll.head;
        LinkList* this_copy = this;
        LinkList* ll_copy = ll.next;
        while (ll_copy) {
            this_copy->next = new LinkList(ll_copy->head);
            this_copy = this_copy->next;
            ll_copy = ll_copy->next;
        }
        return *this;
    }

    LinkList(const LinkList& other) : head(other.head), next(nullptr) {
        LinkList* cur_new = this;
        LinkList* cur_other = other.next;
        while (cur_other) {
            cur_new->next = new LinkList(cur_other->head);
            cur_new = cur_new->next;
            cur_other = cur_other->next;
        }
    }
    int pop() {
        int val = head;
        if (next) {
            LinkList* old_next = next;
            head = next->head;
            next = next->next;
            old_next->next = nullptr;
            delete old_next;
        }
        return val;
    }

    void printall() {
        cout << head << "\n";
        if (next) next->printall();
    }

    void insert(int value) {
        this->next = new LinkList(this->head, this->next);
        this->head = value;
    }
};

int main() {
    int test[] = {1,2,3,4,5};
    LinkList l1(test+1,4), l2(test,5);
    LinkList l3 = l2, l4;
    l4 = l1;
    printf("%d %d %d\n", l1.pop(), l3.pop(), l4.pop());
    return 0;
}
