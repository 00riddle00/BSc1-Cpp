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

        // write current state of database to a file
        //
        // ::params: conn - Connection struct
        void database_write();
};

#endif
