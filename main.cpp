#include <iostream>
#include <matrix.h>
#include <fraction.h>

using namespace std;

int main(int argc, char *argv[])
{
    matrix matr;
    matr.enterMatrix();
    fraction deter = det(matr);
    matr.print();
    cout<<endl<<deter;

    return 0;
}
