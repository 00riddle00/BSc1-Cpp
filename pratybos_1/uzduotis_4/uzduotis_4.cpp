#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {

    string target = argv[1];
    string filename = argv[2];

    ifstream in(filename);

    int count;
    string word;

    while(in >> word) {
        if (word == target)
            count++;
    }

    cout << count << endl;

}
