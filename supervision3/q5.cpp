#include <iostream>
using namespace std;

class A {
public:
    int* arr;
    A(int arr_val[3]) {
        arr = new int[3];
        for (int i = 0; i < 3; i++)
            arr[i] = arr_val[i];
    }
    ~A() {
        cout << "A";
        delete arr;
    }
};
class B : public A {
public:
    int* arr2;
    B(int arr_val1[3], int arr_val2[3])
        : A(arr_val1)
    {
        arr2 = new int[3];
        for (int i = 0; i < 3; i++)
            arr2[i] = arr_val2[i];
    }
    ~B() {
        cout << "B";
        delete arr2;
    }
};
int main() {
    int x[3] = {1,2,3};
    int y[3] = {6,7,8};
    A* Bclass = new B(x, y);
    delete Bclass;
    return 0;
}

