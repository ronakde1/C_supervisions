#include <iostream>
using namespace std;
class Vector{
    public:
    double vect[2];
    Vector(double vect_val[2] = nullptr){
        if (vect_val){
            for (int i = 0; i < 2; i++){
                vect[i] = vect_val[i];
            }
        }
    }
    Vector operator=(Vector vect_b){
        for (int i = 0; i < 2; i++){
            vect[i] = vect_b.vect[i];
        }
        return *this;
    }
    Vector operator+(Vector vect_b){
        Vector result;
        for (int i = 0; i < 2; i++){
            result.vect[i] = vect[i] + vect_b.vect[i];
        }
        return result;
    }
    Vector operator-(Vector vect_b){
        Vector result;
        for (int i = 0; i < 2; i++){
            result.vect[i] = vect[i] - vect_b.vect[i];
        }
        return result;
    }
    void printall(){
        for (int i = 0; i < 2; i++){
            cout << vect[i] <<endl;
        }
    }
};