#include <iostream>
#include "MyString.h"

using namespace std;

MyString::MyString(string mystr) : myString(mystr) {}

void MyString::print() const {
    cout << myString << endl;
}

