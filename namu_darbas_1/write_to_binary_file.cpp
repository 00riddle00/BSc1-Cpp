#include <iostream>
#include <fstream>
#include <string>

#include "write_to_binary_file.h"

using namespace std;

WriteToBinaryFile::WriteToBinaryFile(const string& filename) {
    this->filename = filename;
    otf.open(filename, ios::out | ios::binary);

    cout << "WriteToBinaryFile object is created" << endl;
}

WriteToBinaryFile::~WriteToBinaryFile() {
    if (otf.is_open()) {
        this->close();
    }
    cout << "WriteToBinaryFile object is destroyed" << endl;
}

void WriteToBinaryFile::write(const string& line, int size) {
    otf.write(line.c_str(), size);
}

void WriteToBinaryFile::write(float number) {
    otf.write((char*)&number, sizeof(float));
}

void WriteToBinaryFile::write(int number) {
    otf.write((char*)&number, sizeof(int));
}

void WriteToBinaryFile::close() {
   cout << "closing the file " << filename << endl;
   otf.close();
}

