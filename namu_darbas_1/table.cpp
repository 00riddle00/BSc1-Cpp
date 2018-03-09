#include <iostream>
#include <iomanip>
#include <vector>

#include "table.h"

using namespace std;

Table::Table(vector<string> params, vector<int> column_widths) {
    setParams(params);
    setColumnWidths(column_widths);
}

void Table::setParams(vector<string> params) {
    this->params = params;
}

void Table::setColumnWidths(vector<int> column_widths) {
    if (!this->params.size()) {
        throw 0;
    }

    if (column_widths.size() != this->params.size()) {
        throw 0;
    }

    this->column_widths = column_widths;
}


void Table::print_heading() {
    int count = this->params.size();
    int length = 0;

    for (auto& n : this->column_widths)
        length += n;

    length += count + 1;

    cout << string(length, '_') << endl;
    cout << "|";

    for (int i = 0; i < count; i++) {

        int diff = this->column_widths[i] - this->params[i].length(); 
        int odd = diff % 2;
        int left_space = (diff / 2);
        int right_space = (diff / 2 + odd);
    
        cout << setw(left_space) << " " << this->params[i] << setw(right_space) << " " << "|";
    }
    cout << endl;

    cout << "|";

    for (int i = 0; i < count; i++) {
        cout << string(this->column_widths[i], '_') << "|";
    }
    cout << endl;
}


void Table::printEntry(vector<string> args) {
    int count = this->params.size();

    cout << "|";

    for (int i = 0; i < count; i++) {
        cout << setw(this->column_widths[i]) << args[i] << "|";
    }
    cout << endl;

    cout << "|";

    for (int i = 0; i < count; i++) {
        cout << string(this->column_widths[i], '_') << "|";
    }
    cout << endl;

}


