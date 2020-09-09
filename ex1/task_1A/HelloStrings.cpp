#include <string>

#include <iostream>

using namespace std;

int main() {

string s1, s2; // Empty strings

string s3 = "Hello, World."; // Initialized

string s4("Today is"); // Also initialized

s2 = "of September"; // Assigning to a string

s1 = s3 + " " + s4; // Combining strings

s1 += " 7 "; // Appending to a string

cout << s1 + s2 + "!" << endl;

}
