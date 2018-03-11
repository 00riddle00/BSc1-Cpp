#include <iostream>
#include <algorithm>
using namespace std;

bool IsUsedSymbol(char c)
{
    switch(c) {
        case ' ':
        case '.':
        case ',':
        case '!':
        case ';':
        case ':':
        case '(':
        case ')':
            return false;
        default:
            return true;
    }
}

bool IsUnusedSymbol(char c)
{
    switch(c) {
        case ' ':
        case '.':
        case ',':
        case '!':
        case ';':
        case ':':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}


bool palindromeTester(string &original) {
    string original_modified = original;
    std::transform(original_modified.begin(), original_modified.end(), original_modified.begin(), ::tolower);

    //original_modified.erase(std::remove_if(original_modified.begin(), original_modified.end(), &IsUnusedSymbol), original_modified.end());
    
    string res;
    std::copy_if(original_modified.begin(), original_modified.end(), std::back_inserter(res), IsUsedSymbol);
    original_modified = res;

    string reversed = original_modified;
    std::reverse(reversed.begin(), reversed.end());
    if (original_modified == reversed) {
        return true;
    }
    return false;
}


int main() {
    string str1 = "radar";
    string str2 = "radars";
    string str3 = "RaDar";
    string str4 = "rada r radar";
    string str5 = "rada., r! (radar;:)";

    cout.setf(std::ios::boolalpha);

    cout << palindromeTester(str1) << endl;
    cout << palindromeTester(str2) << endl;
    cout << palindromeTester(str3) << endl;
    cout << palindromeTester(str4) << endl;
    cout << palindromeTester(str5) << endl;
}

