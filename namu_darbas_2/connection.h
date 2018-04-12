#ifndef __CONNECTION_H_
#define __CONNECTION_H_

#include <fstream>
#include <vector>

class Car;

class Connection {
    std::ofstream output;
    std::ifstream input;
    std::string filename;

    public:
        explicit Connection(const std::string& filename);
        ~Connection();

        void load_from_file(std::vector<Car*> &cars);

        void write_to_file(std::vector<Car*> &cars);
};

#endif
