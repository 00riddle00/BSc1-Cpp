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



void Sorting::sort_lex_by_make(vector<Car*>* cars) {

    int i, j;
    Car* temp;

    for (i = this->first; i < this->last; ++i) {

        for (j = i + 1; j < last + 1; ++j) {

            if ((*cars)[i]->getCarMake() > (*cars)[j]->getCarMake()) {
                temp = (*cars)[i];
                (*cars)[i] = (*cars)[j];
                (*cars)[j] = temp;
            }
        }
    }
}


void Sorting::sort_lex_by_model(vector<Car*>* cars) {

    int i, j;
    Car* temp;

    for (i = this->first; i < last; ++i)

        for (j = i + 1; j < last + 1; ++j) {

            if ((*cars)[i]->getCarModel() > (*cars)[j]->getCarModel()) {
                temp = (*cars)[i];
                (*cars)[i] = (*cars)[j];
                (*cars)[j] = temp;
            }
        }
}

void Sorting::sort_by_year(vector<Car*>* cars, int first, int last) {

    Car* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                (*cars)[i]->getCarYear() <= (*cars)[pivot]->getCarYear() && i < last) {
                i++;
            }
            while ((*cars)[j]->getCarYear() > (*cars)[pivot]->getCarYear()) {
                j--;
            }
            if (i < j) {
                temp = (*cars)[i];
                (*cars)[i] = (*cars)[j];
                (*cars)[j] = temp;
            }
        }

        temp = (*cars)[pivot];
        (*cars)[pivot] = (*cars)[j];
        (*cars)[j] = temp;

        sort_by_year(cars, first, j - 1);
        sort_by_year(cars, j + 1, last);
    }
}

void Sorting::sort_by_price(vector<Car*>* cars, int first, int last) {

    Car* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                (*cars)[i]->getCarPrice() <= (*cars)[pivot]->getCarPrice() && i < last) {
                i++;
            }
            while ((*cars)[j]->getCarPrice() > (*cars)[pivot]->getCarPrice()) {
                j--;
            }
            if (i < j) {
                temp = (*cars)[i];
                (*cars)[i] = (*cars)[j];
                (*cars)[j] = temp;
            }
        }

        temp = (*cars)[pivot];
        (*cars)[pivot] = (*cars)[j];
        (*cars)[j] = temp;

        sort_by_price(cars, first, j - 1);
        sort_by_price(cars, j + 1, last);
    }
}


void Sorting::sort_by_id(vector<Car*>* cars, int first, int last)
{

    Car* temp;
    int pivot, j, i;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (
                (*cars)[i]->getID() <= (*cars)[pivot]->getID() && i < last) {
                i++;
            }
            while ((*cars)[j]->getID() > (*cars)[pivot]->getID()) {
                j--;
            }
            if (i < j) {
                temp = (*cars)[i];
                (*cars)[i] = (*cars)[j];
                (*cars)[j] = temp;
            }
        }

        temp = (*cars)[pivot];
        (*cars)[pivot] = (*cars)[j];
        (*cars)[j] = temp;

        sort_by_id(cars, first, j - 1);
        sort_by_id(cars, j + 1, last);
    }
}



void Sorting::sort(vector<Car*>* cars) {

    this->first = 0;
    this->last = cars->size() - 1;

    switch(this->field) {
        case SortingConstants::MAKE:
            this->sort_lex_by_make(cars);
            break;
        case SortingConstants::MODEL:
            this->sort_lex_by_model(cars);
            break;
        case SortingConstants::YEAR:
            this->sort_by_year(cars, this->first, this->last);
            break;
        case SortingConstants::PRICE:
            this->sort_by_price(cars, this->first, this->last);
            break;
        case SortingConstants::ID:
            this->sort_by_id(cars, this->first, this->last);
            break;
    }

    if (this->type == SortingConstants::DESCENDING) {
        std::reverse(cars->begin(), cars->end());
    }
}


