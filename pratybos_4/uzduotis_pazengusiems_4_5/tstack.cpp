
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

    S.push(auto1);
    S.push(auto2);
   
    cout << "----------------" << endl;
    S.MyStackPrint();
    cout << "----------------" << endl;

    auto2 = S.pop();
    cout << "Popped value is: " << endl;
    auto2->print();
    cout << "----------------" << endl;
    
    S.MyStackPrint();

    delete auto2;
}

