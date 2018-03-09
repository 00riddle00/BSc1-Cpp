#include <iostream>
#include <iomanip>
#include "car.h"
#include "filter.h"

#include <vector>

using namespace std;

void Filter::reset_filter(vector<Car*> rows) {

    for (int i = 0; i < rows.size(); i++) {
        rows[i]->setFilter(true);
    }
}

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

//void Filter::filter_by_model(vector<Car*> rows, int type, const string& value) {

    //switch(type) {
        //case 1:
            //for (int i = 0; i < rows.size(); i++) {
                //if (rows[i]->getCarModel() != value) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 2:
            //for (int i = 0; i < rows.size(); i++) {
                //if (rows[i]->getCarModel().find(value) == std::string::npos) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 3:
            //for (int i = 0; i < rows.size(); i++) {
                //if (rows[i]->getCarModel() == value) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 4:
            //for (int i = 0; i < rows.size(); i++) {
                //if (rows[i]->getCarModel().find(value) != std::string::npos) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
    //}
//}


//void Filter::filter_by_year(vector<Car*> rows, int type, const string& value) {

    //switch(type) {
        //case 1:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_year = to_string(rows[i]->getCarYear());
                //if (car_year != value) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 2:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_year = to_string(rows[i]->getCarYear());
                //if (car_year.find(value) == std::string::npos) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 3:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_year = to_string(rows[i]->getCarYear());
                //if (car_year == value) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 4:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_year = to_string(rows[i]->getCarYear());
                //if (car_year.find(value) != std::string::npos) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
    //}
//}


//void Filter::filter_by_price(vector<Car*> rows, int type, const string& value) {

    //switch(type) {
        //case 1:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_price = to_string(rows[i]->getCarPrice());
                //if (car_price != value) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 2:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_price = to_string(rows[i]->getCarPrice());
                //if (car_price.find(value) == std::string::npos) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 3:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_price = to_string(rows[i]->getCarPrice());
                //if (car_price == value) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
        //case 4:
            //for (int i = 0; i < rows.size(); i++) {
                //string car_price = to_string(rows[i]->getCarPrice());
                //if (car_price.find(value) != std::string::npos) {
                    //rows[i]->setFilter(false);
                //} 
            //}
            //break;
    //}
//}



