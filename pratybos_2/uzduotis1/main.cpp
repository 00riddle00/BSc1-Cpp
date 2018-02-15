#include <iostream>
#include <string>
#include "automobilis.h"
using namespace std;

int main() {
    Automobilis automobilis1;
    automobilis1.setGamintojas("BMW");
    automobilis1.setModelis("520d");
    automobilis1.setVariklioTuris(3.0);

    automobilis1.print();

    Automobilis automobilis2;
    automobilis2.setGamintojas("Audi");
    automobilis2.setModelis("A4");
    automobilis2.setVariklioTuris(2.0);

    automobilis2.print();

}

