#include "Array.h"
#include <iostream>
using namespace std;

int main() {

    try {
        Array integers(-2);
    } catch(invalid_argument &e) {
        cout << "------EXCEPTION------ " << e.what() << endl;
    }

	Array integers1(5);
	Array integers2;
	
	cout << "integers1 dydis yra: " << integers1.getSize() << endl << integers1 << endl;
	
	cout << "integers2 dydis yra: " << integers2.getSize() << endl << integers2 << endl;
	
	cout << "Iveskite 15 sveikuju skaiciu:" << endl;
	cin >> integers1 >> integers2;
	
	cout << "Po ivedimo, masyvas integers1: " << endl << integers1 << endl;
	cout << "Po ivedimo, masyvas integers2: " << endl << integers2 << endl;

    integers1.setAt(0,99);
    integers2.setAt(0,11);

	cout << "Po setAt(0,99), masyvas integers1: " << endl << integers1 << endl;
	cout << "Po setAt(0,11), masyvas integers2: " << endl << integers2 << endl;

    try {
        integers1.setAt(20,88);
    } catch(out_of_range &e) {
        cout << "------EXCEPTION------" << e.what() << endl;
    }
	
	const Array integers3 = integers1;
	
	cout << "Masyvai integers1 ir integers2 yra ";
	if (integers1 == integers2) cout << "lygus" << endl;
	else cout << "nelygus" << endl;
	
	cout << "#1 Masyvai integers1 ir integers3 yra ";
	if (integers1 == integers3) cout << "lygus" << endl;
	else cout << "nelygus" << endl;
	
	cout << "#2 Masyvai integers3 ir integers1 yra ";
	if (integers3 == integers1) cout << "lygus" << endl;
	else cout << "nelygus" << endl;
	
	//Priskyrimo operatorius, N.B.: masyvas integers1 yra mazesnis!
	integers1 = integers2;
	cout << "Masyvas integers1 po priskyrimo:" << endl << integers1 << endl;
	
	integers1 = integers3;
	cout << "Masyvas integers1 po priskyrimo:" << endl << integers1 << endl;
	
	cout << "integers2[0] reiksme yra " << integers2[0] << endl;
	cout << "integers3[0] reiksme yra " << integers3[0] << endl;
	
	integers1[4] = 100;
	cout << "Masyvas integers1 po priskyrimo i 4 elementa: " << endl << integers1 << endl;

	//Atkomentave patestuokite priskyrima konstantiniam objektui (nesikompiliuos)
	//cout << "Bandome integers3 (konstantinis objektas) priskirti 4 elementa:" << endl;
	//integers3[4] = 100;
	
    try {
        cout << integers1[5] << endl;
    } catch(out_of_range &e) {
        cout << "------EXCEPTION------" << e.what() << endl;
    }
	
	
}

/*
integers1 dydis yra: 5
0 0 0 0 0
integers2 dydis yra: 10
0 0 0 0 0 0 0 0 0 0
Iveskite 15 sveikuju skaiciu:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Po ivedimo, masyvas integers1:
1 2 3 4 5
Po ivedimo, masyvas integers2:
6 7 8 9 10 11 12 13 14 15
Masyvai integers1 ir integers2 yra nelygus
#1 Masyvai integers1 ir integers3 yra lygus
#2 Masyvai integers3 ir integers1 yra lygus
Masyvas integers1 po priskyrimo:
6 7 8 9 10 11 12 13 14 15
Masyvas integers1 po priskyrimo:
1 2 3 4 5
integers2[0] reiksme yra 6
integers3[0] reiksme yra 1
Masyvas integers1 po priskyrimo i 4 elementa:
1 2 3 4 100
*/
