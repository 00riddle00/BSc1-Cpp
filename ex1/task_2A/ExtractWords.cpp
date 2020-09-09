#include <string>

#include <iostream>

#include <fstream>

using namespace std;

int main() {

ifstream in("ExtractWords.cpp");

string word;

while(in >> word)

cout << word << endl;

}
