#include <iostream>
#include <iomanip>
#include <string>
#include "automobilis.h"
using namespace std;


void Automobilis::setGamintojas(string gamintojas) {

    // validacija
    int error = 0;

    for (int i = 0; i < gamintojas.length(); i++) {
        if(isdigit(gamintojas[i])) {
            error = 1;
            break;
        }
    }

    if(error) {
        printf("Gamintojas negali tureti skaiciu\n");
    } else {
        this->gamintojas = gamintojas;
    }
    
}

string Automobilis::getGamintojas() {
    return gamintojas;
}

void Automobilis::setModelis(string modelis) {
    this->modelis = modelis;
}

string Automobilis::getModelis() {
    return modelis;
}

void Automobilis::setVariklioTuris(float variklioTuris) {
    this->variklioTuris = variklioTuris;
}

float Automobilis::getVariklioTuris() {
    return variklioTuris;
}

void Automobilis::print() {
    cout << "Gamintojas: " << gamintojas << ", Modelis: " << modelis << ", Variklio turis: " << fixed << setprecision(1) << variklioTuris << "l" << endl;
}

