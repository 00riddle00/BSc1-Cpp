#include <iostream>
#include <iomanip>
#include "helpers.h"

using namespace std;


int main() {
    int a = 1, b = 2;
    cout << Helpers::sum(a, b) << endl;

    float c = 2.0, d = 3.0;
    cout << Helpers::sum(c, d) << endl;

    unsigned char e = '!', f = 'A';
    cout << Helpers::sum(e, f) << endl;
    cout << +Helpers::sum(e, f) << endl;
}

