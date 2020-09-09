#include <iostream>
#include <string>
#include <vector>
#include "automobilis.h"
using namespace std;

int main() {
    Automobilis automobilis1;
    automobilis1.setGamintojas("BMW");
    automobilis1.setModelis("520d");
    automobilis1.setVariklioTuris(3.0);

    Automobilis automobilis2;
    automobilis2.setGamintojas("Audi");
    automobilis2.setModelis("A4");
    automobilis2.setVariklioTuris(2.0);

    vector<Automobilis> v;

    v.push_back(automobilis1);
    v.push_back(automobilis2);

     for(int i = 0; i < v.size(); i++) {
        v[i].print();
     }
}

