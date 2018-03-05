#ifndef __ADDRESS_H_
#define __ADDRESS_H_

#define MAX_ENTRY_SIZE 30
#define LATEST_YEAR 2018
#define EARLIEST_YEAR 1920
#define MAX_PRICE 1e9

class Address {
    std::string car_make;
    std::string car_model;
    int car_year;
    int car_price;

    public:
        int id;
        int filter;

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
