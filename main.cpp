#include"matrix.h"

int main(){
    Matrix a(3,1,{1,2,3});
    Matrix b = a.transpose(); 
    a.print();
    b.print();
    Matrix c = b*a;
    c.print();
    a.print();
    Matrix f = 15*a;
    f.print(); 

    return 0;
} 