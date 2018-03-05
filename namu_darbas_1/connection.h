#ifndef __CONNECTION_H_
#define __CONNECTION_H_

#include "database.h"

class Connection {
    public:
        std::ofstream output;
        std::ifstream input;
        std::string filename;
        //FILE *file;
        Database *db;

        // ::return: connection struct
        void database_open();

        // create database
        // allocate memory for address rows, 
        // set size and capacity of the database
        //
        // ::params: conn - Connection struct
        void database_create();

        // write current state of database to a file
        //
        // ::params: conn - Connection struct
        void database_write();

        // close connection to a file, and free
        // database (conn->db) as well as connection (conn) structs
        // 
        // ::params: conn - Connection struct
        void database_close();
};

#endif
