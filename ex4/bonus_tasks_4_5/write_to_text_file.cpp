#include <iostream>
#include <fstream>
#include <string>
#include "write_to_text_file.h"

using namespace std;


WriteToTextFile::WriteToTextFile(const string& filename) {
    this->filename = filename;
    otf.open(filename, std::ofstream::out | std::ofstream::app);
    cout << "WriteToTextFile object is created" << endl;
}

WriteToTextFile::~WriteToTextFile() {
    if (otf.is_open()) {
        this->close();
    }
    cout << "WriteToTextFile object is destroyed" << endl;
}

void WriteToTextFile::write(const string& line) {
    otf << line << endl;
}

void WriteToTextFile::write(float number) {
    otf << number << endl;
}

void WriteToTextFile::write(int number) {
    otf << number << endl;
}

void WriteToTextFile::close() {
   cout << "closing the file " << filename << endl;
   otf.close();
}

