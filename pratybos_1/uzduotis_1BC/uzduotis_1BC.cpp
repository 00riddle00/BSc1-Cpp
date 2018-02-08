#include <iostream> 

using namespace std;

int main() {

    string input("Enter side length of a square: ");
    string sideHex = "side length in hex = 0x";
    string areaDec = "square area in decimal = ";

    int side;

    cout << input;

    cin >> side;

    cout << sideHex << hex << side << char(10);

    cout << areaDec << dec << side * side << char(10);

}
