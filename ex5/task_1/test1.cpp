#include <iostream>
#include "test1.h"
using namespace std;

void Test1::print() {
    cout << "Nothing to print" << endl;
}

void Test1::print(int i1) {
    cout << "Output: " << i1 << endl;
}

void Test1::print(int i1, int i2) {
    cout << "Output: " << i1 << " " << i2 << endl;
}

void Test1::print(int i1, int i2, int i3) {
    cout << "Output: " << i1 << " " << i2 << " " << i3 << endl;
}

