#include <iostream>
using namespace std;
class Vector{
    int vec[5];
public:
    Vector(int v[]);
    Vector(const Vector& obj);
    Vector operator +(const Vector& obj);
    Vector operator -(const Vector& obj);
    void print();
};
Vector::Vector(int v[]){
        for(int i=0;i<5;i++){
            vec[i] = v[i];
        }
    
}
Vector::Vector(const Vector& obj){
    for(int i=0;i<5;i++){
        vec[i] = obj.vec[i];
    }
}
Vector Vector::operator+(const Vector& obj){
    Vector result = *this;
    for(int i=0;i<5;i++){
        result.vec[i] += obj.vec[i];
    }
    return result;
}
Vector Vector::operator-(const Vector& obj){
    Vector result = *this;
    for(int i=0;i<5;i++){
        result.vec[i] -= obj.vec[i];
    }
    return result;
}
void Vector::print(){
    for(int i=0;i<5;i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main(){
    int v[5];
    for(int i=0;i<5;i++){
        cin >> v[i];
    }
    Vector V1(v); 
    for(int i=0;i<5;i++){
        cin >> v[i];
    }
    Vector V2(v);

    Vector V3 = V1 + V2;
    V3.print();
    Vector V4 = V1 - V2;
    V4.print(); 
}
