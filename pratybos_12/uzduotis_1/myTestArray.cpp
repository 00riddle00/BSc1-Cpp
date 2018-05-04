#include "Array.h"
#include <iostream>
using namespace std;

int main() {
	Array integers1(4);
	Array integers2;
	cout << "Masyvas integers1 dydis yra: " << integers1.getSize() << endl << integers1 << endl;
    cout << "Masyvo integers2 dydis yra: " << integers2.getSize() << endl <<  integers2 << endl;

    cout << "// Ivedame skaicius i integers1 ir integers2 masyvus:" << endl;
    cin >> integers1 >> integers2;

	cout << "Masyvo integers1 dydis yra: " << integers1.getSize() << endl << integers1 << endl;
    cout << "Masyvo integers2 dydis yra: " << integers2.getSize() << endl <<  integers2 << endl;

    cout << "// Priskiriame integers1 = integers2" << endl;
    integers1 = integers2;
	cout << "Masyvo integers1 dydis yra: " << integers1.getSize() << endl << integers1 << endl;
    cout << "Masyvo integers2 dydis yra: " << integers2.getSize() << endl <<  integers2 << endl;

    cout << "// Priskiriame integers1[1] = 8, integers1[-1] = 9" << endl;
    integers1[1] = 8;
    integers1[-1] = 9;
	cout << "Masyvo integers1 dydis yra: " << integers1.getSize() << endl << integers1 << endl;

    cout << "// Ivedame skaiciu i integers1[0] ir integers[2]:" << endl;
    cin >> integers1[0] >> integers1[2];
	cout << "Masyvo integers1 dydis yra: " << integers1.getSize() << endl << integers1 << endl;

    cout << "// Spausdiname integers1[2] ir integers1[3] (naudojam operatoriaus [] perkrauta konstantini metoda):" << endl;
	cout << integers1[2] << " " << integers1[3] << endl;

    Array integers3(4);
    Array integers4(4);
    cout << "// Ivedame skaicius i integers3 ir integers4 masyvus:" << endl;
    cin >> integers3 >> integers4;
    
	cout << "Masyvo integers3 dydis yra: " << integers3.getSize() << endl << integers1 << endl;
    cout << "Masyvo integers4 dydis yra: " << integers4.getSize() << endl <<  integers2 << endl;

    cout << "Masyvai integers3 ir integers4 yra ";
    if (integers3 == integers4) {
        cout << "vienodi";
    } else {
        cout << "skirtingi";
    }
    cout << endl;

    cout << "// Sukuriame integers5 masyvo integers1 pagrindu:" << endl;
    const Array integers5 = integers1;
    cout << "Masyvo integers5 dydis yra: " << integers5.getSize() << endl <<  integers5 << endl;

	cout << "integers5[0] reiksme yra " << integers5[0] << endl;

	//Atkomentave patestuokite priskyrima konstantiniam objektui (nesikompiliuos)
    //cout << "Bandome integers5 (konstantinis objektas) priskirti 4 elementa:" << endl;
    //integers5[4] = 100;
}

