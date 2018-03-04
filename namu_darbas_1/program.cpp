/*==============================================================================
 |
 |  Assignment:  Homework #1
 |
 |       Author:  Tomas Giedraitis
 |  Study group:  VU MIF INFO1, 1st group
 |     Contacts:  tomasgiedraitis@gmail.com
 |        Class:  Programming Basics
 |         Date:  March 8th, 2018
 |
 |     Language:  C++ (using gcc on Lenovo Y50-70, OS: Arch Linux x86_64)
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  A car database program, where one can perform get, list, 
 |                create, edit, delete and clear operations. There are four fields
 | 				  for each car entry: (1) Make (2) Model (3) Year (4) Price. The 
 | 			      database is loaded from and saved to the binary file. The user
 | 				  can also perform sorting (ascending, descending) actions by each
 | 			      of the four fields, and also filtering by each field. There are 
 | 			      four filtering options: (1) Value is equal (2) Value contains 
 | 				  (3) Value is not equal (4) Value does not contain. After sorting
 | 			      or filtering, the changed database output is displayed to the 
 | 			      screen. Each time the program runs, the log entry is created in 
 |                ./log.txt file, with the info about the beginning of the program 
 |                 and how much time did it run.
 |
 |  Constraints:  
 |                
 |	    Input:    Command line input by user
 |
 |	    Output:   Prompt messages, validation errors and final results
 |                are displayed one per line to the standard output.
 |
 |  Known bugs:   
 |                
 |       TODOS:   (1) Add unit tests
 |
 | Version
 | updates:       Version 1.3
 |
 +===========================================================================*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "dbg.h"
#include "helpers.h"
#include "load_from_binary_file.h"
#include "write_to_binary_file.h"

#define MAX_ENTRY_SIZE 30
#define MAX_LINE 100
#define MAX_TEXT_LENGTH 30
#define MAX_PARAMS 2
#define LATEST_YEAR 2018
#define EARLIEST_YEAR 1920
#define MAX_PRICE 1e9
#define CHUNK_SIZE 2
#define LOGFILE "log.txt"

using namespace std;


class Input {
    public:
        int count;
        int valid;

        // add additional space for one extra parameter in
        // order for the validation to work
        // (ie error "too many parameters" is displayed)
        // TODO revise this logic
        string params[MAX_PARAMS + 1];
        //char** params;

        // ::params: input - input structure is modified
        void get_input();

        // ::params: input - input structure 
        // ::return: 1 if input is valid, else 0
        int valid_input();

        // set input value and input count to 0, nullify pointers 
        // inside input->params
        //
        // ::params: input - input structure is modified
        void clear_input();
};


void Input::get_input() {

    //char line[MAX_LINE];
    string line;

    while (1) {
        printf("[enter \"i\" for info] main shell > ");

        // FIXME choose smaller read size
        //cin.getline(line, MAX_LINE);
        getline(cin, line);

        string buf; // Have a buffer string
        stringstream ss(line); // Insert the string into a stream

        while (ss >> buf && this->count <= MAX_PARAMS+1) {
            //tokens.push_back(buf);
            this->params[this->count] = buf;
            this->count++;
        }

        // break if input is valid
        if (this->valid_input()) {
            this->valid = 1;
            break;
        // else clear input and repeat
        } else {
            this->clear_input();
        }
    }
}

int Input::valid_input() {

    // Validate argument count
   
    int count = this->count;

    if (count == 0) {
        printf("The input is empty.\n");
        return 0;
    }

    if (count > MAX_PARAMS) {
        printf("Too many arguments\n");
        return 0;
    }


    // Validate action
    
    //char *all_actions = (char*)"a,g,s,d,l,c,i,q,action,get,set,delete,list,clear,info,quit";
    // FIXME Define as constant
    string all_actions = "a,g,s,d,l,c,i,q,action,get,set,delete,list,clear,info,quit";
    
    // FIXME is it right
    if (all_actions.find(this->params[0]) == std::string::npos) {
    //if (strstr(all_actions, this->params[0]) == NULL) {
        printf("Such action does not exist\n");
        return 0;
    }


    char action = this->params[0][0];

    if (count == 1) {
        char *actions = (char*)"gsd";
        if (strchr(actions, action) != NULL) {
            printf("ID is not submitted\n");
            return 0;
        }
    }

    // Validate id
    
    if (count > 1) {

        char *one_args = (char*)"alicq";
        if (strchr(one_args, action) != NULL) {
            printf("Too much arguments for this action\n");
            return 0;
        }

        int id = stoi(this->params[1]);

        // id being equal to 0 in condition
        // below also validates from char input
        if (id <= 0) {
            printf("ID should be a positive integer.\n");
            return 0;
        }
    }

    return 1;
}


void Input::clear_input() {
    for (int i = 0; i < MAX_PARAMS; ++i) {
        //this->params[i] = NULL;
        // FIXME more effective free
        this->params[i] = "";
    }
    this->valid = 0;
    this->count = 0;
}

class Address {
    public:
        int id;
        int filter;
        //char car_make[MAX_TEXT_LENGTH];
        //char car_model[MAX_TEXT_LENGTH];
        string car_make;
        string car_model;
        int car_year;
        int car_price;

        void setCarMake(const string& car_make);
        void setCarModel(const string& car_model);
        void setCarYear(int car_year);
        void setCarPrice(int car_price);

        void getAddress();
};


void Address::setCarMake(const string& car_make) {

    if (std::string::npos != car_make.find_first_of("0123456789")) {
        throw std::invalid_argument("Car make cannot contain numbers!");
    }
    if (car_make.length() > MAX_ENTRY_SIZE) {
        throw std::invalid_argument("Database entry cannot contain more than 30 characters!");
    }
    this->car_make = car_make;
};

void Address::setCarModel(const string& car_model) {
    if (car_model.length() > MAX_ENTRY_SIZE) {
        throw std::invalid_argument("Database entry cannot contain more than 30 characters!");
    }
    this->car_model = car_model;
};


void Address::setCarYear(int car_year) {
    if (car_year < EARLIEST_YEAR || car_year > LATEST_YEAR) {
        throw std::invalid_argument("Please make sure that year is in normal format");
    }

    this->car_year = car_year;
};

void Address::setCarPrice(int car_price) {
    if (car_price <= 0) {
        throw std::invalid_argument("Price cannot be zero or negative!");
    }
    if (car_price > MAX_PRICE) {
        throw std::invalid_argument("Price has outgone its upper limit!");
    }

    this->car_price = car_price;
};


void Address::getAddress() {

    while (1) {

        cout << "Enter make > ";
        string car_make;
        cin >> car_make;
        try {
            this->setCarMake(car_make);
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
            continue;
        }
        // flush input
        // FIXME is it the right way to do it?
        cin.get();
        break;
    }

    while (1) {

        cout << "Enter model > ";
        string car_model;
        getline(cin, car_model);
        try {
            this->setCarModel(car_model);
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
            continue;
        }
        // flush input
        // FIXME is it the right way to do it?
        cin.get();
        break;
    }

    while(1) {
        cout << "Enter year > ";
        int car_year;
        cin >> car_year;

        try {
            this->setCarYear(car_year);
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }

    while(1) {
        cout << "Enter price > ";
        int car_price;
        cin >> car_price;

        try {
            this->setCarPrice(car_price);
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
};


class Database {
    public: 
        //Address** rows;
        vector<Address*> rows;
        int size;
        int capacity;

        // print the heading of the table
        void print_heading();

        // print address from database
        //
        // ::params: addr - Address
        void address_print(Address *addr);

        // function for debugging
        // print the table including empty spaces
        //
        // ::params: conn - Connection structure
        void debugTable();

        // set Address struct in database
        //
        // ::params: db - Database
        // ::params: id - entry id (user input)
        // ::params: car - car struct
        void database_set(int id, Address *address);

        // get address from database
        //
        // ::params: conn - connection struct
        // ::params: id - entry id (user input)
        void database_get(int id);

        // get address from database
        //
        // ::params: db - Database
        // ::params: reverse - whether to print in 
        // reverse order (used in sorting)
        void database_list(int reverse);

        // get entries from database, if they pass the filter
        // (check if address->filter is true)
        //
        // ::params: db - Database
        // ::params: reverse - whether to print in 
        // reverse order (used in sorting)
        void database_list_filtered(int reverse);

        // delete address from database
        //
        // ::params: conn - Connection struct
        // ::params: id - entry id (user input)
        void database_delete(int id);

        // clear database
        // 
        // ::params: conn - Connection struct
        void database_clear();

        // perform action on a database
        // (filtering or sorting)
        //
        // ::params: action - Number, indicating the type of action
        // ::params: db - Database
        void perform_action(int action);


        // functions to filter database in a given manner

        // reset filter
        void reset_filter();

        // filter by car make
        void filter_by_make(int type, const string& value);

        // filter by car model
        void filter_by_model(int type, const string& value);

        // filter by car year
        void filter_by_year(int type, const string& value);

        // filter by car price
        void filter_by_price(int type, const string& value);


        // functions to sort database in a given manner

        // sort numerically by entry id
        void sort_by_id(int first, int last);

        // sort lexicographically by car make
        void sort_lex_by_make(int first, int last);

        // sort lexicographically by car model
        void sort_lex_by_model(int first, int last);

        // sort numerically by car year
        void sort_by_year(int first, int last);

        // sort numerically by car price
        void sort_by_price(int first, int last);
}; 


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
         << setw(30) << addr->car_make << "|"
         << setw(30) << addr->car_model << "|"
         << setw(10) << addr->car_year << "|"
         << setw(10) << addr->car_price << "|"
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

    debug("db size: %d", this->size);
    debug("db capacity: %d", this->capacity);

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
   
    // FIXME is it needed with vector?
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

    printf("Successfully saved, ID = %d\n", id);
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
    printf("ID is not set\n");
}


void Database::database_list(int reverse) {

    this->print_heading();

    if (this->size == 0) {
        printf("No entries.\n");
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
        printf("No entries.\n");
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
            if (choice("Do you really want to delete this entry?")) {
                addr->id = 0;
                this->rows[i] = new Address();
                this->size--;
                printf("Successfully deleted\n");
                return;
            }
        }
    }
    printf("No such entry in database\n");
}


void Database::database_clear() {

    if (!this->size) {
        printf("Database has no entries. Nothing to clear.\n");
        return;
    }

    if (choice("Do you really want to clear the entire database?")) {

        this->size = 0;

        for (int i = 0; i < this->capacity; i++) {
            delete this->rows[i];
        }
        printf("Database has been successfully cleared.\n");

    }
}

void Database::perform_action(int action) {
    int field; 
    int type;

    switch(action) {
        case 1: {
            printf("By which field would you like to filter? (enter a number)\n");
            printf("(1) Make\n");
            printf("(2) Model\n");
            printf("(3) Year\n");
            printf("(4) Price\n");

            field = get_num_interval((char*)"(Enter a number) > ", (char*)"Such option does not exist", 1, 4);

            printf("How would you like to filter?\n");
            printf("(1) Entry is equal to the given value\n");
            printf("(2) Entry contains the given value\n");
            printf("(3) Entry is not equal to the given value\n");
            printf("(4) Entry does not contain the given value\n");

            type = get_num_interval((char*)"(Enter a number) > ", (char*)"Such option does not exist", 1, 4);

            printf("Please enter a value to be filtered by\n");

            string value;
            // TODO add validation as in "get text" function
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
            printf("By which field would you like to sort? (enter a number)\n");
            printf("(1) Make\n");
            printf("(2) Model\n");
            printf("(3) Year\n");
            printf("(4) Price\n");

            field = get_num_interval((char*)"(Enter a number) > ", (char*)"Such option does not exist", 1, 4);

            printf("How would you like to sort?\n");
            printf("(1) Ascending order\n");
            printf("(2) Descending order\n");

            type = get_num_interval((char*)"(Enter a number) > ", (char*)"Such option does not exist", 1, 2);

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
                    if (cur->car_make != value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 2:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->car_make.find(value) == std::string::npos) {
                        cur->filter = 0;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->car_make == value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 4:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->car_make.find(value) != std::string::npos) {
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
                    if (cur->car_model != value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 2:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->car_model.find(value) == std::string::npos) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 3:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->car_model == value) {
                        cur->filter = 0;
                    } 
                }
            }
            break;
        case 4:
            for (int i = 0; i < this->size; i++) {
                Address *cur = this->rows[i];
                if (cur) {
                    if (cur->car_model.find(value) != std::string::npos) {
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
                    string car_year = to_string(cur->car_year);
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
                    string car_year = to_string(cur->car_year);
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
                    string car_year = to_string(cur->car_year);
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
                    string car_year = to_string(cur->car_year);
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
                    string car_price = to_string(cur->car_price);
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
                    string car_price = to_string(cur->car_price);
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
                    string car_price = to_string(cur->car_price);
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
                    string car_price = to_string(cur->car_price);
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

            if (this->rows[i]->car_make > this->rows[j]->car_make) {
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

            if (this->rows[i]->car_model > this->rows[j]->car_model) {
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
                this->rows[i]->car_year <= this->rows[pivot]->car_year && i < last) {
                i++;
            }
            while (this->rows[j]->car_year > this->rows[pivot]->car_year) {
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
                this->rows[i]->car_price <= this->rows[pivot]->car_price && i < last) {
                i++;
            }
            while (this->rows[j]->car_price > this->rows[pivot]->car_price) {
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



class Connection {
    public:
        std::ofstream output;
        std::ifstream input;
        string filename;
        //FILE *file;
        Database *db;

        // ::return: connection struct
        void database_open();

        // create database
        // allocate memory for address rows, 
        // set size and capacity of the database
        //
        // ::params: conn - Connection struct
        void database_create();

        // write current state of database to a file
        //
        // ::params: conn - Connection struct
        void database_write();

        // close connection to a file, and free
        // database (conn->db) as well as connection (conn) structs
        // 
        // ::params: conn - Connection struct
        void database_close();
};



void Connection::database_open() {

    this->db = new Database;

    this->input.open(this->filename, ios::in | ios::binary);


    this->input.seekg(0, std::ios::end);
    if (this->input.tellg() == 0)
    {
        std::cout << "File is empty" << std::endl;
        this->database_create();
        this->database_write();
        this->input.close();
        return;
    }

    LoadFromBinaryFile lb(this->filename);

    if(this->input.good()) {
        this->db->size = lb.readInt();
        this->db->capacity = lb.readInt();

        //this->db->rows = new Address*[this->db->capacity];

        for (int i = 0; i < this->db->capacity; i++) {
            this->db->rows.push_back(new Address());
        }

        for (int i = 0; i < this->db->capacity; i++) {

            this->db->rows[i]->id = lb.readInt();
            this->db->rows[i]->filter = lb.readInt();

            this->db->rows[i]->car_make = lb.readString(MAX_TEXT_LENGTH);

            this->db->rows[i]->car_model = lb.readString(MAX_TEXT_LENGTH);

            this->db->rows[i]->car_year = lb.readInt();
            this->db->rows[i]->car_price = lb.readInt();

        }

        lb.close();
    } 
}





void Connection::database_create() {

    this->db->capacity = CHUNK_SIZE;
    this->db->size = 0;
    debug("create");

    //this->db->rows = new Address*[this->db->capacity];

    for (int i = 0; i < this->db->capacity; i++) {
        //this->db->rows[i] = new Address();
        this->db->rows.push_back(new Address());
    }
}

void Connection::database_write() {

    WriteToBinaryFile wb(this->filename);
    wb.write(this->db->size);
    wb.write(this->db->capacity);

    for (int i = 0; i < this->db->capacity; i++) {
        wb.write(this->db->rows[i]->id);
        wb.write(this->db->rows[i]->filter);
        wb.write(this->db->rows[i]->car_make, MAX_TEXT_LENGTH);
        wb.write(this->db->rows[i]->car_model, MAX_TEXT_LENGTH);
        wb.write(this->db->rows[i]->car_year);
        wb.write(this->db->rows[i]->car_price);
    }

    wb.close();
}


void Connection::database_close() {
    //if (this->file) fclose(this->file);

    for (int i = 0; i < this->db->capacity; i++) {
        free(this->db->rows[i]);
    }
    // TODO free connection
    //free(conn->db->rows);
    //free(conn->db);
    //free(conn);
}



// this function gets called with atexit()
// writes logging info to a log file and 
// displays goodbye message
void exiting();




clock_t start;
clock_t finish;

double clocks;
double time_spent;

static FILE* logfile;


int main(int argc, char *argv[]) {

    if (argc < 2) die ((char*)"USAGE: test <dbfile> <action> [action params]");

    logfile = fopen(LOGFILE, "ab+");

    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    fprintf(logfile, "Starting program @%s", c_time_string);
    start = clock();

    /* register the termination function */
    atexit(exiting);

    Connection* conn = new Connection;
    conn->filename = argv[1];
    conn->database_open();

    char* about = (char*)"This is a car database program, where one can perform get, list, create, edit and delete "
            "operations. The database is loaded from and saved to the binary file. Version: v.0";

    char* info = (char*)"Usage: in the main shell, input the Action[1] and ID[2].\n\n[1] Action - g=get, l=list, "
        "s=set, d=delete, c=clear database, q=quit, i=info.\n[2] ID - a positive integer. Only get, "
        "set and delete operations require ID parameter.\nExamples: (1) get 1 (get 1st element) (2) l (list elements) "
        "(3) set 2 (set 2nd element)";

    char* separator = (char*)"---------------------------------------------------";

    // shows whether the were command line arguments to a program
    int cmd = 0;

    // id for database entries
    int id;

    /* initialize input variable*/
    //Input* input = (Input*) malloc(sizeof(Input));
    Input* input = new Input;
    //input->params = (char**)malloc(MAX_PARAMS * sizeof(char *));
    input->count = 0;
    input->valid = 0;

    // print info about the program
    printf("%s\n\n", about);
    printf("%s\n", separator);
    printf("%s\n\n", info);

    // process input from argv
    if (argc > 2) {
        cmd = 1;
        input->params[0] = argv[2];
        input->count++;

        if (argc > 3) {
            input->params[1] = argv[3];
            input->count++;
        }
        
        if (argc > 4) {
            printf("Too many arguments\n");
            cmd = 0;
        }
    }

    // main control loop
    while (1) {
        printf("%s\n", separator);

        // in case of argv input
        if (cmd) {
            cmd = 0;
            if (!input->valid_input()) {
                input->clear_input();
                continue;
            }
        // else get input from user
        } else {
            input->clear_input();
            input->get_input();
        }

        // setting action from input
        char action = (input->params)[0][0];

        // setting id from input
        if (input->params[1] != "") {
            //id = atoi(input->params[1]);
            id = stoi(input->params[1]);
        }

        // TODO free input
        //free(input->params);
        //free(input);

        switch (action) {
            case 'a': {
                printf("What action would you like to perform? (enter a number)\n");
                printf("(1) Filter\n");
                printf("(2) Sort\n");

                Database *db = conn->db;
                action = get_num_interval((char*)"(Enter a number) > ", (char*)"Such option does not exist", 1, 2);
                db->perform_action(action);
                break;
            }
            case 'g': {
                conn->db->database_get(id);
                break;
            }
            case 's':; { // An empty statement before a label
                int no_change = 0;

				for (int i = 0; i < conn->db->capacity; i++) {
                    if (conn->db->rows[i]->id == id) {
                        printf("Such entry already exists:\n");
                        conn->db->database_get(id);
                        if (choice("Would you like to change it?")) {
                            conn->db->database_delete(id);
                            conn->database_write();
                        } else {
                            no_change = 1;
                            break;
                        }
                    }
                }
                if (no_change)
                    break;

                //Car *car = (Car*) malloc(sizeof(Car));
                //if (car == NULL) die((char*)"Memory error");
                //
                Address* addr = new Address;
                addr->getAddress();

                if (choice("Would you like to save?")) {
                    conn->db->database_set(id, addr);
					conn->database_write();
                }
                // TODO free car
/*                free(car->make);*/
                //free(car->model);
                //free(car);
                break;
            }
            case 'd': {
                conn->db->database_delete(id);
                conn->database_write();
                break;
            }
            case 'l': {
                conn->db->sort_by_id(0, conn->db->size - 1);
				conn->db->database_list(0);
                break;
            }
            case 'c': {
                conn->db->database_clear();
                // FIXME moved out from a clear function
                conn->database_create();
                conn->database_write();
                break;
            }
            case 'i': {
                printf("\n%s\n", separator);
                printf("%s\n\n", info);
                // TODO rm debug printing
                conn->db->debugTable();
                break;
            }
            case 'q': {
                //conn->database_close();
                return 0;
            }
            default: {
                printf("Invalid action, only: g=get, s=set, d=delete, l=list, q=quit, i=info\n");
            }
        }

    }
}

void exiting() {
    finish = clock();

    clocks = (double)(finish - start);
    time_spent = clocks / CLOCKS_PER_SEC;
    fprintf(logfile, "Time spent: %lf seconds\n", time_spent);
    fputs("-----------------------\n", logfile);
    fclose(logfile);
    printf("Goodbye!\n");
}


