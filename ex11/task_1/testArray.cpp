#include "Array.h"
#include <iostream>
using namespace std;

int main() {
	Array integers1(12);
	Array integers2;
	
	cout << "integers1 dydis yra: " << integers1.getSize() << endl;
	integers1.print();
	
    cout << "integers2 dydis yra: " << integers2.getSize() << endl;
    integers2.print();
    
    for (size_t i = 0; i < 12; i++)
        integers1.setAt(i, i+1);
    
    cout << "integers1 po setAt: " << endl;
    integers1.print();
    
    Array integers3 = integers1;
    integers3.setAt(0, 100);
    
    cout << "integers3: " << endl;
    integers3.print();
    
    cout << "integers1: " << endl;
    integers1.print();
    
    const Array months = integers1;
    cout << "Menesiu masyvo months dydis yra: " << months.getSize() << endl;
    months.print();
}

/*
integers1 dydis yra: 12
0 0 0 0 0 0 0 0 0 0 0 0
integers2 dydis yra: 10
0 0 0 0 0 0 0 0 0 0
integers1 po setAt:
1 2 3 4 5 6 7 8 9 10 11 12
integers3:
100 2 3 4 5 6 7 8 9 10 11 12
integers1:
1 2 3 4 5 6 7 8 9 10 11 12
Menesiu masyvo months dydis yra: 12
1 2 3 4 5 6 7 8 9 10 11 12
*/
