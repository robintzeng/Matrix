#include"matrix.h"
#include <typeinfo>

void TestConstructors(){
    // Constructors 
    Matrix<float>  a(3,1,{1.1,2.5,3.0}); // by 1D vector
    Matrix<int>    b({{1,2},{3,4}}); // by 2D vector
    Matrix<double> c(4,4);// create an empty vector
    a.print();
    b.print();
    c.print();
};
void TestTranspose(){
    // Transpose 
    Matrix<float> a(3,1,{1.1,2.5,3.0});
    Matrix<float> b = a.transpose();
    a.print();
    b.print();
}
void TestElementwiseMultiplication(){
    //Elementwise Multiplication
    Matrix<int>a({{1,2},{3,4}});
    Matrix<int>b({{2,2},{2,2}});
    Matrix<int>c = a.elementwiseMultiplication(b);
    a.print();
    b.print();
    c.print();
}
void TestTypeCasting(){
     // Type Casting
    Matrix<float> a(3,1,{1.1,2.5,3.0});
    a.print();
    std:: cout<<"The element type in a is "<<typeid(a(0,0)).name()<< std::endl;
    
    Matrix<int> b = a;
    b.print();
    std:: cout<<"The element type in b is "<<typeid(b(0,0)).name()<< std::endl;
    
    a = Matrix<int>(a);
    a.print();
    std:: cout<<"The element type in a is "<<typeid(a(0,0)).name()<< std::endl;
}
void  TestMatrixMultiplcation(){
    // Test Constant * Matrix 
    float a = 13.5;
    Matrix<float> b(3,1,{1.1,2.5,3.0});
    Matrix<float> c = a*b;
    c.print();
    
    // Test Matrix*Const
    Matrix<float>d = b*a;
    d.print();

    // Test Matrix*Matrix
    Matrix<float> e = b.transpose();
    Matrix<float> f = e*b;
    Matrix<float> g = b*e;
    f.print();
    g.print();
}
int main(){
    
    TestConstructors();
    TestTranspose();
    TestElementwiseMultiplication();
    TestTypeCasting();
    TestMatrixMultiplcation();
    return 0;
} 