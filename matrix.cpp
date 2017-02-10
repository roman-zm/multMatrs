#include "matrix.h"
#include "fraction.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>

matrix::matrix()
{
//    enterMatrix();
}

matrix::~matrix(){
    clear();
}

fraction det(matrix inMatrix){
    return inMatrix.det();
}

fraction matrix::det(matrix inMatrix){
    fraction response;
    if(inMatrix.size(0)==inMatrix.size(1)){
        if(inMatrix.size(0)==2){
            response = inMatrix[0][0]*inMatrix[1][1] -
                    inMatrix[0][1]*inMatrix[1][0];
        } else if(inMatrix.size(0)==1) {
            response = inMatrix[0][0];
        } else {
            response.setNumerator(0);
            for(size_t i = 0; i<inMatrix.size(0); i++){
                matrix Minor = getMinor(inMatrix, 0, i);
                response = response + inMatrix[0][i]*pow(-1.0,i)*det(Minor);
            }
        }
    }
    return response;
}

fraction matrix::det(){
    return det(*this);
}

void matrix::clear(){
    matr.clear();
}

void matrix::enterMatrix(){
    clear();
    size_t a, b;
    std::cout << "Enter number of rows and columns" << std::endl;
    std::cin >> a >> b;

    for (size_t i = 0; i < a; i++) {
        std::vector<fraction> temp;
        for (size_t j = 0; j < b; j++) {
            fraction n;
            std::cout << "A(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> n;
            temp.push_back(n);
        }
        matr.push_back(temp);
    }
}


std::vector< std::vector<fraction> > matrix::toVector(){
    return matr;
}

std::vector<fraction> matrix::operator [](std::size_t idx){
    return matr[idx];
}

size_t matrix::size(unsigned depth){
    if(depth==0) return matr.size();
    else if(depth == 1) return matr[0].size();
    else return 0;
}

matrix matrix::operator /(fraction number){
    for(size_t i=0; i<this->size(0);i++){
        for(size_t j=0; j<this->size(1); j++){
            fraction dTemp = matr[i][j];
            matr[i][j] = dTemp/number;
        }
    }
    return *this;
}

matrix matrix::operator *(fraction number){
    for(size_t i=0; i<this->size(0);i++){
        for(size_t j=0; j<this->size(1); j++){
            fraction dTemp = matr[i][j];
            matr[i][j] = dTemp*number;
        }
    }
    return *this;
}

void matrix::push_back(std::vector<fraction> temp){
    matr.push_back(temp);
}

matrix getMinor(matrix inMatrix, size_t exclRow, size_t exclCol){
    return inMatrix.getMinor(exclRow, exclCol);
}

matrix matrix::getMinor(matrix inMatrix, size_t exclRow, size_t exclCol){
    unsigned ri=0, ci=0;

    matrix response;
    for(size_t i=0; i<inMatrix.size(0)-1; i++){
        std::vector<fraction> temp;
        if(i>=exclRow) ri=1;
        for(size_t j=0; j<inMatrix.size(0)-1; j++){
            if(j>=exclCol)ci=1;
            temp.push_back(inMatrix[i+ri][j+ci]);
            ci=0;
        }
        response.push_back(temp);
    }
    return response;
}

matrix matrix::getMinor(size_t exclRow, size_t exclCol){
    return getMinor(*this, exclRow, exclCol);
}

matrix matrix::operator -(matrix inMatrix){
    fraction negOne;
    negOne.setNumerator(-1);
    inMatrix = inMatrix * negOne ;
    return *this+inMatrix;
}

matrix matrix::operator +(matrix inMatrix){
    for(size_t i=0; i<this->size(0); i++){
        for(size_t j=0; j<this->size(1); j++){
            matr[i][j] = matr[i][j] + inMatrix[i][j];
        }
    }
    return *this;
}

matrix matrix::operator *(matrix inMatrix){
    std::vector< std::vector<fraction> > result;

    if(inMatrix.size(0) != this->size(1)){
        this->clear();
        return *this;
    }

    for (size_t i = 0; i < this->size(0); i++) {
        std::vector<fraction> temp;
        for (size_t j = 0; j < inMatrix.size(1); j++) {
            fraction sum;
            sum.setNumerator(0);
            for (size_t ri = 0; ri < inMatrix.size(0); ri++) {
                sum = sum + matr[i][ri] * inMatrix[ri][j];
            }
            temp.push_back(sum);
        }
        result.push_back(temp);
    }
    matr.clear();
    matr = result;

    return *this;
}

void matrix::print(){
    for (size_t i = 0; i < matr.size(); i++) {
        for (size_t j = 0; j < matr[i].size(); j++) {
            //std::cout << std::left << std::setw(5) << matr[i][j];
            std::cout << std::left << matr[i][j].getNumenator()<<"/"<< std::setw(5)<<matr[i][j].getDenominator();
        }
        std::cout << std::endl;
    }
}

matrix getInversiveMatrix(matrix inMatrix){
    return inMatrix.getInversiveMatrix();
}

matrix matrix::getInversiveMatrix(matrix inMatrix){
    matrix response;
    for(size_t i=0; i<inMatrix.size(0); i++){
        std::vector<fraction> temp;
        for(size_t j=0; j<inMatrix.size(1); j++){
            matrix Minor = getMinor(inMatrix, i, j);
            fraction dTemp = det(Minor)*pow(-1.0,i+j);
            temp.push_back( dTemp );
        }
        response.push_back(temp);
    }
    fraction number = det(inMatrix);
    response = transposeMatrix(response);
    response = response*number;
    return response;
}

matrix matrix::getInversiveMatrix(){
    return getInversiveMatrix(*this);
}

matrix transposeMatrix(matrix inMatrix){
    return inMatrix.transposeMatrix();
}

matrix matrix::transposeMatrix(matrix inMatrix){
    matrix response;

    for(size_t i =0; i<inMatrix.size(1); i++){
        std::vector<fraction> temp;
        for(size_t j=0; j<inMatrix.size(0); j++){
            temp.push_back(inMatrix[j][i]);
        }
        response.push_back(temp);
    }
    return response;
}

matrix matrix::transposeMatrix(){
    return transposeMatrix(*this);
}





