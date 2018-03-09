#include <iostream>
#include <iomanip>
#include <vector>

#include "car.h"
#include "table.h"
#include "Helpers.h"

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

//void Database::reset_filter() {

    //for (int i = 0; i < this->size; i++) {
        //Car *cur = this->rows[i];
        //if (cur) {
            //cur->setFilter(true);
        //}
    //}
//}

//void Database::filter_by_make(int type, const string& value) {

    //switch(type) {
        //case 1:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarMake() != value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 2:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarMake().find(value) == std::string::npos) {
                        //cur->setFilter(false);
                    //}
                //}
            //}
            //break;
        //case 3:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarMake() == value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 4:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarMake().find(value) != std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
    //}
//}

//void Database::filter_by_model(int type, const string& value) {

    //switch(type) {
        //case 1:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarModel() != value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 2:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarModel().find(value) == std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 3:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarModel() == value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 4:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //if (cur->getCarModel().find(value) != std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
    //}
//}


//void Database::filter_by_year(int type, const string& value) {


    //switch(type) {
        //case 1:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_year = to_string(cur->getCarYear());
                    //if (car_year != value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 2:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_year = to_string(cur->getCarYear());
                    //if (car_year.find(value) == std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 3:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_year = to_string(cur->getCarYear());
                    //if (car_year == value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 4:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_year = to_string(cur->getCarYear());
                    //if (car_year.find(value) != std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
    //}
//}


//void Database::filter_by_price(int type, const string& value) {


    //switch(type) {
        //case 1:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_price = to_string(cur->getCarPrice());
                    //if (car_price != value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 2:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_price = to_string(cur->getCarPrice());
                    //if (car_price.find(value) == std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 3:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_price = to_string(cur->getCarPrice());
                    //if (car_price == value) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
        //case 4:
            //for (int i = 0; i < this->size; i++) {
                //Car *cur = this->rows[i];
                //if (cur) {
                    //string car_price = to_string(cur->getCarPrice());
                    //if (car_price.find(value) != std::string::npos) {
                        //cur->setFilter(false);
                    //} 
                //}
            //}
            //break;
    //}
//}



//void Database::sort_lex_by_make(int first, int last) {

    //int i, j;
    //Car* temp;

    //for (i = first; i < last; ++i)

        //for (j = i + 1; j < last + 1; ++j) {

            //if (this->rows[i]->getCarMake() > this->rows[j]->getCarMake()) {
                //temp = this->rows[i];
                //this->rows[i] = this->rows[j];
                //this->rows[j] = temp;
            //}
        //}
//}


//void Database::sort_lex_by_model(int first, int last) {

    //int i, j;
    //Car* temp;

    //for (i = first; i < last; ++i)

        //for (j = i + 1; j < last + 1; ++j) {

            //if (this->rows[i]->getCarModel() > this->rows[j]->getCarModel()) {
                //temp = this->rows[i];
                //this->rows[i] = this->rows[j];
                //this->rows[j] = temp;
            //}
        //}
//}

//void Database::sort_by_year(int first, int last) {

    //Car* temp;
    //int pivot, j, i;

    //if (first < last) {
        //pivot = first;
        //i = first;
        //j = last;

        //while (i < j) {
            //while (
                //this->rows[i]->getCarYear() <= this->rows[pivot]->getCarYear() && i < last) {
                //i++;
            //}
            //while (this->rows[j]->getCarYear() > this->rows[pivot]->getCarYear()) {
                //j--;
            //}
            //if (i < j) {
                //temp = this->rows[i];
                //this->rows[i] = this->rows[j];
                //this->rows[j] = temp;
            //}
        //}

        //temp = this->rows[pivot];
        //this->rows[pivot] = this->rows[j];
        //this->rows[j] = temp;

        //sort_by_year(first, j - 1);
        //sort_by_year(j + 1, last);
    //}
//}

//void Database::sort_by_price(int first, int last) {

    //Car* temp;
    //int pivot, j, i;

    //if (first < last) {
        //pivot = first;
        //i = first;
        //j = last;

        //while (i < j) {
            //while (
                //this->rows[i]->getCarPrice() <= this->rows[pivot]->getCarPrice() && i < last) {
                //i++;
            //}
            //while (this->rows[j]->getCarPrice() > this->rows[pivot]->getCarPrice()) {
                //j--;
            //}
            //if (i < j) {
                //temp = this->rows[i];
                //this->rows[i] = this->rows[j];
                //this->rows[j] = temp;
            //}
        //}

        //temp = this->rows[pivot];
        //this->rows[pivot] = this->rows[j];
        //this->rows[j] = temp;

        //sort_by_price(first, j - 1);
        //sort_by_price(j + 1, last);
    //}
//}


//void Database::sort_by_id(int first, int last)
//{

    //Car* temp;
    //int pivot, j, i;

    //if (first < last) {
        //pivot = first;
        //i = first;
        //j = last;

        //while (i < j) {
            //while (
                //this->rows[i]->getID() <= this->rows[pivot]->getID() && i < last) {
                //i++;
            //}
            //while (this->rows[j]->getID() > this->rows[pivot]->getID()) {
                //j--;
            //}
            //if (i < j) {
                //temp = this->rows[i];
                //this->rows[i] = this->rows[j];
                //this->rows[j] = temp;
            //}
        //}

        //temp = this->rows[pivot];
        //this->rows[pivot] = this->rows[j];
        //this->rows[j] = temp;

        //sort_by_id(first, j - 1);
        //sort_by_id(j + 1, last);
    //}
//}


