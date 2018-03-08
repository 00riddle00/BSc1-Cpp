#include <iostream>
#include <iomanip>
#include <vector>

#include "car.h"
#include "database.h"
#include "Helpers.h"

using namespace std;

/*void Database::print_heading() {*/

    //cout << string(90, '_') << endl

         //<< "| " << "ID" << " |" 
         //<< setw(13) << " " << "Make" << setw(13) << " " << "|"
         //<< setw(12) << " " << "Model" << setw(13) << " " << "|"
         //<< setw(3) << " " << "Year" << setw(3) << " " << "|"
         //<< setw(2) << " " << "Price" << setw(3) << " " << "|" << endl

         //<< "|" << string(4, '_') << "|" 
         //<< string(30, '_') << "|" 
         //<< string(30, '_') << "|" 
         //<< string(10, '_') << "|" 
         //<< string(10, '_') << "|" << endl;
//}

//void Database::database_set(int id, Car* car) { 
    //if (this->size == this->capacity) {
        //this->capacity += CHUNK_SIZE;
        //for (int i = this->size; i < this->capacity; i++) {
            //this->rows.push_back(new Car());
        //}
    //}
   
    //int i;
    //for (i = 0; i < this->capacity; i++) {
        //if (this->rows[i]->getID() == 0) {
            //break;
        //}
    //}

    //// TODO gal prideti vector.erase ?
    //this->rows[i] = car;
    //cout << "ID: " << this->rows[i]->getID() << endl;
    //this->size += 1;

    //cout << "Successfully saved, ID = " << id << endl;
//}


//void Database::database_get(int id) {
    //for (int i = 0; i < this->size; i++) {
        //Car *car = this->rows[i];
        //if (car->getID() == id) {
            //if (car) {
                //this->print_heading();
                //this->car_print(car);
                //return;
            //} 
        //}
    //}
    //cout << "ID is not set" << endl;
//}


//void Database::database_list(int reverse [>= 0*/, int filtered /*= 0<]) {

    //this->print_heading();

    //if (this->size == 0) {
        //cout << "No entries." << endl;
        //return;
    //}

    //if (!filtered) {
        //if (!reverse) {
            //for (int i = 0; i < this->capacity; i++) {
                //if (this->rows[i]->getID()) {
                    //this->car_print(this->rows[i]);
                //}
            //}
        //} else {
            //for (int i = this->capacity - 1; i >= 0; i--) {
                //if (this->rows[i]->getID()) {
                    //this->car_print(this->rows[i]);
                //}
            //}
        //}
    //} else {
        //if (!reverse) {
            //// TODO niekur neklausia ar ID egzistuoja
            //for (int i = 0; i < this->capacity; i++) {
                //if (this->rows[i]->getID() && this->rows[i]->getFilter()) {
                    //this->car_print(this->rows[i]);
                //}
            //}
        //} else {
            //for (int i = this->capacity - 1; i >= 0; i--) {
                //if (this->rows[i]->getID() && this->rows[i]->getFilter()) {
                    //this->car_print(this->rows[i]);
                //}
            //}
        //}
    //}
//}

//void Database::database_delete(int id) {
    //for (int i = 0; i < this->capacity; i++) {
        //Car *car = this->rows[i];
        //if (car->getID() == id) {
            //if (Helpers::choice("Do you really want to delete this entry?")) {
                //this->rows[i] = new Car();
                //this->size--;
                //cout << "Successfully deleted" << endl;
                //return;
            //}
        //}
    //}
    //cout << "No such entry in database" << endl;
//}


//void Database::perform_action(int action) {
    //int field; 
    //int type;

    //switch(action) {
        //case 1: {
            //cout << "By which field would you like to filter? (enter a number)" << endl
                 //<< "(1) Make" << endl
                 //<< "(2) Model" << endl
                 //<< "(3) Year" << endl
                 //<< "(4) Price" << endl;

            //while(1) {
                //cout << "(Enter a number) > ";
                //cin >> field;

                //if (field < 1 || field > 4) {
                    //cout << "Such option does not exist" << endl;
                    //continue;
                //}
                //break;
            //}

            //cout << "How would you like to filter?" << endl
                 //<< "(1) Entry is equal to the given value" << endl
                 //<< "(2) Entry contains the given value" << endl
                 //<< "(3) Entry is not equal to the given value" << endl
                 //<< "(4) Entry does not contain the given value" << endl;

            //while(1) {
                //cout << "(Enter a number) > ";
                //cin >> type;

                //if (type < 1 || type > 4) {
                    //cout << "Such option does not exist" << endl;
                    //continue;
                //}
                //break;
            //}

            //cout << "Please enter a value to be filtered by" << endl;

            //string value;
            //cout << "(Enter a value) > ";
            //cin >> value;
            //cin.get();

            //switch(field) {
                //case 1:
                    //this->filter_by_make(type, value);
                    //break;
                //case 2:
                    //this->filter_by_model(type, value);
                    //break;
                //case 3:
                    //this->filter_by_year(type, value);
                    //break;
                //case 4:
                    //this->filter_by_price(type, value);
                    //break;
            //}
            //this->database_list(0, 1);
            //this->reset_filter();
            //break;
        //}

        //case 2: {
            //cout << "By which field would you like to sort? (enter a number)" << endl
                 //<< "(1) Make" << endl
                 //<< "(2) Model" << endl
                 //<< "(3) Year" << endl
                 //<< "(4) Price" << endl;

            //while(1) {
                //cout << "(Enter a number) > ";
                //cin >> field;

                //if (field < 1 || field > 4) {
                    //cout << "Such option does not exist" << endl;
                    //continue;
                //}
                //break;
            //}

            //cout << "How would you like to sort?" << endl
                 //<< "(1) Ascending order" << endl
                 //<< "(2) Descending order" << endl;

            //while(1) {
                //cout << "(Enter a number) > ";
                //cin >> type;

                //if (type < 1 || type > 2) {
                    //cout << "Such option does not exist" << endl;
                    //continue;
                //}
                //break;
            //}

            //int reverse = (type == 1) ? 0 : 1;

            //switch(field) {
                //case 1:
                    //this->sort_lex_by_make(0, this->size - 1);
                    //break;
                //case 2:
                    //this->sort_lex_by_model(0, this->size - 1);
                    //break;
                //case 3:
                    //this->sort_by_year(0, this->size - 1);
                    //break;
                //case 4:
                    //this->sort_by_price(0, this->size - 1);
                    //break;
            //}
            //this->database_list(reverse);
            //break;
        //}
    //}
//}


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


