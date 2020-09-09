
#include<iostream>
#include "mystack.h"
#include "automobilis.h"

// FIXME rm this temp solution
#include "mystack.cpp"
using namespace std;

int main()
{
    AutoStack S;

    S.MyStackPrint();

    Automobilis* auto1 = new Automobilis("Skoda", "Octavia", 2.0, 2010, 4000);
    Automobilis* auto2 = new Automobilis("Volkswagen", "Golf", 2.0, 2006, 3000);

    if (!S.push(auto1)) {
        delete auto1;
    }

    if (!S.push(auto2)) {
        delete auto2;
    }
   
    cout << "----------------" << endl;
    S.MyStackPrint();
    cout << "----------------" << endl;

    try {
        auto2 = S.pop();
    } catch(const char* s) {
        cout << s << endl;
    }

    cout << "Popped value is: " << endl;

    auto2->print();

    cout << "----------------" << endl;
    S.MyStackPrint();
    cout << "----------------" << endl;

    Automobilis* auto3 = new Automobilis("BMW", "520", 2.0, 2010, 4000);
    Automobilis* auto4 = new Automobilis("Audi", "100", 2.0, 2006, 3000);

    Automobilis* autos[] = {auto3, auto4};
    AutoStack S2(autos, sizeof(autos)/sizeof(autos[0]));

    cout << "----------------" << endl;
    S2.MyStackPrint();
    cout << "----------------" << endl;

    delete auto2;
}

