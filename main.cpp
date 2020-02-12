#include"matrix.h"

int main(){
    Matrix a(3,1,{1,2,3.5});
    Matrix b = a.transpose();
    Matrix c = a*b; 
    Matrix d = a.elementwiseMultiplication(b.T());
    
    a.print();
    b.print();
    c.print();
    d.print();

    
    return 0;
} 