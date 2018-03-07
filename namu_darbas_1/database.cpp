#include <iostream>
#include <iomanip>
#include <vector>

#include "address.h"
#include "database.h"
#include "Helpers.h"

using namespace std;

Database::Database() {
    this->size = 0;
    this->capacity = CHUNK_SIZE;

    for (int i = 0; i < this->capacity; i++) {
        this->rows.push_back(new Address());
    }
}

Database::Database(int size, int capacity) {
    this->size = size;
    this->capacity = capacity;

    for (int i = 0; i < this->capacity; i++) {
        this->rows.push_back(new Address());
    }
}

Database::~Database() {

    for (int i = 0; i < this->capacity; i++) {
        delete this->rows[i];
    }
}

void Database::setSize(int size) {
    this->size = size;
}

void Database::setCapacity(int capacity) {
    this->capacity = capacity;
}

int Database::getSize() {
    return this->size;
}
int Database::getCapacity() {
    return this->capacity;
}

void Database::print_heading() {

    cout << string(90, '_') << endl

         << "| " << "ID" << " |" 
         << setw(13) << " " << "Make" << setw(13) << " " << "|"
         << setw(12) << " " << "Model" << setw(13) << " " << "|"
         << setw(3) << " " << "Year" << setw(3) << " " << "|"
         << setw(2) << " " << "Price" << setw(3) << " " << "|" << endl

         << "|" << string(4, '_') << "|" 
         << string(30, '_') << "|" 
         << string(30, '_') << "|" 
         << string(10, '_') << "|" 
         << string(10, '_') << "|" << endl;
}

void Database::address_print(Address *addr) {

    cout << "|" << setw(4) << addr->id << "|"
         << setw(30) << addr->getCarMake()<< "|"
         << setw(30) << addr->getCarModel() << "|"
         << setw(10) << addr->getCarYear() << "|"
         << setw(10) << addr->getCarPrice() << "|"
         << endl;

    cout << "|" << string(4, '_') << "|" 
         << string(30, '_') << "|" 
         << string(30, '_') << "|" 
         << string(10, '_') << "|" 
         << string(10, '_') << "|" 
         << endl;
}


// function for debugging
void Database::debugTable() {
    int i = 0;

    cout << "db size: " << this->size << endl;
    cout << "db capacity: " << this->capacity << endl;

    this->print_heading();

    for (i = 0; i < this->capacity; i++) {
        this->address_print(this->rows[i]);
    }
}


void Database::database_set(int id, Address* addr) { 
    if (this->size == this->capacity) {
        this->capacity += CHUNK_SIZE;
        //this->rows = (Address**) realloc(this->rows, this->capacity * sizeof(Address*));
        for (int i = this->size; i < this->capacity; i++) {
            this->rows.push_back(new Address());
            //this->rows[i] = (Address*) calloc(1, sizeof(Address));
        }
    }
   
    int i;
    for (i = 0; i < this->capacity; i++) {
        if (this->rows[i]->id == 0) {
            break;
        }
    }

    addr->id = id;
    addr->filter = 1;

    this->rows[i] = addr;
    this->size += 1;

    cout << "Successfully saved, ID = " << id << endl;
}


void Database::database_get(int id) {
    for (int i = 0; i < this->size; i++) {
        Address *addr = this->rows[i];
        if (addr->id == id) {
            if (addr) {
                this->print_heading();
                this->address_print(addr);
                return;
            } 
        }
    }
    cout << "ID is not set" << endl;
}


void Database::database_list(int reverse) {

    this->print_heading();

    if (this->size == 0) {
        cout << "No entries." << endl;
        return;
    }

    int i = 0;

    if (!reverse) {
        for (i = 0; i < this->capacity; i++) {
            if (this->rows[i]->id) {
                this->address_print(this->rows[i]);
            }
        }
    } else {
        for (i = this->capacity - 1; i >= 0; i--) {
            if (this->rows[i]->id) {
                this->address_print(this->rows[i]);
            }
        }
    }

}



void Database::database_list_filtered(int reverse) {

    this->print_heading();

    if (this->size == 0) {
        cout << "No entries." << endl;
        return;
    }

    int i = 0;

    if (!reverse) {
        for (i = 0; i < this->capacity; i++) {
            if (this->rows[i]->filter) {
                this->address_print(this->rows[i]);
            }
        }
    } else {
        for (i = this->capacity - 1; i >= 0; i--) {
            if (this->rows[i]->filter) {
                this->address_print(this->rows[i]);
            }
        }
    }

}

void Database::database_delete(int id) {
    for (int i = 0; i < this->capacity; i++) {
        Address *addr = this->rows[i];
        if (addr->id == id) {
            //if (Helpers::choice("Do you really want to delete this entry?")) {
                addr->id = 0;
                this->rows[i] = new Address();
                this->size--;
                cout << "Successfully deleted" << endl;
                return;
            //}
        }
    }
    cout << "No such entry in database" << endl;
}


void Database::perform_action(int action) {
    int field; 
    int type;

    switch(action) {
        case 1: {
            cout << "By which field would you like to filter? (enter a number)" << endl
                 << "(1) Make" << endl
                 << "(2) Model" << endl
                 << "(3) Year" << endl
                 << "(4) Price" << endl;

            while(1) {
                cout << "(Enter a number) > ";
                cin >> field;

                if (field < 1 || field > 4) {
                    cout << "Such option does not exist" << endl;
                    continue;
                }
                break;
            }

            cout << "How would you like to filter?" << endl
                 << "(1) Entry is equal to the given value" << endl
                 << "(2) Entry contains the given value" << endl
                 << "(3) Entry is not equal to the given value" << endl
                 << "(4) Entry does not contain the given value" << endl;

            while(1) {
                cout << "(Enter a number) > ";
                cin >> type;

                if (type < 1 || type > 4) {
                    cout << "Such option does not exist" << endl;
                    continue;
                }
                break;
            }

            cout << "Please enter a value to be filtered by" << endl;

            string value;
            cout << "(Enter a value) > ";
            cin >> value;

            switch(field) {
                case 1:
                    this->filter_by_make(type, value);
                    break;
                case 2:
                    this->filter_by_model(type, value);
                    break;
                case 3:
                    this->filter_by_year(type, value);
                    break;
                case 4:
                    this->filter_by_price(type, value);
                    break;
            }
            this->database_list_filtered(0);
            this->reset_filter();
            break;
        }

        case 2: {
            cout << "By which field would you like to sort? (enter a number)" << endl
                 << "(1) Make" << endl
                 << "(2) Model" << endl
                 << "(3) Year" << endl
                 << "(4) Price" << endl;

            while(1) {
                cout << "(Enter a number) > ";
                cin >> field;

                if (field < 1 || field > 4) {
                    cout << "Such option does not exist" << endl;
                    continue;
                }
                break;
            }

            cout << "How would you like to sort?" << endl
                 << "(1) Ascending order" << endl
                 << "(2) Descending order" << endl;

            while(1) {
                cout << "(Enter a number) > ";
                cin >> type;

                if (type < 1 || type > 2) {
                    cout << "Such option does not exist" << endl;
                    continue;
                }
                break;
            }

            int reverse = (type == 1) ? 0 : 1;

            switch(field) {
                case 1:
                    this->sort_lex_by_make(0, this->size - 1);
                    break;
                case 2:
                    this->sort_lex_by_model(0, this->size - 1);
                    break;
                case 3:
                    this->sort_by_year(0, this->size - 1);
                    break;
                case 4:
                    this->sort_by_price(0, this->size - 1);
                    break;
            }
            this->database_list(reverse);
            break;
        }
    }
}


void Database::reset_filter() {

    for (int i = 0; i < this->size; i++) {
        Address *cur = this->rows[i];
        if (cur) {
            cur->filter = 1;
        }
    }
}

void Database::filter_by_make(int type, const string& value) {

    switch(type) {
        case 1:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarMake() != value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 2:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarMake().find(value) == std::string::npos) {
                        cur->filter = 0;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarMake() == value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 4:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarMake().find(value) != std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
    }
}

void Database::filter_by_model(int type, const string& value) {

    switch(type) {
        case 1:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarModel() != value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 2:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarModel().find(value) == std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 3:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarModel() == value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 4:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->getCarModel().find(value) != std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
    }
}


void Database::filter_by_year(int type, const string& value) {


    switch(type) {
        case 1:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_year = to_string(cur->getCarYear());
                    if (car_year != value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 2:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_year = to_string(cur->getCarYear());
                    if (car_year.find(value) == std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 3:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_year = to_string(cur->getCarYear());
                    if (car_year == value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 4:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_year = to_string(cur->getCarYear());
                    if (car_year.find(value) != std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
    }
}


void Database::filter_by_price(int type, const string& value) {


    switch(type) {
        case 1:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_price = to_string(cur->getCarPrice());
                    if (car_price != value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 2:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_price = to_string(cur->getCarPrice());
                    if (car_price.find(value) == std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 3:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_price = to_string(cur->getCarPrice());
                    if (car_price == value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 4:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    string car_price = to_string(cur->getCarPrice());
                    if (car_price.find(value) != std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
    }
}



void Database::sort_lex_by_make(int first, int last) {

    int i, j;
    Address* temp;

    for (i = first; i < last; ++i)

        for (j = i + 1; j < last + 1; ++j) {

            if (this->rows[i]->getCarMake() > this->rows[j]->getCarMake()) {
                temp = this->rows[i];
                this->rows[i] = this->rows[j];
                this->rows[j] = temp;
            }
        }
}


void Database::sort_lex_by_model(int first, int last) {

    int i, j;
    Address* temp;

    for (i = first; i < last; ++i)

        for (j = i + 1; j < last + 1; ++j) {

            if (this->rows[i]->getCarModel() > this->rows[j]->getCarModel()) {
                temp = this->rows[i];
                this->rows[i] = this->rows[j];
                this->rows[j] = temp;
            }
        }
}

void Database::sort_by_year(int first, int last) {

    Address* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                this->rows[i]->getCarYear() <= this->rows[pivot]->getCarYear() && i < last) {
                i++;
            }
            while (this->rows[j]->getCarYear() > this->rows[pivot]->getCarYear()) {
                j--;
            }
            if (i < j) {
                temp = this->rows[i];
                this->rows[i] = this->rows[j];
                this->rows[j] = temp;
            }
        }

        temp = this->rows[pivot];
        this->rows[pivot] = this->rows[j];
        this->rows[j] = temp;

        sort_by_year(first, j - 1);
        sort_by_year(j + 1, last);
    }
}

void Database::sort_by_price(int first, int last) {

    Address* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                this->rows[i]->getCarPrice() <= this->rows[pivot]->getCarPrice() && i < last) {
                i++;
            }
            while (this->rows[j]->getCarPrice() > this->rows[pivot]->getCarPrice()) {
                j--;
            }
            if (i < j) {
                temp = this->rows[i];
                this->rows[i] = this->rows[j];
                this->rows[j] = temp;
            }
        }

        temp = this->rows[pivot];
        this->rows[pivot] = this->rows[j];
        this->rows[j] = temp;

        sort_by_price(first, j - 1);
        sort_by_price(j + 1, last);
    }
}


void Database::sort_by_id(int first, int last)
{

    Address* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                this->rows[i]->id <= this->rows[pivot]->id && i < last) {
                i++;
            }
            while (this->rows[j]->id > this->rows[pivot]->id) {
                j--;
            }
            if (i < j) {
                temp = this->rows[i];
                this->rows[i] = this->rows[j];
                this->rows[j] = temp;
            }
        }

        temp = this->rows[pivot];
        this->rows[pivot] = this->rows[j];
        this->rows[j] = temp;

        sort_by_id(first, j - 1);
        sort_by_id(j + 1, last);
    }
}


