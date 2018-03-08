#ifndef __ADDRESS_H_
#define __ADDRESS_H_
#include <string>
#include "connection.h"

const int MAX_ENTRY_SIZE = 30;
const int LATEST_YEAR = 2018;
const int EARLIEST_YEAR = 1920;
const int MAX_PRICE = 1e9;

class Address {
    std::string car_make;
    std::string car_model;
    int car_year;
    int car_price;

    public:
        int id;
        int filter;

        Address();
        ~Address();

        friend void Connection::database_load();

        void setCarMake(const std::string&);
        void setCarModel(const std::string&);
        void setCarYear(int);
        void setCarPrice(int);

        const std::string& getCarMake();
        const std::string& getCarModel();
        int getCarYear();
        int getCarPrice();

        void getAddress();
};

#endif
