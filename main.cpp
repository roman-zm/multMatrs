#define matrix vector<vector<double>>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

matrix enterMatr() {
    matrix matr;
    size_t a, b;
    cout << "Enter a and b" << endl;
    cin >> a >> b;

    for (size_t i = 0; i < a; i++) {
        vector<double> temp;
        for (size_t j = 0; j < b; j++) {
            double n;
            cout << "A(" << i + 1 << "," << j + 1 << ") = ";
            cin >> n;
            temp.push_back(n);
        }
        matr.push_back(temp);
    }

    return matr;
}

void printMatr(matrix matr) {
    for (size_t i = 0; i < matr.size(); i++) {
        for (size_t j = 0; j < matr[i].size(); j++) {
            cout << std::left << std::setw(5) << matr[i][j];
        }
        cout << endl;
    }
}

void printMatr2(matrix matr) {
    for_each(matr.begin(), matr.end(), [](vector<double> &ivec) {
        for_each(ivec.begin(), ivec.end(),
                 [](double i) { cout << std::left << std::setw(5) << i; });
        cout << endl;
    });
}

matrix multiplyMatrs(matrix matr1, matrix matr2) {
    matrix result;

    size_t a = matr1.size();
    size_t b = matr2[0].size();
    size_t n = matr2.size(); // = matr1[0].size()

    for (size_t i = 0; i < a; i++) {
        vector<double> temp;
        for (size_t j = 0; j < b; j++) {
            double sum = 0;
            for (size_t ri = 0; ri < n; ri++) {
                sum += matr1[i][ri] * matr2[ri][j];
            }
            temp.push_back(sum);
        }
        result.push_back(temp);
    }

    return result;
}

matrix multMatrOnDigit(matrix inMatrix, double number) {
    matrix response;
    for (size_t i = 0; i < inMatrix.size(); i++) {
        vector<double> temp;
        for (size_t j = 0; j < inMatrix[0].size(); j++) {
            double dTemp = number * inMatrix[i][j];
            if (dTemp == -0.0)
                dTemp = 0;
            temp.push_back(dTemp);
        }
        response.push_back(temp);
    }
    return response;
}

matrix transposeMatrix(matrix inMatrix) {
    size_t a = inMatrix[0].size();
    size_t b = inMatrix.size();
    matrix response;

    for (size_t i = 0; i < a; i++) {
        vector<double> temp;
        for (size_t j = 0; j < b; j++) {
            temp.push_back(inMatrix[j][i]);
        }
        response.push_back(temp);
    }
    return response;
}

matrix getMinor(matrix inMatrix, size_t exclRow, size_t exclCol) {
    size_t a = inMatrix.size() - 1;
    unsigned ri = 0, ci = 0;

    matrix response;
    for (size_t i = 0; i < a; i++) {
        vector<double> temp;
        if (i >= exclRow)
            ri = 1;
        for (size_t j = 0; j < a; j++) {
            if (j >= exclCol)
                ci = 1;
            temp.push_back(inMatrix[i + ri][j + ci]);
            ci = 0;
        }
        response.push_back(temp);
    }
    return response;
}

double det(matrix inMatrix) {
    double response;
    if (inMatrix.size() == inMatrix[0].size()) {
        if (inMatrix.size() == 2) {
            response = inMatrix[0][0] * inMatrix[1][1] -
                       inMatrix[0][1] * inMatrix[1][0];
        } else if (inMatrix.size() == 1) {
            response = inMatrix[0][0];
        } else {
            response = 0;
            for (size_t i = 0; i < inMatrix.size(); i++) {
                matrix Minor = getMinor(inMatrix, 0, i);
                response += inMatrix[0][i] * pow(-1.0, i) * det(Minor);
            }
        }
    }
    return response;
}

matrix getInversiveMatrix(matrix inMatrix) {
    matrix matr;
    for (size_t i = 0; i < inMatrix.size(); i++) {
        vector<double> temp;
        for (size_t j = 0; j < inMatrix[0].size(); j++) {
            matrix Minor = getMinor(inMatrix, i, j);
            double dTemp = det(Minor) * pow(-1.0, i + j);
            if (abs(dTemp) < 0.0000001)
                dTemp = 0;
            temp.push_back(dTemp);
        }
        matr.push_back(temp);
    }
    double number = 1 / det(inMatrix);
    matr = transposeMatrix(matr);
    matr = multMatrOnDigit(matr, number);
    return matr;
}

int main() {

    matrix matr = enterMatr();
    matrix matr2 = getInversiveMatrix(matr);
    printMatr(matr);
    cout << endl;
    printMatr(matr2);
    cout << endl;

    matrix matr3 = multiplyMatrs(matr, matr2);
    printMatr(matr3);

    return 0;
}
