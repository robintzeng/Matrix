# Matrix
A matrix class written in C++11. The matrix class contain some basic operator such as transpose,mutiplication and element access.
# Constructors
```C++
#include"matrix.h"
a = Matrix(3,3); // Create a 3X3 zero matrix 
b = Matrix(3,3,{1,2,3,4,5,6,7,8,9});
// Create a 3X3 matrix with 1D vector
/// {{1 2 3},
///  {4 5 6},
///  {7,8,9}}
c = Matrix(2,1,{{1},{2}}); 
// Create a 2X1 matrix with 2D vecotr
/// {{1}
//   {2}} 

d = Matrix(c);// Create a matrix which is the same as c
```
# Operators
```C++
// element access
val = a(1,3);
// tranpose // both of them can do the same thing
b = a.transpose();
b = a.T();
// multiplication
c = a*b;
// elementwise mutiplication
c = a.elementwiseMultiplication(b);
```
# Print out the matrix
```C++
c.print();
```
