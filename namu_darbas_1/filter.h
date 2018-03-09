#ifndef __FILTER_H_
#define __FILTER_H_

#include <string>
#include <vector>

class Filter {

    public:
        void reset_filter(std::vector<Car*> rows);
        void filter_by_make(std::vector<Car*> rows, int type, const std::string& value);
        void filter_by_model(std::vector<Car*> rows, int type, const std::string& value);
        void filter_by_year(std::vector<Car*> rows, int type, const std::string& value);
        void filter_by_price(std::vector<Car*> rows, int type, const std::string& value);
};

#endif


