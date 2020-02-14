# Matrix
A matrix class written in C++11. The matrix class contains some basic operator such as transpose,mutiplication and element access.
# Design Choice
I implement a matrix template for the client. The client can pick the ideal matrix type depend on the usage scenarios. Also, I develop a type casting function for the client to cast the matrix type in the program conveniently. For the matrix multiplcation, we often use the naive mutiplication or the elementwise mutiplication in programming. However, The client did not specify it, so I implement both of them. 
# Compile Source File
```
g++ main.cpp -std=c++11
```
# Constructors
```C++
void TestConstructors(){
    // Constructors 
    std::cout<<"Test Constructors"<< std::endl;
    //Create by 1D vector
    Matrix<float> a(3,1,{1.1,2.5,3.0}); 
    // [1.1]
    // [2.5]
    // [3.0]

    // Create by 2D vector
    Matrix<int> b({{1,2},{3,4}}); 
    // [1 2]
    // [3 4]

    // Create an empty vector
    Matrix<double> c(4,4);
    // [0 0 0 0]
    // [0 0 0 0]
    // [0 0 0 0]
    // [0 0 0 0]
    a.print();
    b.print();
    c.print();
};
```
# Function 
## Transpose
``` C++
void TestTranspose(){
    // Transpose
    std::cout<<"Test Transpose"<< std::endl; 

    Matrix<float> a(3,1,{1.1,2.5,3.0});
    // [1.1]
    // [2.5]
    // [3.0]
    Matrix<float> b = a.transpose();
    // [1.1 2.5 3.0]

    a.print();
    b.print();
}
```
## Elementwise Multiplication
```C++
void TestElementwiseMultiplication(){
    //Elementwise Multiplication
    std::cout<<"Test Elementwise Multiplication"<< std::endl;

    Matrix<int>a({{1,2},{3,4}});
    //[1 2]
    //[3 4]

    Matrix<int>b({{2,2},{2,2}});
    // [2 2]
    // [2 2]

    Matrix<int>c = a.elementwiseMultiplication(b);
    // [2 4]
    // [6 8]
    
    a.print();
    b.print();
    c.print();
}
```
# Operators
## Type Casting
```C++
void TestTypeCasting(){
    // Type Casting
    std::cout<<"Test Type Casting"<< std::endl;
    Matrix<float> a(3,1,{1.1,2.5,3.0});
    a.print();
    std:: cout<<"The element type in a is "<<typeid(a(0,0)).name()<< std::endl;
    // [1.1]
    // [2.5]
    // [3.0]
    /// f

    // First way to cast
    Matrix<int> b = a;
    b.print();
    std:: cout<<"The element type in b is "<<typeid(b(0,0)).name()<< std::endl;
    // [1]
    // [2]
    // [3]
    // i

    // Second way to cast
    Matrix<int> c (3,1);
    c = Matrix<int>(a);
    c.print();
    std:: cout<<"The element type in c is "<<typeid(c(0,0)).name()<< std::endl;
    // [1]
    // [2]
    // [3]
    // i
}
```
## Mutiplication
```
Notice : If you want to mutiplicate a float number with matrix<int>, it is illigal. You should either cast the float number into int or cast the matrix<int> into matrix<float> first. 
```
```C++
void  TestMatrixMultiplcation(){
    std::cout<<"Test Matrix Multiplcation"<< std::endl;
    // Test Constant * Matrix 
    float a = 13.5;
    Matrix<float> b(3,1,{1.1,2.5,3.0});
    Matrix<float> c = a*b;
    c.print();
    //[14.85]
    //[33.75]
    //[40.5]

    // Test Matrix*Const
    Matrix<float>d = b*a;
    d.print();
    //[14.85]
    //[33.75]
    //[40.5]

    // Test Matrix*Matrix
    Matrix<float> e = b.transpose();
    Matrix<float> f = e*b;
    // [16.46]
    Matrix<float> g = b*e;
    // [1.21 2.75 3.3]
    // [2.75 6.25 7.5]
    // [3.3  7.5   9]

    f.print();
    g.print();
}
```


