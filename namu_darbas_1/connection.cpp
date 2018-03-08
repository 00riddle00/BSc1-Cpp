#include <iostream>
#include <fstream>
#include <vector>

#include "load_from_binary_file.h"
#include "write_to_binary_file.h"
#include "connection.h"
#include "database.h"

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

Database* Connection::database_load() {

    Database* db;

    this->input.open(this->filename, ios::in | ios::binary);

    this->input.seekg(0, std::ios::end);
    if (this->input.tellg() == 0)
    {
        std::cout << "File is empty" << std::endl;
        db = new Database;
        this->database_write(db);
        this->input.close();
        return db;
    }

    LoadFromBinaryFile lb(this->filename);

    if(this->input.good()) {
        db = new Database(lb.readInt(), lb.readInt());

        for (int i = 0; i < db->getCapacity(); i++) {

            db->rows[i] = new Car(
                    lb.readInt(),
                    lb.readInt(), 
                    lb.readString(MAX_ENTRY_SIZE), 
                    lb.readString(MAX_ENTRY_SIZE),
                    lb.readInt(),
                    lb.readInt()
            );
        }

        lb.close();
    } 
    return db;
}

void Connection::database_write(Database* db) {

    WriteToBinaryFile wb(this->filename);
    wb.write(db->getSize());
    wb.write(db->getCapacity());

    for (int i = 0; i < db->getCapacity(); i++) {
        wb.write(db->rows[i]->getID());
        wb.write(db->rows[i]->getFilter());
        wb.write(db->rows[i]->getCarMake(), MAX_ENTRY_SIZE);
        wb.write(db->rows[i]->getCarModel(), MAX_ENTRY_SIZE);
        wb.write(db->rows[i]->getCarYear());
        wb.write(db->rows[i]->getCarPrice());
    }

    wb.close();
}


