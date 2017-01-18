#define matrix vector<vector<double> >

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

matrix enterMatr()
{
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

void printMatr(matrix matr)
{
    for (size_t i = 0; i < matr.size(); i++) {
        for (size_t j = 0; j < matr[i].size(); j++) {
            cout << std::left << std::setw(5) << matr[i][j];
        }
        cout << endl;
    }
}

void printMatr2(matrix matr)
{
    for_each(matr.begin(), matr.end(), [](vector<double>& ivec) {
        for_each(ivec.begin(), ivec.end(), [](double i) {
            cout << std::left << std::setw(5) << i;
        });
        cout << endl;
    });
}

matrix multiplyMatrs(matrix matr1, matrix matr2)
{
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

int main(int argc, char* argv[])
{
    matrix matr = enterMatr();
    matrix matr2 = enterMatr();

    cout << "Matrix 1: " << endl;
    printMatr(matr);

    cout << "Matrix 2: " << endl;
    printMatr2(matr2);

    matrix mulResult = multiplyMatrs(matr, matr2);
    cout << "Result: " << endl;
    printMatr2(mulResult);

    return 0;
}
