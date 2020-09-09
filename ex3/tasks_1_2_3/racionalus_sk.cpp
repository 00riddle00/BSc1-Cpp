#include <iostream>
#include "racionalus_sk.h"
using namespace std;


int RacionalusSk::gcd(int n1, int n2) {
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}

void RacionalusSk::simplify() {
    int hcf = this->gcd(numerator, denominator);
    numerator /= hcf;
    denominator /= hcf;
}
        
RacionalusSk::RacionalusSk() {
    numerator = 1;
    denominator = 1;
}

RacionalusSk::RacionalusSk(int num, int den) {
    try {
        numerator = num;
        denominator = den;
        if (denominator == 0) {
            throw 0;
        } else {
            this->simplify();
        }
    }

    catch (int x) {
      cout << "Failed to create the object. ";
      cout<<"Denominator cannot be " << x << "!" << endl;
    }
}

RacionalusSk::~RacionalusSk() {
    cout << "The number ";
    this->printRational();
    cout << "is deleted" << endl;
}

// setter

void RacionalusSk::setNumber(int num, int den) {
    try {
        numerator = num;
        denominator = den;
        if (denominator == 0) {
            throw 0;
        } else {
            this->simplify();
        }
    }

    catch (int x) {
      cout << "Failed to set the number. ";
      cout<<"Denominator cannot be " << x << "!" << endl;
    }
}

// getters

float RacionalusSk::getNumerator() {
    return numerator;
}

float RacionalusSk::getDenominator() {
    return denominator;
}

float RacionalusSk::getFloat() {
    return (float) numerator/denominator;
}

// member functions

void RacionalusSk::printRational() {
    cout << numerator << '/' << denominator << endl;
}

void RacionalusSk::printFloat() {
    cout << (float) numerator/denominator << endl;
}

void RacionalusSk::multiply(const RacionalusSk &rs) {
    numerator *= rs.numerator;
    denominator *= rs.denominator;
    this->simplify();
}

void RacionalusSk::divide(const RacionalusSk &rs) {
    numerator *= rs.denominator;
    denominator *= rs.numerator;
    this->simplify();
}
