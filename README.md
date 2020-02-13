# Matrix
A matrix class written in C++11. The matrix class contain some basic operator such as transpose,mutiplication and element access.
# Compile Source File
```
g++ main.cpp -std=c++11
```
# Constructors
```C++
#include"matrix.h"
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
```
# Function 
## Transpose
``` C++
// Transpose 
Matrix<float> d = a.transpose();
// [1.1 2.5 3] 
```
## Elementwise Multiplication
```C++
//Elementwise Multiplication
Matrix<float> e = a.elementwiseMultiplication(d.transpose());
// [1.21]
// [6.25]
// [9]
```

# Operator
## Type Casting 
```C++
// Type Casting  
Matrix<int> f = e;
// [1]
// [6]
// [9]

a = Matrix<int>(a);
// [1]
// [2]
// [3]
```
## Mutiplication
```C++
// The type of a is Matrix<int>
// The type of d is Matrix<float>
// The mutiplication will auto cast into the type of g which is Matrix<float>

Matrix<float> g = a*d;
// [1.1 2.5 3.0]
// [2.2 5.0 6.0]
// [3.3 7.5 9.0]
Matrix<int>   h = a*d;
// [1 2 3]
// [2 5 6]
// [3 7 9]
Matrix<float> i = d*a;
// [15.1]
Matrix<int>   j = d*a;
// [15]

```


