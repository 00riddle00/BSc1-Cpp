#include <iostream>
using namespace std;

class Leidinys {
    public:
        Leidinys() {
            cout << "Leidinys object is created" << endl;
        }

        virtual ~Leidinys() {
            cout << "Leidinys object is destroyed" << endl;
        }

        virtual void spausdinti() {
            cout << "Leidinys" << endl;
        }
};

class Knyga: public Leidinys {
    public:
        Knyga() {
            cout << "Knyga object is created" << endl;
        }

        ~Knyga() {
            cout << "Knyga object is destroyed" << endl;
        }

        void spausdinti() {
            cout << "Knyga" << endl;
        }
};

class Zurnalas: public Leidinys {
    public:
        Zurnalas() {
            cout << "Zurnalas object is created" << endl;
        }

        ~Zurnalas() {
            cout << "Zurnalas object is destroyed" << endl;
        }

        void spausdinti() {
            cout << "Zurnalas" << endl;
        }
};

class AudioIrasas: public Leidinys {
    public:
        AudioIrasas() {
            cout << "AudioIrasas object is created" << endl;
        }

        ~AudioIrasas() {
            cout << "AudioIrasas object is destroyed" << endl;
        }

        void spausdinti() {
            cout << "AudioIrasas" << endl;
        }
};

;

int main() {


    size_t size_leidiniai = 3;
    Leidinys* leidiniai[size_leidiniai] = {new Knyga, new Zurnalas, new AudioIrasas};

    cout << "---------------------------" << endl;
    for (size_t i = 0; i < size_leidiniai; i++) {
        leidiniai[i]->spausdinti();
    }

    cout << "---------------------------" << endl;

    for (size_t i = 0; i < size_leidiniai; i++) {
        delete leidiniai[i];
    }
}
