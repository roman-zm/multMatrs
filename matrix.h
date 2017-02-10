#ifndef MATRIX_H
#define MATRIX_H

#include "fraction.h"

#include <vector>
#include <sys/types.h>

class matrix
{
public:
    matrix();
    ~matrix();

    void enterMatrix();
    void print();
    void clear();
    void push_back(std::vector<fraction> temp);


    std::size_t size(unsigned depth);

    std::vector< std::vector<fraction> > toVector();

    std::vector<fraction> operator [](std::size_t idx);

    friend fraction det(matrix inMatrix);
    friend matrix getInversiveMatrix(matrix inMatrix);
    friend matrix getMinor(matrix inMatrix, size_t exclRow, size_t exclCol);
    friend matrix transposeMatrix(matrix inMatrix);

    fraction det();
    matrix getInversiveMatrix();
    matrix getMinor(size_t exclRow, size_t exclCol);
    matrix transposeMatrix();

    matrix operator +(matrix inMatrix);
    matrix operator -(matrix inMatrix);
    matrix operator +(fraction number);
    matrix operator -(fraction number);
    matrix operator *(matrix inMatrix);
    matrix operator *(fraction number);
    matrix operator /(fraction number);

private:
    std::vector< std::vector<fraction> > matr;

    fraction det(matrix inMatrix);
    matrix getInversiveMatrix(matrix inMatrix);
    matrix getMinor(matrix inMatrix, size_t exclRow, size_t exclCol);
    matrix transposeMatrix(matrix inMatrix);

};


#endif // MATRIX_H
