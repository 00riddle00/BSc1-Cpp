#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "automobilis.h"
// TODO fix this temp solution
using namespace std;

Automobilis::Automobilis() {
    this->gamintojas = "Nenurodyta";
    this->modelis = "Nenurodyta";
    this->variklioTuris = 0.0;
    this->gamybosMetai = 0;
    this->kaina = 0;
    cout << "Automobilis (gamintojas: " << this->gamintojas << ") sukurtas be parametru" << endl;
}

Automobilis::Automobilis(const string& gamintojas, const string& modelis, float variklioTuris, int gamybosMetai, int kaina) {
    this->gamintojas = gamintojas;
    this->modelis = modelis;
    this->variklioTuris = variklioTuris;
    this->gamybosMetai = gamybosMetai;
    this->kaina = kaina;
    cout << "Automobilis (gamintojas: " << this->gamintojas << ") sukurtas su pateiktais parametrais" << endl;
}

Automobilis::~Automobilis() {
    cout << "Automobilis (gamintojas: " << this->gamintojas << ") pasalintas" << endl;
}

void Automobilis::setGamintojas(const string& gamintojas) {

    // validacija
    int error = 0;

    for (size_t i = 0; i < gamintojas.length(); i++) {
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

void Automobilis::setModelis(const string& modelis) {
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


void Automobilis::setGamybosMetai(int gamybosMetai) {
    this->gamybosMetai = gamybosMetai;
}

int Automobilis::getGamybosMetai() {
    return gamybosMetai;
}

void Automobilis::setKaina(int kaina) {
    this->kaina = kaina;
}

int Automobilis::getKaina() {
    return kaina;
}

void Automobilis::print() {
    cout << "Gamintojas: " << gamintojas << ", Modelis: " << modelis;
    cout << ", Variklio turis: " << fixed << setprecision(1) << variklioTuris << "l";
    cout << ", Gamybos metai: " << gamybosMetai << ", Kaina: " << kaina << " Eur" << endl;
}

void Automobilis::printToTextFile(ofstream& otf) {
    otf << gamintojas << endl
        << modelis << endl
        << variklioTuris << endl
        << gamybosMetai << endl
        << kaina << endl << endl;
}

void Automobilis::loadFromTextFile(std::ifstream& itf) {
    itf >> gamintojas;
    itf >> modelis;
    itf >> variklioTuris;
    itf >> gamybosMetai;
    itf >> kaina;
}
