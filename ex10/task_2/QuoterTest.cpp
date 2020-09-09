#include <iostream>
#include <cstdlib> // Random number generator
#include <ctime> // To seed random generator
using namespace std;

#include "Quoter.h"

int main() {

    Quoter quoter1;
    cout << quoter1.quote() << endl;
    cout << quoter1.quote() << endl;
    cout << quoter1.quote() << endl;

    cout << "Last quote is:" << endl;
    cout << quoter1.lastQuote() << endl;

    const Quoter quoter2;
    
    // Šią eilutę reikia užkomentuoti,
    // kitaip nesikompiliuos, nes objektui
    // konstantai kviečiamas nekonstantinis
    // metodas
    cout << quoter2.quote() << endl;

    cout << "Last quote is:" << endl;
    cout << quoter2.lastQuote() << endl;
}

