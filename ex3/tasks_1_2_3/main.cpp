#include <iostream>
#include "racionalus_sk.h"
using namespace std;

int gcd(int n1, int n2) {
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}


void simplify(RacionalusSk &rs) {
    int num = rs.getNumerator();
    int den = rs.getDenominator();
    int hcf = gcd(num, den);
    cout << "GCD is " << hcf << endl;
    rs.setNumber(num/hcf, den/hcf);
}



int main() {
    cout << "hello" << endl;
    RacionalusSk *rs1 = new RacionalusSk(1,2);
    RacionalusSk *rs2 = new RacionalusSk(3,4);

    rs1->printRational();
    rs1->printFloat();

    rs2->printRational();
    rs2->printFloat();

    rs1->multiply(*rs2);
    rs1->printRational();
    rs1->printFloat();

    rs1->divide(*rs2);
    rs1->printRational();
    rs1->printFloat();

    RacionalusSk *rs3 = new RacionalusSk(1,0);
    
    RacionalusSk *rs4 = new RacionalusSk();
    rs4->printRational();
    rs4->setNumber(5,6);
    rs4->printRational();

    rs4->setNumber(5,0);
    rs4->printRational();
    rs4->printFloat();

    float rs = rs2->getFloat();
    cout << rs << endl;

    simplify(*rs1);
    rs1->printRational();

    delete(rs1);
    delete(rs2);
    delete(rs4);

}

