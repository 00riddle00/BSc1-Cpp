#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class TxtFailasRasymui : public ofstream {
    string fileName;
    ios_base::openmode mode;
    ifstream in;

    public: 
        TxtFailasRasymui(const string& file, ios_base::openmode mode = ios_base::out) : ofstream(file.c_str()), fileName(file), mode(mode) { }

    int kiekEiluciu() {
        in.open(fileName.c_str(), ifstream::in);

        int count = 0;
        string line;

        while(getline(in,line)) {
            count++;
        }
        in.close();

        return count;
    }

    int kiekZodziu() {
        in.open(fileName.c_str(), ifstream::in);

        int count = 0;
        string word;

        while (in >> word)
            count++;

        in.close();

        return count;
    }


};

int main() {
    TxtFailasRasymui out("file.txt");

    if (out.is_open()) {
        cout << "File is opened" << endl;
    }

    out << "Random text" << endl;
    out << "Random text" << endl;
    out << "Random text" << endl;
    out << "Random text" << endl;

    cout << "Zodziu kiekis: "<< out.kiekZodziu() << endl;
    cout << "Eiluciu kiekis: "<< out.kiekEiluciu() << endl;

    out.close();

    if (!out.is_open()) {
        cout << "File is closed" << endl;
    }
}

