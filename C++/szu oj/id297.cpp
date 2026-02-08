#include<iostream>
using namespace std;

class Matrix{
private:
    int** matrix;
    int rows,cols;
public:
    Matrix(int r,int c):rows(r),cols(c){
        matrix = new int*[rows];
        for(int i=0;i<rows;i++){
            matrix[i] = new int[cols];
            for(int j=0;j<cols;j++){
                matrix[i][j] = 0;
            }
        }
    }
    void setValue(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin >> matrix[i][j];
            }
        }
    }
    Matrix operator+(Matrix &m){
        Matrix result(m.rows,m.cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                result.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator-(Matrix &m){
        Matrix result(m.rows,m.cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
            }
        }
        return result;
    }
    void print(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix(){
        if(matrix == nullptr)
            return;
        for(int i=0;i<rows;i++){
            if(matrix[i] == nullptr)
                continue;
            delete matrix[i];
        }
    } 
};

int main(){

    int t;
    cin >> t;
    int rows,cols;
    while(t--){
        cin >> rows >> cols;
        Matrix A(rows,cols);
        A.setValue();
        Matrix B(rows,cols);
        B.setValue();

        Matrix C = A+B;
        cout << "Add:" << endl;
        C.print();

        Matrix D = A-B;
        cout << "Minus:" << endl;
        D.print();
        cout << "-----------------" << endl;
    }

    return 0;
}