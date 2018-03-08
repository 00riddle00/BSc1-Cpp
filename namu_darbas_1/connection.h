#ifndef __CONNECTION_H_
#define __CONNECTION_H_

#include <fstream>
class Database;

class Connection {
    std::ofstream output;
    std::ifstream input;
    std::string filename;

    public:
        explicit Connection(const std::string& filename);
        ~Connection();

        Database *db;

        // ::return: connection struct
        void database_load();

        // write current state of database to a file
        //
        // ::params: conn - Connection struct
        void database_write();
};

#endif
