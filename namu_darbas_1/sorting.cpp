#include <iostream>
#include <iomanip>
#include "car.h"
#include "sorting.h"

#include <vector>

using namespace std;

void Sorting::setField(int field) {
	this->field = static_cast<Sorting::Fields>(field);
}

void Sorting::setType(int type) {
	this->type = static_cast<Sorting::Types>(type);
}



void Sorting::sort_lex_by_make(vector<Car*>* rows, int first, int last) {

    int i, j;
    Car* temp;

    for (i = first; i < last; ++i) {

        for (j = i + 1; j < last + 1; ++j) {

            if ((*rows)[i]->getCarMake() > (*rows)[j]->getCarMake()) {
                temp = (*rows)[i];
                (*rows)[i] = (*rows)[j];
                (*rows)[j] = temp;
            }
        }
    }
}


void Sorting::sort_lex_by_model(vector<Car*>* rows, int first, int last) {

    int i, j;
    Car* temp;

    for (i = first; i < last; ++i)

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




void Sorting::sort(vector<Car*>* rows, int first, int last) {

    switch(this->field) {
        case MAKE:
            this->sort_lex_by_make(rows, first, last);
            break;
        case MODEL:
            this->sort_lex_by_model(rows, first, last);
            break;
        case YEAR:
            this->sort_by_year(rows, first, last);
            break;
        case PRICE:
            this->sort_by_price(rows, first, last);
            break;
        case ID:
            this->sort_by_id(rows, first, last);
            break;
    }
}


