#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "automobilis.h"
#include "write_to_binary_file.h"
using namespace std;

class LoadFromBinaryFile {
        ifstream itf;
        string filename;

    public:
        LoadFromBinaryFile(const string& filename) {
            this->filename = filename;
            itf.open(filename, ios::in | ios::binary);
            cout << "LoadFromBinaryFile object is created" << endl;
        }

        ~LoadFromBinaryFile() {
            if (itf.is_open()) {
                close();
            }
            cout << "LoadFromBinaryFile object is destroyed" << endl;
        }

        string readString(int len) {
            string my_string;
            char* temp = new char[len+1];
            itf.read(temp, len);
            temp[len] = '\0';
            my_string = temp;
            delete [] temp;
            return my_string;
        }

        int readInt() {
            int my_int;
            itf.read((char*)&my_int, sizeof(int));
            return my_int;
        }

        float readFloat() {
            float my_float;
            itf.read((char*)&my_float, sizeof(float));
            return my_float;
        }

        void close() {
            itf.close();
            cout << "closing the file " << filename << endl;
        }
};


class WriteToTextFile {
        ofstream otf;
        string filename;

    public:
        WriteToTextFile(const string& filename) {
            this->filename = filename;
            otf.open(filename, std::ofstream::out | std::ofstream::app);
            cout << "WriteToTextFile object is created" << endl;
        }

        ~WriteToTextFile() {
            if (otf.is_open()) {
                this->close();
            }
            cout << "WriteToTextFile object is destroyed" << endl;
        }

        void write(const string& line) {
            otf << line << endl;
        }

        void write(float number) {
            otf << number << endl;
        }

       void write(int number) {
            otf << number << endl;
        }

       void close() {
           cout << "closing the file " << filename << endl;
           otf.close();
       }
};


class LoadFromTextFile {
    public:
        ifstream itf;
        string filename;

        LoadFromTextFile(const string& filename) {
            this->filename = filename;
            itf.open(filename, std::ofstream::in);
            cout << "LoadFromTextFile object is created" << endl;
        }

        ~LoadFromTextFile() {
            if (itf.is_open()) {
                close();
            }
            cout << "LoadFromTextFile object is destroyed" << endl;
        }

        string readline() {
            string line;
            itf >> line;
            return line;
        }

        void close() {
            itf.close();
            cout << "closing the file " << filename << endl;
        }
};



int main(int argc, char *argv[]) {

    Automobilis automobilis01("Toyota", "Avensis", 1.8, 2000, 2500);

    string separator = "-------------------------\n";

    cout << separator;
    cout << "Automobilis1:" << endl;
    automobilis01.print();
    cout << separator;

    const string textFile = argv[1];
    const string binaryFile = argv[2];

    WriteToTextFile wt(textFile);
    wt.write(automobilis01.getGamintojas());
    wt.write(automobilis01.getModelis());
    wt.write(automobilis01.getVariklioTuris());
    wt.write(automobilis01.getGamybosMetai());
    wt.write(automobilis01.getKaina());
    wt.write("");
    wt.close();

    WriteToBinaryFile wb(binaryFile);

    const int len_gamintojas = automobilis01.getGamintojas().size();
    const int len_modelis = automobilis01.getModelis().size();

    wb.write(automobilis01.getGamintojas(), len_gamintojas);
    wb.write(automobilis01.getModelis(), len_modelis);
    wb.write(automobilis01.getVariklioTuris());
    wb.write(automobilis01.getGamybosMetai());
    wb.write(automobilis01.getKaina());
    wb.close();

    Automobilis automobilis02;

    LoadFromTextFile lt(textFile);
    automobilis02.setGamintojas(lt.readline());
    automobilis02.setModelis(lt.readline());
    automobilis02.setVariklioTuris(lt.readline());
    automobilis02.setGamybosMetai(lt.readline());
    automobilis02.setKaina(lt.readline());
    lt.close();

    cout << separator;
    cout << "Automobilis2:" << endl;
    automobilis02.print();
    cout << separator;

    Automobilis automobilis03;

    LoadFromBinaryFile lb(binaryFile);

    automobilis03.setGamintojas(lb.readString(len_gamintojas));
    automobilis03.setModelis(lb.readString(len_modelis));
    automobilis03.setVariklioTuris(lb.readFloat());
    automobilis03.setGamybosMetai(lb.readInt());
    automobilis03.setKaina(lb.readInt());
    lb.close();

    cout << separator;
    cout << "Automobilis3:" << endl;
    automobilis03.print();
    cout << separator;
}

