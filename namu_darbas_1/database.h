#ifndef __DATABASE_H_
#define __DATABASE_H_

const int CHUNK_SIZE = 2;

#include "car.h"
#include "connection.h"

#include <vector>


class Database {
    int size;
    int capacity;

    public: 
        std::vector<Car*> rows;

        Database();
        Database(int size, int capacity);
        ~Database();

        void setSize(int);
        void setCapacity(int);

        int getSize();
        int getCapacity();

        // print the heading of the table
        void print_heading();

        // print address from database
        //
        // ::params: addr - Address
        void car_print(Car *car);

        // function for debugging
        // print the table including empty spaces
        //
        // ::params: conn - Connection structure
        void debugTable();

        //friend void Connection::database_open();

        // set Address struct in database
        //
        // ::params: db - Database
        // ::params: id - entry id (user input)
        // ::params: car - car struct
        void database_set(int id, Car *car);

        // get address from database
        //
        // ::params: conn - connection struct
        // ::params: id - entry id (user input)
        void database_get(int id);

        // get address from database
        //
        // ::params: db - Database
        // ::params: reverse - whether to print in 
        // reverse order (used in sorting)
        void database_list(int reverse = 0, int filtered = 0);

        // delete address from database
        //
        // ::params: conn - Connection struct
        // ::params: id - entry id (user input)
        void database_delete(int id);

        // perform action on a database
        // (filtering or sorting)
        //
        // ::params: action - Number, indicating the type of action
        // ::params: db - Database
        void perform_action(int action);


        // functions to filter database in a given manner

        // reset filter
        void reset_filter();

        // filter by car make
        void filter_by_make(int type, const std::string& value);

        // filter by car model
        void filter_by_model(int type, const std::string& value);

        // filter by car year
        void filter_by_year(int type, const std::string& value);

        // filter by car price
        void filter_by_price(int type, const std::string& value);


        // functions to sort database in a given manner

        // sort numerically by entry id
        void sort_by_id(int first, int last);

        // sort lexicographically by car make
        void sort_lex_by_make(int first, int last);

        // sort lexicographically by car model
        void sort_lex_by_model(int first, int last);

        // sort numerically by car year
        void sort_by_year(int first, int last);

        // sort numerically by car price
        void sort_by_price(int first, int last);
}; 

#endif
