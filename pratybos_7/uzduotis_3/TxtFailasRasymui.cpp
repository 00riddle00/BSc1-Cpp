#include <iostream>
#include <fstream>
#include <iomanip>
#include <streambuf>
using namespace std;

class TxtFailasRasymui : public ofstream {
    string fileName;
    ios_base::openmode mode;

    TxtFailasRasymui(const string& file, ios_base::openmode mode = ios_base::out) : ofstream(file.c_str()) {
        fileName = file;
        // FIXME nebutina
        mode = mode;
    }

};






class Leidinys {
    bool skolinamas;
    bool paskolintas;

    public:
        Leidinys(bool skol = true, bool paskol = false) {
            skolinamas = skol;
            paskolintas = paskol;
            cout << "Leidinys object is created" << endl;
        }

        ~Leidinys() {
            cout << "Leidinys object is destroyed" << endl;
        }

        void change_skolinamas(bool skol) {
            skolinamas = skol;
        }

        bool is_skolinamas() {
            return skolinamas;
        }

        virtual void print_info() {}
 
        virtual void is_skolinamas_print() {
            if (skolinamas) {
                cout << "Leidinys yra skolinamas" << endl;
            } else {
                cout << "Leidynys nera skolinamas" << endl;
            }
        }

        bool is_paskolintas() {
            return paskolintas;
        }

        void paskolinti() {
            if (skolinamas) {
                paskolintas = true;
            }
        }

        void grazinti() {
            if (paskolintas) {
                paskolintas = false;
            }
        }
};

class Knyga: public Leidinys {
    string autorius;
    string pavadinimas;
    size_t leidimo_metai;

    public:
        Knyga(string aut = "NA", string pav = "NA", size_t metai=0, bool skol=true) {
            autorius = aut;
            pavadinimas = pav;
            leidimo_metai = metai;
            change_skolinamas(skol);
            cout << "Knyga object is created" << endl;
        }

        ~Knyga() {
            cout << "Knyga object is destroyed" << endl;
        }

        void print_info() {
            cout << "Autorius: " << autorius << endl
                << "Pavadinimas: " << pavadinimas << endl
                << "Leidimo metai: " << leidimo_metai << endl;
            if (is_skolinamas() && is_paskolintas()) {
                cout << "Knyga yra paskolinta" << endl;
            } else if (!is_skolinamas()) {
                cout << "Knyga nera skolinama" << endl;
            } else {
                cout << "Knyga nera paskolinta" << endl;
            }
        }

        void is_skolinamas_print() {
            if (is_skolinamas()) {
                cout <<"Knyga yra skolinama" << endl;
            } else {
                cout << "Knyga nera skolinama" << endl;
            }
        }

};

class AudioIrasas: public Leidinys {
    string atlikejas;
    string pavadinimas;
    float trukme;
    public:
        AudioIrasas(string atl = "NA", string pav = "NA", float truk = 60.0) {
            atlikejas = atl;
            pavadinimas = pav;
            trukme = truk;
            cout << "AudioIrasas object is created" << endl;
        }

        ~AudioIrasas() {
            cout << "AudioIrasas object is destroyed" << endl;
        }

        void print_info() {
            cout << "Atlikejas: " << atlikejas << endl
                << "Pavadinimas: " << pavadinimas << endl
                << "Trukme: " << fixed << setprecision(1) << trukme <<  endl;

            if (is_skolinamas() && is_paskolintas()) {
                cout << "AudioIrasas yra paskolintas" << endl;
            } else if (!is_skolinamas()) {
                cout << "AudioIrasas nera skolinamas" << endl;
            } else {
                cout << "AudioIrasas nera paskolintas" << endl;
            }
        }

        void is_skolinamas_print() {
            if (is_skolinamas()) {
                cout <<"AudioIrasas yra skolinamas" << endl;
            } else {
                cout << "AudioIrasas nera skolinamas" << endl;
            }
        }
};


class RetaKnyga: public Knyga {
    void change_skolinamas(bool);
    void paskolinti();
    void grazinti();
    void paskolintas();

    public:
        RetaKnyga(string aut = "NA", string pav = "NA", size_t metai=0) : Knyga(aut, pav, metai, false) {
            cout << "RetaKnyga object is created" << endl;
        }

        ~RetaKnyga() {
            cout << "RetaKnyga object is destroyed" << endl;
        }

        void is_skolinamas_print() {
            cout <<"RetaKnyga yra neskolinama" << endl;
        }

};

int main() {

    size_t size_leidiniai = 3;
    Leidinys* leidiniai[size_leidiniai] = {
        new Knyga("A.Lindgren", "Broliai Liutasirdziai", 2015),
        new AudioIrasas("Vytautas Kernagis", "Akustinis", 80.0),
        new RetaKnyga("Claro Vascotti", "Institutiones Historiae Ecclesiasticae Novi Foederis", 1895)
    };

    cout << "---------------------------" << endl;
    for (size_t i = 0; i < size_leidiniai; i++) {
        leidiniai[i]->print_info();
        leidiniai[i]->is_skolinamas_print();
        cout << "---------------------------" << endl;
    }
    cout << "---------------------------" << endl;

    leidiniai[1]->paskolinti();
    leidiniai[1]->print_info();

    cout << "---------------------------" << endl;

    leidiniai[0]->paskolinti();
    leidiniai[0]->print_info();

    cout << "---------------------------" << endl;
    leidiniai[0]->grazinti();
    leidiniai[0]->print_info();

    cout << "---------------------------" << endl;
}
