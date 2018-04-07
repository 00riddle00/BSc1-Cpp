#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "automobilis.h"
using namespace std;

Automobilis automobilis01("Toyota", "Avensis", 1.8, 2000, 2500);

int main(int argc, char *argv[]) {

    string separator = "-------------------------\n";
    const size_t size = 3;

    automobilis01.print();

    char* filename = argv[1];

    ifstream file01(filename, ifstream::in);

    automobilis01.loadFromTextFile(file01);
    file01.close();

    cout << separator;
    automobilis01.print();
    cout << separator;


    Automobilis Automobilis02("Skoda", "Octavia", 2.0, 2010, 4000);

    Automobilis* automobilis1 = new Automobilis;
    automobilis1->setGamintojas("BMW");
    automobilis1->setModelis("520d");
    automobilis1->setVariklioTuris(3.0);
    automobilis1->setGamybosMetai(1998);
    automobilis1->setKaina(2000);

    automobilis1->print();

    Automobilis* automobilis2 = new Automobilis;
    automobilis2->setGamintojas("Audi");
    automobilis2->setModelis("A4");
    automobilis2->setVariklioTuris(2.0);
    automobilis2->setGamybosMetai(2002);
    automobilis2->setKaina(1800);
 
    automobilis2->print();

    Automobilis* automobilis3 = new Automobilis;
    automobilis3->print();

    Automobilis* automobilis4 = new Automobilis("Volkswagen", "Golf", 2.0, 2006, 3000);
    automobilis4->print();

    cout << separator;

    vector<Automobilis*> v;

    v.push_back(automobilis1);
    v.push_back(automobilis2);
    v.push_back(automobilis4);

    ofstream file02(filename, ofstream::out);

     for(int i = 0; i < v.size(); i++) {
        v[i]->print();
        v[i]->printToTextFile(file02);
     }

     file02.close();

    cout << separator;

    delete automobilis1;
    delete automobilis2;
    delete automobilis3;
    delete automobilis4;

    ifstream file03(filename, ifstream::in);

    Automobilis automobiliai[size];

    for (int i = 0; i < size; i++) {
        automobiliai[i].loadFromTextFile(file03);
    }

    cout << separator;

    for (int i = 0; i < size; i++) {
        automobiliai[i].print();
    }
    cout << separator;
    
    file03.close();


}

