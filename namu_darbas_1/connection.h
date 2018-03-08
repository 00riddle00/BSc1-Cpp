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

        Database* database_load();

        void database_write(Database* db);
};

#endif
