#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "automobilis.h"
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
    cout << "Automobilis (gamintojas: " << this->gamintojas << ") sukurtas su pateiktais atitinkamu tipu parametrais" << endl;
}


Automobilis::Automobilis(const string& gamintojas, const string& modelis, const string& variklioTuris, const string& gamybosMetai, const string& kaina) {
    setGamintojas(gamintojas);
    setModelis(modelis);
    setVariklioTuris(variklioTuris);
    setGamybosMetai(gamybosMetai);
    setKaina(kaina);
    cout << "Automobilis (gamintojas: " << this->gamintojas << ") sukurtas su pateiktais \"string\" parametrais" << endl;
}




Automobilis::~Automobilis() {
    cout << "Automobilis (gamintojas: " << this->gamintojas << ") pasalintas" << endl;
}

void Automobilis::setGamintojas(const string& gamintojas) {

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

void Automobilis::setModelis(const string& modelis) {
    this->modelis = modelis;
}

string Automobilis::getModelis() {
    return modelis;
}

void Automobilis::setVariklioTuris(float variklioTuris) {
    this->variklioTuris = variklioTuris;
}


void Automobilis::setVariklioTuris(const string& variklioTuris) {
    float vt = ::atof(variklioTuris.c_str());
    this->variklioTuris = vt;
}


float Automobilis::getVariklioTuris() {
    return variklioTuris;
}


void Automobilis::setGamybosMetai(int gamybosMetai) {
    this->gamybosMetai = gamybosMetai;
}

void Automobilis::setGamybosMetai(const string& gamybosMetai) {
    int gm = ::atoi(gamybosMetai.c_str());
    this->gamybosMetai = gm;
}


int Automobilis::getGamybosMetai() {
    return gamybosMetai;
}

void Automobilis::setKaina(int kaina) {
    this->kaina = kaina;
}

void Automobilis::setKaina(const string& kaina) {
    int k = ::atoi(kaina.c_str());
    this->kaina = k;
}

int Automobilis::getKaina() {
    return kaina;
}

void Automobilis::print() {
    cout << "Gamintojas: " << gamintojas << ", Modelis: " << modelis;
    cout << ", Variklio turis: " << fixed << setprecision(1) << variklioTuris << "l";
    cout << ", Gamybos metai: " << gamybosMetai << ", Kaina: " << kaina << " Eur" << endl;
}

