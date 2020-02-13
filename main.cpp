#include"matrix.h"

int main(){
    // Constructor 
    Matrix<float> a(3,1,{1.1,2.5,3.0});
    Matrix<int> b(3,3,{1,2,3,4,5,6,7,8,9});
    Matrix<int> c({{1,2},{3,4}});
    a.print();
    b.print();
    //Matrix<int> c = a*b; 

    //Matrix<int> d = a.elementwiseMultiplication(b.T());
    
    //Matrix<int> r = a;
    //r.print();
    //Matrix<float> r(3,1,{1.5,2.3,33});
    //Matrix<float> ss(1,3,{1.5,2.3,33});

    //Matrix<float> e = r*ss;
    //e.print();
    //a.print();
    //b.print();
    //c.print();
    //d.print();

    
    return 0;
} 