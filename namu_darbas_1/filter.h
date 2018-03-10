#ifndef __FILTER_H_
#define __FILTER_H_

#include <string>
#include <vector>

namespace FilterConstants {
	enum Fields { MAKE = 1, MODEL, YEAR, PRICE };
	enum Types { EQUAL = 1, CONTAINS, NOT_EQUAL, DOES_NOT_CONTAIN };
}


class Filter {

    FilterConstants::Fields field;
    FilterConstants::Types type;
    std::string value;

    void filter_by_make(std::vector<Car*>* rows);
    void filter_by_model(std::vector<Car*>* rows);
    void filter_by_year(std::vector<Car*>* rows);
    void filter_by_price(std::vector<Car*>* rows);

    public:
		void setField(int field);
		void setType(int type);
        void setValue(const std::string& value);
        void filter(std::vector<Car*>* rows);
        void reset_filter(std::vector<Car*>* rows);

};

#endif


