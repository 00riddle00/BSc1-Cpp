#include <iostream>
#include "test1.h"
#include "test2.h"
using namespace std;

int main() {

    Test1 test1;
    test1.print();
    test1.print(1);
    test1.print(1,2);
    test1.print(1,2,3);

    cout << endl;

    Test2 test2;
    test2.print();
    test2.print(1);
    test2.print(1,2);
    test2.print(1,2,3);

}

