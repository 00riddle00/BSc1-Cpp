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
#include "address.h"
#include "database.h"
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


int main(int argc, char *argv[]) {

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
    conn->database_load();

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

                Database *db = conn->db;
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

                db->perform_action(action);
                break;
            }
            case 'g': {
                conn->db->database_get(input->getID());
                break;
            }
            case 's':; { // An empty statement before a label
                int no_change = 0;
                int id = input->getID();

				for (int i = 0; i < conn->db->getCapacity(); i++) {
                    if (conn->db->rows[i]->id == id) {
                        cout << "Such entry already exists:" << endl;
                        conn->db->database_get(id);
                        //if (choice("Would you like to change it?")) {
                        if (1) {
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

                //if (choice("Would you like to save?")) {
                    conn->db->database_set(id, addr);
					conn->database_write();
                //}
                delete addr;
                break;
            }
            case 'd': {
                conn->db->database_delete(input->getID());
                conn->database_write();
                break;
            }
            case 'l': {
                conn->db->sort_by_id(0, conn->db->getSize() - 1);
				conn->db->database_list(0);
                break;
            }
            case 'c': {
                if (!conn->db->getSize()) {
                    cout << "Database has no entries. Nothing to clear." << endl;
                    break;
                }
                if (Helpers::choice("Do you really want to clear the entire database?")) {
                    delete conn->db;
                } else {
                    break;
                }
                conn->db = new Database;
                conn->database_write();
                break;
            }
            case 'i': {
                cout << separator << endl;
                cout << info << "\n\n";
                break;
            } 
            case 'o': {
                conn->db->debugTable();
                break;
            }
            case 'q': {
                delete input;
                delete conn->db;
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


