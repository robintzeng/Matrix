#include"matrix.h"
#include <typeinfo>
int main(){
    // Constructors 
    Matrix<float> a(3,1,{1.1,2.5,3.0}); // by 1D vector
    Matrix<int> b({{1,2},{3,4}}); // by 2D vector
    Matrix<double> c(4,4);// create an empty vector
    // Transpose 
    Matrix<float> d = a.transpose();
    //Elementwise Multiplication
    Matrix<float> e = a.elementwiseMultiplication(d.transpose());
    // Type Casting  
    Matrix<int> f = e;
    a = Matrix<int>(a);
    // Matrix multiplcation
    Matrix<float> g = a*d;
    Matrix<int>   h = a*d;

    Matrix<float> i = d*a;
    Matrix<int>   j = d*a;
    
    d = Matrix<int>(d);
    Matrix<float> k = a*d;

    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    f.print();
    g.print();
    h.print();
    i.print();
    j.print();
    std:: cout<<typeid(k(0,0)).name()<< std::endl;
    return 0;
} 