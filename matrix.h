#ifndef __MATRIX_H__
#define __MATRIX_H__
#include<vector>
#include<iostream>
#include <stdexcept>
template<class U>
class Matrix{
    public:

        // === Constructor/Destructor ===
        // Create an empty matrix
        Matrix(int rows,int columns);
        //Initialize with 1D vector
        Matrix(int rows, int columns,std::vector<U>list);
        // Initialize with 2D vector 
        Matrix(std::vector<std::vector<U>>list);
        //Copy Contructor
        Matrix(const Matrix& matrix);
        // Destructor
        ~Matrix();

        // === Getter/Setter ===
        inline int getRow() const { return row_; }
        inline int getCol() const { return col_; };

        // === Operators ===
        //Access Element Operator
        U& operator()(int i, int j);
        U  operator()(int i, int j)const;
        // Matrix Type Casting Operator
        template<typename T> operator Matrix<T>() const;

        // === Functions ===
        // Transpose Function
        inline Matrix transpose() const;
        // Elementwise Multiplication Function
        inline Matrix elementwiseMultiplication(const Matrix&);
        //Print Out the Matrix 
        void print();

    private: 
        int col_;
        int row_;
        std::vector<std::vector<U>> buffer; 
};

// Multiplication Operators

// Matrix * Constant Number
template<class U>Matrix<U> operator* (const Matrix<U>&, U);
// Constant Number * Matrix
template<class U>Matrix<U> operator* (U, const Matrix<U>&);
// Matrix * Matrix
template<class U>Matrix<U> operator* (const Matrix<U>&, const Matrix<U>&);


// === Constructor/Destructor ===
// Create an empty matrix
template<class U>
Matrix<U>::Matrix(int rows,int columns){
    col_ = columns;
    row_ = rows;
    buffer = std::vector<std::vector<U>>(row_,std::vector<U>(col_,0));
}

//Initialize with 1D vector
template<class U>
Matrix<U>::Matrix(int rows, int columns, std::vector<U> list){
    row_ = rows;
    col_ = columns;
    if(list.size() != row_*col_){
        throw std::length_error("List Length is different from the Matrix");
    }
    const auto begin = std::begin(list);
    for(int r = 0; r <row_ ;++r){
        buffer.push_back({begin+r*col_,begin+(r+1)*col_});
    }
}

// Initialize with 2D vector
template<class U>
Matrix<U>::Matrix(std::vector<std::vector<U>> list){
    row_ = list.size();
    col_ = list[0].size();
    buffer = list;
}

// Copy Constructor
template<class U>
Matrix<U> :: Matrix(const Matrix<U>& matrix){
    row_ = matrix.row_;
    col_ = matrix.col_;
    buffer = matrix.buffer;
}

// Destructor
template<class U>
Matrix<U>::~Matrix(){
    //std::cout << "matrix dead";
}


// === Operators ===
//Access Element Operator
template<class U>
U& Matrix<U>::operator()(int i, int j){
    if(i>row_-1 || j>col_-1)
        throw std::range_error("Out of Range");
    return buffer[i][j];
}

//Access Element Operator
template<class U>
U Matrix<U>::operator()(int i, int j)const{
    if(i>row_-1 || j>col_-1)
        throw std::range_error("Out of Range");
    return buffer[i][j];
}

// Multiplication Operator
// Matrix * Constant Number
template<class U>
Matrix<U> operator* (const Matrix<U>& a, U b){
    Matrix<U> matrix(a.getRow(),a.getCol());
    for(int i = 0; i < a.getRow();i++){
        for(int j = 0;j < a.getCol();j++){
            matrix(i,j) = b*a(i,j);
        }
    }
    return matrix;
}

// Multiplication Operator
// Constant Number * Matrix  
template<class U>
Matrix<U> operator* (U a, const Matrix<U>& b){
    return b*a ;
}

// Multiplication Operator
// Matrix*Matrix
template<class U>
Matrix<U> operator* (const Matrix<U>& a, const Matrix<U>& b){
    if(a.getCol() != b.getRow()){
        throw std::invalid_argument("Bad dimension !!!");
    }
    Matrix<U> matrix(a.getRow(),b.getCol());
    for(int i = 0 ; i < a.getRow();i++){
        for(int j = 0;j < b.getCol();j++){
            U Sum = 0;
            for(int k = 0; k < a.getCol();k++)
                Sum += a(i,k)*b(k,j);
            matrix(i,j) = Sum;
        }
    }
    return matrix;
}

// Matrix Type Casting Operator
template<typename U> 
template<typename T> Matrix<U>:: operator Matrix<T>() const
{
    std::vector<std::vector<T>> vecT;
    for(auto&& b: buffer) vecT.emplace_back(std::begin(b), std::end(b));
    return Matrix<T>(vecT);
}

// === Functions ===
//Transpose Function
template<class U>
Matrix<U> Matrix<U>::transpose()const{
    Matrix matrix(col_,row_);
    for(int i = 0 ; i < col_;i++)
        for(int j = 0 ; j < row_;j++)
            matrix.buffer[i][j] = buffer[j][i];
    return matrix;
}

// Elementwise Multiplication Function
template<class U>
Matrix<U> Matrix<U>::elementwiseMultiplication(const Matrix<U>& a){
   if(a.getCol() != col_ || a.getRow() != row_){
       throw std::invalid_argument("Bad dimension !!!");
   }
   Matrix<U> matrix(row_,col_);
   for(int i = 0 ; i < row_;i++){
       for(int j =0 ; j < col_;j++){
           matrix(i,j) = a(i,j)*(*this)(i,j);
       }
   }
   return matrix ;
}


//Print Out the Matrix
template<class U>  
void Matrix<U>:: print(){
    for(int i = 0 ; i < row_ ; i++){
        std:: cout<< "[";
        for(int j = 0 ; j < col_ ;j++){
            std::cout << buffer[i][j] <<" ";
        }
        std::cout <<"]"<< std::endl;
    }
    std::cout << std::endl;
}

#endif