#include <iostream>
#include <iomanip>
#include "car.h"
#include "sorting.h"

#include <vector>
#include <algorithm>

using namespace std;

void Sorting::setField(int field) {
    switch(field) {
        case SortingConstants::MAKE: case SortingConstants::MODEL: case SortingConstants::YEAR: case SortingConstants::PRICE: case SortingConstants::ID:
            this->field = static_cast<SortingConstants::Fields>(field);
            break;
        default:
            throw std::invalid_argument("Please make sure that field value is within bounds");
    }
}

void Sorting::setType(int type) {
    switch(type) {
        case SortingConstants::ASCENDING: case SortingConstants::DESCENDING:
            this->type = static_cast<SortingConstants::Types>(type);
            break;
        default:
            throw std::invalid_argument("Please make sure that type value is within bounds");
    }
}



void Sorting::sort_lex_by_make(vector<Car*>* rows) {

    int i, j;
    Car* temp;

    for (i = this->first; i < this->last; ++i) {

        for (j = i + 1; j < last + 1; ++j) {

            if ((*rows)[i]->getCarMake() > (*rows)[j]->getCarMake()) {
                temp = (*rows)[i];
                (*rows)[i] = (*rows)[j];
                (*rows)[j] = temp;
            }
        }
    }
}


void Sorting::sort_lex_by_model(vector<Car*>* rows) {

    int i, j;
    Car* temp;

    for (i = this->first; i < last; ++i)

        for (j = i + 1; j < last + 1; ++j) {

            if ((*rows)[i]->getCarModel() > (*rows)[j]->getCarModel()) {
                temp = (*rows)[i];
                (*rows)[i] = (*rows)[j];
                (*rows)[j] = temp;
            }
        }
}

void Sorting::sort_by_year(vector<Car*>* rows, int first, int last) {

    Car* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                (*rows)[i]->getCarYear() <= (*rows)[pivot]->getCarYear() && i < last) {
                i++;
            }
            while ((*rows)[j]->getCarYear() > (*rows)[pivot]->getCarYear()) {
                j--;
            }
            if (i < j) {
                temp = (*rows)[i];
                (*rows)[i] = (*rows)[j];
                (*rows)[j] = temp;
            }
        }

        temp = (*rows)[pivot];
        (*rows)[pivot] = (*rows)[j];
        (*rows)[j] = temp;

        sort_by_year(rows, first, j - 1);
        sort_by_year(rows, j + 1, last);
    }
}

void Sorting::sort_by_price(vector<Car*>* rows, int first, int last) {

    Car* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                (*rows)[i]->getCarPrice() <= (*rows)[pivot]->getCarPrice() && i < last) {
                i++;
            }
            while ((*rows)[j]->getCarPrice() > (*rows)[pivot]->getCarPrice()) {
                j--;
            }
            if (i < j) {
                temp = (*rows)[i];
                (*rows)[i] = (*rows)[j];
                (*rows)[j] = temp;
            }
        }

        temp = (*rows)[pivot];
        (*rows)[pivot] = (*rows)[j];
        (*rows)[j] = temp;

        sort_by_price(rows, first, j - 1);
        sort_by_price(rows, j + 1, last);
    }
}


void Sorting::sort_by_id(vector<Car*>* rows, int first, int last)
{

    Car* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                (*rows)[i]->getID() <= (*rows)[pivot]->getID() && i < last) {
                i++;
            }
            while ((*rows)[j]->getID() > (*rows)[pivot]->getID()) {
                j--;
            }
            if (i < j) {
                temp = (*rows)[i];
                (*rows)[i] = (*rows)[j];
                (*rows)[j] = temp;
            }
        }

        temp = (*rows)[pivot];
        (*rows)[pivot] = (*rows)[j];
        (*rows)[j] = temp;

        sort_by_id(rows, first, j - 1);
        sort_by_id(rows, j + 1, last);
    }
}



void Sorting::sort(vector<Car*>* rows) {

    this->first = 0;
    this->last = rows->size() - 1;

    switch(this->field) {
        case SortingConstants::MAKE:
            this->sort_lex_by_make(rows);
            break;
        case SortingConstants::MODEL:
            this->sort_lex_by_model(rows);
            break;
        case SortingConstants::YEAR:
            this->sort_by_year(rows, this->first, this->last);
            break;
        case SortingConstants::PRICE:
            this->sort_by_price(rows, this->first, this->last);
            break;
        case SortingConstants::ID:
            this->sort_by_id(rows, this->first, this->last);
            break;
    }

    if (this->type == SortingConstants::DESCENDING) {
        std::reverse(rows->begin(), rows->end());
    }
}


