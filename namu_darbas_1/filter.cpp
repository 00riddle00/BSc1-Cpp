#include <iostream>
#include <iomanip>
#include "car.h"
#include "filter.h"

#include <vector>

using namespace std;


void Filter::filter_by_make(vector<Car*>* rows) {

    switch(this->type) {
        case FilterConstants::EQUAL:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarMake() != this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case FilterConstants::CONTAINS:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarMake().find(this->value) == std::string::npos) {
                    (*rows)[i]->setFilter(false);
                }
            }
            break;
        case FilterConstants::NOT_EQUAL:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarMake() == this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case FilterConstants::DOES_NOT_CONTAIN:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarMake().find(this->value) != std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
    }
}

void Filter::filter_by_model(vector<Car*>* rows) {

    switch(this->type) {
        case 1:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarModel() != this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 2:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarModel().find(this->value) == std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 3:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarModel() == this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 4:
            for (int i = 0; i < rows->size(); i++) {
                if ((*rows)[i]->getCarModel().find(this->value) != std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
    }
}


void Filter::filter_by_year(vector<Car*>* rows) {

    switch(this->type) {
        case 1:
            for (int i = 0; i < rows->size(); i++) {
                string car_year = to_string((*rows)[i]->getCarYear());
                if (car_year != this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 2:
            for (int i = 0; i < rows->size(); i++) {
                string car_year = to_string((*rows)[i]->getCarYear());
                if (car_year.find(this->value) == std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 3:
            for (int i = 0; i < rows->size(); i++) {
                string car_year = to_string((*rows)[i]->getCarYear());
                if (car_year == this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 4:
            for (int i = 0; i < rows->size(); i++) {
                string car_year = to_string((*rows)[i]->getCarYear());
                if (car_year.find(this->value) != std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
    }
}


void Filter::filter_by_price(vector<Car*>* rows) {

    switch(this->type) {
        case 1:
            for (int i = 0; i < rows->size(); i++) {
                string car_price = to_string((*rows)[i]->getCarPrice());
                if (car_price != this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 2:
            for (int i = 0; i < rows->size(); i++) {
                string car_price = to_string((*rows)[i]->getCarPrice());
                if (car_price.find(this->value) == std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 3:
            for (int i = 0; i < rows->size(); i++) {
                string car_price = to_string((*rows)[i]->getCarPrice());
                if (car_price == this->value) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
        case 4:
            for (int i = 0; i < rows->size(); i++) {
                string car_price = to_string((*rows)[i]->getCarPrice());
                if (car_price.find(this->value) != std::string::npos) {
                    (*rows)[i]->setFilter(false);
                } 
            }
            break;
    }
}



void Filter::setField(int field) {
    switch(field) {
        case FilterConstants::MAKE: case FilterConstants::MODEL: case FilterConstants::YEAR: case FilterConstants::PRICE: 
            this->field = static_cast<FilterConstants::Fields>(field);
            break;
        default:
            throw std::invalid_argument("Please make sure that field value is within bounds");
    }
}

void Filter::setType(int type) {
    switch(type) {
        case FilterConstants::EQUAL: case FilterConstants::CONTAINS: case FilterConstants::NOT_EQUAL: case FilterConstants::DOES_NOT_CONTAIN: 
            this->type = static_cast<FilterConstants::Types>(type);
            break;
        default:
            throw std::invalid_argument("Please make sure that type value is within bounds");
    }
}

void Filter::setValue(const string& value) {
    this->value = value;
}

void Filter::filter(vector<Car*>* rows) {

    switch(this->field) {
        case FilterConstants::MAKE:
            this->filter_by_make(rows);
            break;
        case FilterConstants::MODEL:
            this->filter_by_model(rows);
            break;
        case FilterConstants::YEAR:
            this->filter_by_year(rows);
            break;
        case FilterConstants::PRICE:
            this->filter_by_price(rows);
            break;
    }
}

void Filter::reset_filter(vector<Car*>* rows) {

    for (int i = 0; i < rows->size(); i++) {
        (*rows)[i]->setFilter(true);
    }
}


