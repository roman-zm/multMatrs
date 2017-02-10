#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction
{
public:
    fraction();

    void setNumerator(int input);
    void setDenominator(int input);
    int getNumenator();
    int getDenominator();

    void print();
    void reduce();

    double toDouble();

    friend std::ostream& operator <<(std::ostream& os, const fraction& frac);
    friend std::istream& operator >>(std::istream& is, fraction& frac);

    fraction operator +(fraction inFraction);
    fraction operator -(fraction inFraction);
    fraction operator *(fraction inFraction);
    fraction operator /(fraction inFraction);

    fraction operator +(int inInt);
    fraction operator -(int inInt);
    fraction operator *(int inInt);
    fraction operator /(int inInt);

   // fraction operator =(int inInt);



private:
    int numerator;
    int denominator;
};

int gcd(int first, int second);

#endif // FRACTION_H
