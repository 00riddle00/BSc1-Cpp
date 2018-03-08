#ifndef __CAR_H_
#define __CAR_H_

#include <string>
#include "connection.h"

const int MAX_ENTRY_SIZE = 30;
const int LATEST_YEAR = 2018;
const int EARLIEST_YEAR = 1920;
const int MAX_PRICE = 1e9;

class Car {
    int id;
    bool filter;
    std::string car_make;
    std::string car_model;
    int car_year;
    int car_price;

    public:
        Car();
        Car(int id, bool filter, const std::string& car_make, const std::string& car_model, int car_year, int car_price);
        ~Car();

        friend void Connection::database_load();

        void setID(int);
        void setFilter(bool);
        void setCarMake(const std::string&);
        void setCarModel(const std::string&);
        void setCarYear(int);
        void setCarPrice(int);

        int getID();
        bool getFilter();
        const std::string& getCarMake();
        const std::string& getCarModel();
        int getCarYear();
        int getCarPrice();

        void getCar(int id);
};

#endif
