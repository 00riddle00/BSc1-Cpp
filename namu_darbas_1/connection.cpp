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

void Connection::database_load(vector<Car*>* rows) {

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

        cout << "Size: " << size << endl;

        for (int i = 0; i < size; i++) {

            rows->push_back(
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

void Connection::database_write(vector<Car*> rows) {

    WriteToBinaryFile wb(this->filename);
    int size = rows.size();
    wb.write(size);

    for (int i = 0; i < rows.size(); i++) {
        wb.write(rows[i]->getID());
        wb.write(rows[i]->getFilter());
        wb.write(rows[i]->getCarMake(), MAX_ENTRY_SIZE);
        wb.write(rows[i]->getCarModel(), MAX_ENTRY_SIZE);
        wb.write(rows[i]->getCarYear());
        wb.write(rows[i]->getCarPrice());
    }

    wb.close();
}


