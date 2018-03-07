#include <iostream>
#include <fstream>
#include <vector>

#include "load_from_binary_file.h"
#include "write_to_binary_file.h"
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

void Connection::database_load() {

    this->input.open(this->filename, ios::in | ios::binary);

    this->input.seekg(0, std::ios::end);
    if (this->input.tellg() == 0)
    {
        std::cout << "File is empty" << std::endl;
        this->db = new Database;
        this->database_write();
        this->input.close();
        return;
    }

    LoadFromBinaryFile lb(this->filename);

    if(this->input.good()) {
        this->db = new Database(lb.readInt(), lb.readInt());

        for (int i = 0; i < this->db->getCapacity(); i++) {

            this->db->rows[i]->id = lb.readInt();
            this->db->rows[i]->filter = lb.readInt();

             //TODO add valitaion exception catching
            this->db->rows[i]->setCarMake(lb.readString(MAX_ENTRY_SIZE));
            this->db->rows[i]->setCarModel(lb.readString(MAX_ENTRY_SIZE));
            this->db->rows[i]->setCarYear(lb.readInt());
            this->db->rows[i]->setCarPrice(lb.readInt());

/*            this->db->rows[i]->car_make = lb.readString(MAX_ENTRY_SIZE);*/
            //this->db->rows[i]->car_model = lb.readString(MAX_ENTRY_SIZE);
            //this->db->rows[i]->car_year = lb.readInt();
            //this->db->rows[i]->car_price = lb.readInt();

        }

        lb.close();
    } 
}

void Connection::database_write() {

    WriteToBinaryFile wb(this->filename);
    wb.write(this->db->getSize());
    wb.write(this->db->getCapacity());

    for (int i = 0; i < this->db->getCapacity(); i++) {
        wb.write(this->db->rows[i]->id);
        wb.write(this->db->rows[i]->filter);
        wb.write(this->db->rows[i]->getCarMake(), MAX_ENTRY_SIZE);
        wb.write(this->db->rows[i]->getCarModel(), MAX_ENTRY_SIZE);
        wb.write(this->db->rows[i]->getCarYear());
        wb.write(this->db->rows[i]->getCarPrice());
    }

    wb.close();
}


