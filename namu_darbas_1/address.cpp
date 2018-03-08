#include <iostream>
#include "address.h"

using namespace std;

Address::Address() {
    this->car_make = "";
    this->car_model = "";
    this->car_year = 0;
    this->car_price = 0;
}

Address::~Address() {} 

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

const string& Address::getCarMake() {
    return this->car_make;
}

const string& Address::getCarModel() {
    return this->car_model;
};


int Address::getCarYear() {
    return this->car_year;
};

int Address::getCarPrice() {
    return this->car_price;
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
        // FIXME is this the way
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
    // FIXME is this the way
    cin.get();
};


