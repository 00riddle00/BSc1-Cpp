#include <iostream>
#include <iomanip>
#include <vector>

#include "Array.h"

using namespace std;

Array::Array() {
    size = 10;
    ptr = new int[size] {};
}

Array::Array(size_t sz) {
    size = sz;
    if (sz > 0) {
        ptr = new int[sz] {};
    } else {
        size = 10;
        ptr = new int[size] {};
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

size_t Array::getSize() const {
    return size;
}

void Array::setAt(size_t i, int value) {
    ptr[i] = value;
}

void Array::print() const{
    for (size_t i = 0; i < size; i++) {
        cout << ptr[i] << endl;
    }
}



