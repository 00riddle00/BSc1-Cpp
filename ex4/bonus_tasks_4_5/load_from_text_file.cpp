#include <iostream>
#include <fstream>
#include <string>
#include "load_from_text_file.h"
using namespace std;

LoadFromTextFile::LoadFromTextFile(const string& filename) {
    this->filename = filename;
    itf.open(filename, std::ofstream::in);
    cout << "LoadFromTextFile object is created" << endl;
}

LoadFromTextFile::~LoadFromTextFile() {
    if (itf.is_open()) {
        close();
    }
    cout << "LoadFromTextFile object is destroyed" << endl;
}

string LoadFromTextFile::readline() {
    string line;
    itf >> line;
    return line;
}

void LoadFromTextFile::close() {
    itf.close();
    cout << "closing the file " << filename << endl;
}

