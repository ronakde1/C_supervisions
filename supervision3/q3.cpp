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

class Matrix{
    public:
    double mat[2][2];
    Matrix(double (*mat_val)[2]= nullptr) {
        if (mat_val){
            for (int i = 0; i< 2; i++){
                for (int j = 0; j< 2; j++){
                    mat[i][j] = mat_val[i][j];
                }
            }
        } else{
            for (int i = 0; i< 2; i++){
                for (int j = 0; j< 2; j++){
                    mat[i][j] = 0;
                }
            }
        }
    }
    Matrix(const Matrix& mat_b) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat[i][j] = mat_b.mat[i][j];
            }
        }
    }
    Matrix operator+(Matrix mat_b){
        Matrix result(*this);

        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j]+ mat_b.mat[i][j];
            }
        }
        return result;
    }
    Matrix operator+(double constval){
        Matrix result(*this);

        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j]+ constval;

            }
        }
        return result;
    }

    Matrix operator-(Matrix mat_b){
        Matrix result(*this);

        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j] - mat_b.mat[i][j];
            }
        }
        return result;
    }
    Matrix operator-(double constval){
        Matrix result(*this);

        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j]- constval;

            }
        }
        return result;
    }


    Matrix operator/(double constval){
        Matrix result(*this);
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j]/ constval;
            }
        }
        return result;
    }

    Matrix operator/(int constval){
        Matrix result(*this);
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j]/ constval;
            }
        }
        return result;
    }

    Matrix operator*(double constval){
        Matrix result(*this);
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j] * constval;
            }
        }
        return result;
    }

    Matrix operator*(int constval){
        Matrix result(*this);
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.mat[i][j] = mat[i][j] * constval;
            }
        }
        return result;
    }
    Matrix operator*(Matrix mat_b){
        Matrix result;
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                for (int k = 0; k < 2; k++){
                    result.mat[i][k] += mat[i][j] * mat_b.mat[j][k];
                }
            }
        }
        return result;
    }

    Vector operator*(Vector vect_b){
        Vector result = {0};
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                result.vect[i] += mat[i][j] * vect_b.vect[j];
            }
        }
        return result;
    }
    Matrix& operator=(const Matrix mat_b){
        if (this == &mat_b) return *this;
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                mat[i][j] = mat_b.mat[i][j];
            }
        }
        return *this;
    }

    

    void printall(){
        for (int i = 0; i< 2; i++){
            for (int j = 0; j< 2; j++){
                cout<< mat[i][j] << ' ';
            }
            cout << endl;
        }
    }

};
int main(){
    double hi2D[2][2] = {{1,2},{3,4}};
    Matrix hi_mat = Matrix(hi2D);
    double hi1D[2] = {1,2};
    Vector hi_vect = Vector(hi1D);

    Vector new_vect = hi_mat * hi_vect;
    Matrix hi_2_mat = hi_mat * hi_mat;

    hi_2_mat.printall();
    new_vect.printall();

    return 0;
}