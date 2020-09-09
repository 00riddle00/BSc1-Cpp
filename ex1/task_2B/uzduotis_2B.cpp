#include <string>
#include <fstream>

using namespace std;

int main() {

    int count = 0;
    ifstream in("uzduotis_2B.cpp");

    string word;

    while(in >> word)
        count++;

    cout << count << endl;

}
