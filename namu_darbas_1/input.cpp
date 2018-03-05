#include <iostream>
#include <sstream>
#include "input.h"

using namespace std;

Input::Input() {
    this->count = 0;
    this->valid = 0;
    this->cmd = false;
}

void Input::setParam(int index, const string& param) {
    this->params[index] = param;
    this->count++;
}

void Input::setCMD() {
    this->cmd = true;
}

bool Input::isCMD() {
    return this->cmd;
}

int Input::getCount() {
    return this->count;
}

bool Input::isValid() {
    return this->valid;
}

void Input::get_input() {

    string line;

    while (1) {
        cout << "[enter \"i\" for info] main shell > ";

        getline(cin, line);

        string buf; // Have a buffer string
        stringstream ss(line); // Insert the string into a stream

        while (ss >> buf && this->count <= MAX_PARAMS+1) {
            //tokens.push_back(buf);
            this->params[this->count] = buf;
            this->count++;
        }

        // break if input is valid
        if (this->validate_input()) {
            this->valid = true;
            break;
        // else clear input and repeat
        } else {
            this->clear_input();
        }
    }
}

bool Input::validate_input() {

    // Validate argument count
   
    if (this->count == 0) {
        cout << "The input is empty." << endl;
        return false;
    }

    if (this->count > MAX_PARAMS) {
        cout << "Too many arguments" << endl;
        return false;
    }

    // Validate action
    
    string all_actions = "a,g,s,d,l,c,i,q,action,get,set,delete,list,clear,info,quit";
    
    if (all_actions.find(this->params[0]) == std::string::npos) {
        cout << "Such action does not exist" << endl;
        return false;
    }

    char action = this->params[0][0];

    if (this->count == 1) {
        string actions = "gsd";
        if (actions.find(action) != std::string::npos) {
            cout << "ID is not submitted" << endl;
            return false;
        }
    }

    // Validate id
    
    if (this->count > 1) {

        string one_args = "alicq";

        if (one_args.find(action) != std::string::npos) {
            cout << "Too much arguments for this action" << endl;
            return false;
        }

        int id = stoi(this->params[1]);

        // id being equal to 0 in condition
        // below also validates from char input
        if (id <= 0) {
            cout << "ID should be a positive integer." << endl;
            return false;
        }
    }

    this->valid = true;
    return true;
}


void Input::clear_input() {
    for (int i = 0; i < MAX_PARAMS; ++i) {
        this->params[i] = "";
    }
    this->valid = false;
    this->count = 0;
    this->cmd = false;
}

