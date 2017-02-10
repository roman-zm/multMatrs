#include "fraction.h"
#include <iostream>

fraction::fraction()
{
    numerator = 1;
    denominator = 1;
}

int gcd(int first, int second){
    int q;

    if( first%second == 0) q = second;
    else {
        while( first%second !=0 ){
            q = first%second;
            first=second;
            second=q;
        }
    }
    return q;
}

int fraction::getDenominator(){
    return denominator;
}

int fraction::getNumenator(){
    return numerator;
}

void fraction::setNumerator(int input){
    numerator = input;
}

void fraction::setDenominator(int input){
    denominator = input;
}

void fraction::print(){
    std::cout<<numerator<<"/"<<denominator;
}

void fraction::reduce(){
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

double fraction::toDouble(){
    return numerator/denominator;
}

//-------------------------reloaded operators

std::ostream& operator <<(std::ostream& os, const fraction& frac){
    os << frac.numerator <<"/"<< frac.denominator;
    return os;
}

std::istream& operator >>(std::istream& is, fraction& frac){
    int a,b;
    is >> a >> b;
    frac.setNumerator(a);
    frac.setDenominator(b);
    return is;
}

fraction fraction::operator *(fraction inFraction){
    fraction response = *this;
    response.numerator *= inFraction.numerator;
    response.denominator *= inFraction.denominator;
    //response.reduce();
    return response;
}

fraction fraction::operator /(fraction inFraction){
    fraction response = *this;
    response.numerator *= inFraction.denominator;
    response.denominator *= inFraction.numerator;
    //response.reduce();
    return response;
}

fraction fraction::operator +(fraction inFraction){
    fraction response = *this;
    response.numerator *= inFraction.denominator;
    response.denominator *= inFraction.denominator;

    inFraction.numerator *= this->denominator;

    response.numerator += inFraction.numerator;
    response.reduce();
    return response;
}

fraction fraction::operator -(fraction inFraction){
    fraction response = *this;
    response.numerator *= inFraction.denominator;
    response.denominator *= inFraction.denominator;

    inFraction.numerator *= this->denominator;

    response.numerator -= inFraction.numerator;
    response.reduce();
    return response;
}

fraction fraction::operator *(int inInt){
    fraction response = *this;
    response.numerator *= inInt;
    response.reduce();
    return response;
}

fraction fraction::operator /(int inInt){
    fraction response = *this;
    response.denominator *= inInt;
    response.reduce();
    return response;
}

