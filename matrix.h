#ifndef __MATRIX_H__
#define __MATRIX_H__

#include<vector>

class Matrix{
    public:
        // Create empty matrix
        Matrix(int rows,int columns);
        //initialize with list 
        Matrix(int rows, int columns,std::vector<double>list);
        //Copy Contructor
        Matrix(const Matrix& matrix);
        ~Matrix();
        // Getter 
        int getRow() const;
        int getCol() const;
        //operator
        double& operator()(int i, int j);
        double  operator()(int i, int j)const;
        Matrix transpose() const;

        //Debug
        void print();

    private: 
        int col_;
        int row_;
        std::vector<std::vector<double>> buffer; 
};

// for multiplication
Matrix operator* (const Matrix&, double);
Matrix operator* (double, const Matrix&);
Matrix operator* (const Matrix&, const Matrix&);


#endif // _MATRIX_MATRIX_H_