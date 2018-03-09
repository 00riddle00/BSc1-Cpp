#include <iostream>
#include <iomanip>
#include "car.h"
#include "filter.h"

#include <vector>

using namespace std;


void Filter::filter_by_make(vector<Car*> rows) {

    switch(this->type) {
        case EQUAL:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarMake() != this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case CONTAINS:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarMake().find(this->value) == std::string::npos) {
                    rows[i]->setFilter(false);
                }
            }
            break;
        case NOT_EQUAL:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarMake() == this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case DOES_NOT_CONTAIN:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarMake().find(this->value) != std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
    }
}

void Filter::filter_by_model(vector<Car*> rows) {

    switch(this->type) {
        case 1:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarModel() != this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 2:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarModel().find(this->value) == std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 3:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarModel() == this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 4:
            for (int i = 0; i < rows.size(); i++) {
                if (rows[i]->getCarModel().find(this->value) != std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
    }
}


void Filter::filter_by_year(vector<Car*> rows) {

    switch(this->type) {
        case 1:
            for (int i = 0; i < rows.size(); i++) {
                string car_year = to_string(rows[i]->getCarYear());
                if (car_year != this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 2:
            for (int i = 0; i < rows.size(); i++) {
                string car_year = to_string(rows[i]->getCarYear());
                if (car_year.find(this->value) == std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 3:
            for (int i = 0; i < rows.size(); i++) {
                string car_year = to_string(rows[i]->getCarYear());
                if (car_year == this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 4:
            for (int i = 0; i < rows.size(); i++) {
                string car_year = to_string(rows[i]->getCarYear());
                if (car_year.find(this->value) != std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
    }
}


void Filter::filter_by_price(vector<Car*> rows) {

    switch(this->type) {
        case 1:
            for (int i = 0; i < rows.size(); i++) {
                string car_price = to_string(rows[i]->getCarPrice());
                if (car_price != this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 2:
            for (int i = 0; i < rows.size(); i++) {
                string car_price = to_string(rows[i]->getCarPrice());
                if (car_price.find(this->value) == std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 3:
            for (int i = 0; i < rows.size(); i++) {
                string car_price = to_string(rows[i]->getCarPrice());
                if (car_price == this->value) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
        case 4:
            for (int i = 0; i < rows.size(); i++) {
                string car_price = to_string(rows[i]->getCarPrice());
                if (car_price.find(this->value) != std::string::npos) {
                    rows[i]->setFilter(false);
                } 
            }
            break;
    }
}



void Filter::setField(int field) {
	this->field = static_cast<Filter::Fields>(field);
}

void Filter::setType(int type) {
	this->type = static_cast<Filter::Types>(type);
}

void Filter::setValue(const string& value) {
    this->value = value;
}

void Filter::filter(vector<Car*> rows) {

    switch(this->field) {
        case MAKE:
            this->filter_by_make(rows);
            break;
        case MODEL:
            this->filter_by_model(rows);
            break;
        case YEAR:
            this->filter_by_year(rows);
            break;
        case PRICE:
            this->filter_by_price(rows);
            break;
    }
}

void Filter::reset_filter(vector<Car*> rows) {

    for (int i = 0; i < rows.size(); i++) {
        rows[i]->setFilter(true);
    }
}


