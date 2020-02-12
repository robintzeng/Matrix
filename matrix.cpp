#include"matrix.h"
#include<iostream>

// Constructor
Matrix::Matrix(int rows,int columns){
    col_ = columns;
    row_ = rows;
    buffer = std::vector<std::vector<double>>(row_,std::vector<double>(col_,0));
}
Matrix::Matrix(int rows, int columns, std::vector<double> list){
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
Matrix::Matrix(int rows, int columns, std::vector<std::vector<double>> list){
    row_ = list.size();
    col_ = list[0].size();
    buffer = list;
}
// Copy Constructor
Matrix :: Matrix(const Matrix& matrix){
    row_ = matrix.row_;
    col_ = matrix.col_;
    buffer = matrix.buffer;
}
// Destructor
Matrix::~Matrix(){
    //std::cout << "matrix dead";
}
/// Getter 
int  Matrix::getRow() const{
    return row_;
}
int Matrix::getCol() const{
    return col_;
}

// Operator
double& Matrix::operator()(int i, int j){
    if(i>row_-1 || j>col_-1)
        throw std::range_error("Out of Range");
    return buffer[i][j];
}
double Matrix::operator()(int i, int j)const{
    if(i>row_-1 || j>col_-1)
        throw std::range_error("Out of Range");
    return buffer[i][j];
}
Matrix Matrix::transpose()const{
    Matrix matrix(col_,row_);
    for(int i = 0 ; i < col_;i++)
        for(int j = 0 ; j < row_;j++)
            matrix.buffer[i][j] = buffer[j][i];
    return matrix;
}
Matrix Matrix::T()const{
    return (*this).transpose();
}
Matrix operator* (const Matrix& a, double b){
    Matrix matrix(a.getRow(),a.getCol());
    for(int i = 0; i < a.getRow();i++){
        for(int j = 0;j < a.getCol();j++){
            matrix(i,j) = b*a(i,j);
        }
    }
    return matrix;
}
Matrix operator* (double a, const Matrix& b){
    return b*a ;
}
Matrix operator* (const Matrix& a, const Matrix& b){
    if(a.getCol() != b.getRow()){
        throw std::invalid_argument("Bad dimension !!!");
    }
    Matrix matrix(a.getRow(),b.getCol());
    for(int i = 0 ; i < a.getRow();i++){
        for(int j = 0;j < b.getCol();j++){
            double Sum = 0;
            for(int k = 0; k < a.getCol();k++)
                Sum += a(i,k)*b(k,j);
            matrix(i,j) = Sum;
        }
    }
    return matrix;
}
// Debug 
void Matrix:: print(){
    for(int i = 0 ; i < row_ ; i++){
        std:: cout<< "[";
        for(int j = 0 ; j < col_ ;j++){
            std::cout << buffer[i][j] <<" ";
        }
        std::cout <<"]"<< std::endl;
    }
}