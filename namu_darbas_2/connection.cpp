#include <iostream>
#include <fstream>
#include <vector>

#include "load_from_binary_file.h"
#include "write_to_binary_file.h"
#include "car.h"
#include "connection.h"

using namespace std;

Connection::Connection(const string& filename) {
    this->filename = filename;
}

Connection::~Connection() {
    if (this->input.is_open()) {
        this->input.close();
    }

    if (this->output.is_open()) {
        this->output.close();
    }
}

void Connection::load_from_file(vector<Car*> &cars) {

    this->input.open(this->filename, ios::in | ios::binary);

    this->input.seekg(0, std::ios::end);
    if (this->input.tellg() == 0)
    {
        std::cout << "File is empty" << std::endl;
        return;
    }

    LoadFromBinaryFile lb(this->filename);

    if(this->input.good()) {

        int size = lb.readInt();

        for (int i = 0; i < size; i++) {

            cars.push_back(
                new Car(
                    lb.readInt(),
                    lb.readInt(), 
                    lb.readString(MAX_ENTRY_SIZE), 
                    lb.readString(MAX_ENTRY_SIZE),
                    lb.readInt(),
                    lb.readInt()
                )
            );

        }

        lb.close();
    } 
}

void Connection::write_to_file(vector<Car*> &cars) {

    WriteToBinaryFile wb(this->filename);
    int size = cars.size();
    wb.write(size);

    for (size_t i = 0; i < cars.size(); i++) {
        wb.write(cars[i]->getID());
        wb.write(cars[i]->getFilter());
        wb.write(cars[i]->getCarMake(), MAX_ENTRY_SIZE);
        wb.write(cars[i]->getCarModel(), MAX_ENTRY_SIZE);
        wb.write(cars[i]->getCarYear());
        wb.write(cars[i]->getCarPrice());
    }

    wb.close();
}


