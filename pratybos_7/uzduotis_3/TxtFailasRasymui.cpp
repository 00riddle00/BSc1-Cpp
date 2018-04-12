#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class TxtFailasRasymui : public ofstream {
    string fileName;
    ios_base::openmode mode;

    int kiekEiluciu() {
        ifstream in(fileName.c_str());

        int count = 0;
        string word;

        while (in >> word)
            count++;

        cout << "word count is: " << count << endl;

        in.close();

        return count;
    }

    public: 
        TxtFailasRasymui(const string& file, ios_base::openmode mode = ios_base::out) : ofstream(file.c_str()), fileName(file), mode(mode) { }

};

int main() {
    TxtFailasRasymui out("file.txt");

    if (out.is_open()) {
        cout << "File is open" << endl;
    }

    out << "Random text" << endl;
    out << "Random text" << endl;
    out << "Random text" << endl;
    out << "Random text" << endl;

    out.close();

/*    out.open("file.txt", ios::in);*/

    //int count = 0;
    //string word;

    //while (out >> word)
        //count++;

    /*cout << "word count is: " << count << endl;*/

}

