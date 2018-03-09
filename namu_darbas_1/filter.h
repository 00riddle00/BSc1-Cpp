#ifndef __FILTER_H_
#define __FILTER_H_

#include <string>
#include <vector>


class Filter {
    public:
        enum Types { EQUAL = 1, CONTAINS, NOT_EQUAL, DOES_NOT_CONTAIN };
        enum Fields { MAKE = 1, MODEL, YEAR, PRICE };

        Types type;
        Fields field;
        std::string value;
        void reset_filter(std::vector<Car*> rows);
        void filter_by_make(std::vector<Car*> rows);
        //void filter_by_model(std::vector<Car*> rows);
        //void filter_by_year(std::vector<Car*> rows);
        //void filter_by_price(std::vector<Car*> rows);
};

#endif


