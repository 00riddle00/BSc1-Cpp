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
 | updates:       Version 1.5
 |
 +===========================================================================*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

#include "load_from_binary_file.h"
#include "write_to_binary_file.h"
#include "Helpers.h"
#include "input.h"
#include "car.h"
#include "table.h"
#include "connection.h"

#define LOGFILE "log.txt"

using namespace std;



// this function gets called with atexit()
// writes logging info to a log file and 
// displays goodbye message
void exiting();


clock_t start;
clock_t finish;

double clocks;
double time_spent;

static ofstream logfile;



void list_data(Table table, vector<Car*> rows, int reverse = 0, int filtered = 0) {

    table.print_heading();

    if (rows.size() == 0) {
        cout << "No entries." << endl;
        return;
    }

    if (!filtered) {
        if (!reverse) {
            for (int i = 0; i < rows.size(); i++) {
                table.printEntry({
                        to_string(rows[i]->getID()),
                        rows[i]->getCarMake(),
                        rows[i]->getCarModel(),
                        to_string(rows[i]->getCarYear()),
                        to_string(rows[i]->getCarPrice())
                        });
            }
        } else {
            for (int i = rows.size() - 1; i >= 0; i--) {
                table.printEntry({
                        to_string(rows[i]->getID()),
                        rows[i]->getCarMake(),
                        rows[i]->getCarModel(),
                        to_string(rows[i]->getCarYear()),
                        to_string(rows[i]->getCarPrice())
                        });
            }
        }
    } else {
        if (!reverse) {
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getFilter()) {
                    table.printEntry({
                            to_string(rows[i]->getID()),
                            rows[i]->getCarMake(),
                            rows[i]->getCarModel(),
                            to_string(rows[i]->getCarYear()),
                            to_string(rows[i]->getCarPrice())
                            });
                }
            }
        } else {
            for (int i = rows.size() - 1; i >= 0; i--) {
                if (rows[i]->getFilter()) {
                    table.printEntry({
                            to_string(rows[i]->getID()),
                            rows[i]->getCarMake(),
                            rows[i]->getCarModel(),
                            to_string(rows[i]->getCarYear()),
                            to_string(rows[i]->getCarPrice())
                            });
                }
            }
        }
    }
}


void perform_action(Table table, vector<Car*> rows, int action) {
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
            cin.get();

            switch(field) {
                case 1:
                    //this->filter_by_make(type, value);
                    break;
                case 2:
                    //this->filter_by_model(type, value);
                    break;
                case 3:
                    //this->filter_by_year(type, value);
                    break;
                case 4:
                    //this->filter_by_price(type, value);
                    break;
            }
            list_data(table, rows, 0, 1);
            //this->reset_filter();
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
                    //this->sort_lex_by_make(0, this->size - 1);
                    break;
                case 2:
                    //this->sort_lex_by_model(0, this->size - 1);
                    break;
                case 3:
                    //this->sort_by_year(0, this->size - 1);
                    break;
                case 4:
                    //this->sort_by_price(0, this->size - 1);
                    break;
            }
            list_data(table, rows, reverse);
            break;
        }
    }
}





int main(int argc, char *argv[]) {

    Table table({"ID", "Make", "Model", "Year", "Price"}, {4, 30, 30, 10, 10});

    //vector<string> params = {"ID", "Make", "Model", "Year", "Price"};
    //table.setParams(params);

    //vector<int> widths = {4, 30, 40, 10, 10};
    //table.setColumnWidths(widths);

    std::vector<Car*> rows;

    if (argc < 2) {
        cout << "USAGE: test <dbfile> <action> [action params]" << endl;
        exit(1);
    }

    logfile.open(LOGFILE, std::ofstream::out | std::ofstream::app);

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* current_time = ctime(&now);

    logfile << "Starting program @" << current_time;

    start = clock();

    /* register the termination function */
    atexit(exiting);

    Connection* conn = new Connection(argv[1]);
    conn->database_load(&rows);
    //Database* db = conn->database_load();

    string about = "This is a car database program, where one can perform get, list, create, edit and delete "
            "operations. The database is loaded from and saved to the binary file. Version: v.0";

    string info = "Usage: in the main shell, input the Action[1] and ID[2].\n\n[1] Action - g=get, l=list, "
        "s=set, d=delete, c=clear database, q=quit, i=info.\n[2] ID - a positive integer. Only get, "
        "set and delete operations require ID parameter.\nExamples: (1) get 1 (get 1st element) (2) l (list elements) "
        "(3) set 2 (set 2nd element)";

    string separator = "---------------------------------------------------";

    /* initialize input variable*/
    Input* input = new Input;

    cout << about << "\n\n";
    cout << separator << endl;
    cout << info << "\n\n";

    // process input from argv
    if (argc > 2) {
        input->setCMD();
        input->add(argv[2]);

        if (argc > 3) {
            input->add(argv[3]);
        }
        
        if (argc > 4) {
            cout << "Too many arguments" << endl;
            input->clear_input();
        }
    }

    // main control loop
    while (1) {
        cout << separator << endl;
        
        // FIXME what if input is valid?
        // in case of argv input
        if (input->isCMD()) {
            input->unsetCMD();
            if (!input->isValid()) {
                input->clear_input();
                continue;
            }
        // else get input from user
        } else {
            input->clear_input();
            input->get_input();
            if (!input->isValid()) {
                input->clear_input();
                continue;
            }
        }

        switch (input->getAction()) {
            case 'a': {
                cout << "What action would you like to perform? (enter a number)" << endl 
                     << "(1) Filter" << endl
                     << "(2) Sort" << endl;

                int action;

                while(1) {
                    cout << "(Enter a number) > ";
                    cin >> action;

                    if (action < 1 || action > 2) {
                        cout << "Such option does not exist" << endl;
                        continue;
                    }
                    break;
                }

                perform_action(table, rows, action);
                break;
            }
            case 'g':; { // An empty statement before a label
                bool id_set = false;

                for (int i = 0; i < rows.size(); i++) {
                    if (rows[i]->getID() == input->getID()) {
                        rows[i]->print();
                        id_set = true;
                        break;
                    }
                }
                if (!id_set) {
                    cout << "ID is not set" << endl;
                }
                break;
            }
            case 's':; { // An empty statement before a label
                int id = input->getID();
				int index = -1;

                for (int i = 0; i < rows.size(); i++) {
                    if (rows[i]->getID() == id) {
                        cout << "Such entry already exists:" << endl;
                        rows[i]->print();
                        index = i;
                    }
                }

                if (index < 0 || (index >= 0 && Helpers::choice("Would you like to change it?"))) {
                    Car* car = new Car;
                    car->getCar(id);

                    if (Helpers::choice("Would you like to save?")) {
						if (index >= 0) {
							rows[index] = car;
						} else {
							rows.push_back(car);
						}
                        conn->database_write(rows);
						cout << "Successfully saved, ID = " << id << endl;
                    }
                }
                break;
            }
            case 'd': {
                for (int i = 0; i < rows.size(); i++) {
                    if (rows[i]->getID() == input->getID()) {
                        if (Helpers::choice("Do you really want to delete this entry?")) {
                            rows.erase(rows.begin()+i);
                            conn->database_write(rows);
                        }
                        break;
                    }
                }
                break;
            }
            case 'l': {
                list_data(table, rows);
                break;
            }
            case 'c': {
                if (!rows.size()) {
                    cout << "Database has no entries. Nothing to clear." << endl;
                    break;
                }
                if (Helpers::choice("Do you really want to clear the entire database?")) {
                    rows.clear();
                } else {
                    break;
                }
                conn->database_write(rows);
                break;
            }
            case 'i': {
                cout << separator << endl;
                cout << info << "\n\n";
                break;
            } 
            case 'q': {
                delete input;
                delete conn;
                return 0;
            }
            default: {
                cout << "Invalid action, only: g=get, s=set, d=delete, l=list, q=quit, i=info" << endl;
            }
        }

    }
}

void exiting() {
    finish = clock();

    clocks = (double)(finish - start);
    time_spent = clocks / CLOCKS_PER_SEC;
    logfile << "Time spent: " << time_spent << " seconds" << endl
            << string(20, '-') << endl;
    logfile.close();
    cout << "Goodbye!" << endl;
}


