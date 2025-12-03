#include <iostream>
using namespace std;
bool isprime_rec(int val, int test){
    if (test == 1) return true;
    return (val % test != 0) && isprime_rec(val, test-1);
}

bool isprime(int val){
    return isprime_rec(val, val/2);
}
template<int n, int testval = n/2> struct primecheck{
    enum{value = (n % testval != 0) && primecheck<n,testval-1>::value};
};
template<int n> struct primecheck<n,2>{
    enum {value = n % 2 != 0};
};

template<int n> struct primecheck<n,1>{
    enum {value = true};
};

int main(){

    constexpr int val = primecheck<7>::value;

    cout << 2 << " " << primecheck<2>::value << endl;
    cout << 3 << " " << primecheck<3>::value << endl;
    cout << 4 << " " << primecheck<4>::value << endl;
    cout << 5 << " " << primecheck<5>::value << endl;
    cout << 6 << " " << primecheck<6>::value << endl;
    cout << 7 << " " << val << endl;
    cout << 8 << " " << primecheck<8>::value << endl;
    cout << 9 << " " << primecheck<9>::value << endl;
    

}
