#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "Array.h"

using namespace std;

// Class methods

Array::Array() {
    size = 10;
    ptr = new int[size] {};
}

Array::Array(int sz) {
    size = sz;
    if (sz > 0) {
        ptr = new int[sz] {};
    } else {
        throw invalid_argument("the size cannot be zero or negative");
    }
}
    
Array::Array(const Array& orig) {
    size = orig.size;
    ptr = new int[size] {};
    for (size_t i = 0; i < size; i++) {
        ptr[i] = orig.ptr[i];
    }
}

Array::~Array() {
    delete ptr;
}

int Array::getSize() const {
    return size;
}

void Array::setAt(int i, int value) {
    if (i >= size || i < 0) {
        cout << "HERE" << endl;
        throw out_of_range("The index to be set is out of range");
    }
    ptr[i] = value;
}

void Array::print() const{
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << endl;
    }
}

const Array& Array::operator=(const Array& right) {
    if (this == &right) {
        throw std::invalid_argument("The element cannot be assigned to itself!");
    }
    if (this->size != right.size) {
        delete this->ptr;
        this->size = right.size;
        this->ptr = new int[this->size];
    }
    for (int i = 0; i < this->size; i++) {
        this->ptr[i] = right.ptr[i];
    }
    return *this;
}


// Kodel taip veikia?
int& Array::operator[] (int index) {
    cout << "(metodas1) ";

    if (index >= 0) {
        if ((index) >= size) {
            throw std::out_of_range("The index is out of bounds of an array");
        }
        return ptr[index];
    } else {
        // negative index: index from the end
        if (abs(index) >= size + 1) {
            throw std::invalid_argument("The index is out of bounds of an array");
        }
        // actually here the subtraction is performed
        return ptr[size+index];
    }
}

int Array::operator[] (int index) const {
    cout << "(metodas2) ";

    if (index >= 0) {
        if ((index) >= size) {
            throw std::out_of_range("The index is out of bounds of an array");
        }
        return ptr[index];
    } else {
        // negative index: index from the end
        if (abs(index) >= size + 1) {
            throw std::out_of_range("The index is out of bounds of an array");
        }
        // actually here the subtraction is performed
        return ptr[size+index];
    }
}


// Global operator overloading functions

ostream& operator<<(ostream &out, const Array& op2) {

    for (int i = 0; i < op2.size; i++) {
        out << op2.ptr[i] << " ";
    }
    return out;
}

istream& operator>>(istream &in, Array& op2) {
    cout << "Iveskite masyvo elementus (" << op2.size << "):" << endl;

    for (int i = 0; i < op2.size; i++) {
        in >> op2.ptr[i];
    }
    return in;
}

bool operator==(const Array& op1, const Array& op2) {
    if (op1.size != op2.size) {
        return false;
    } else {
        for (int i = 0; i < op1.size; i++) {
            if (op1.ptr[i] != op2.ptr[i]) {
                return false;
            }
        }
    }
    return true;
}

