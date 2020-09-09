#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
    size_t size;
    //int[] *ptr;
    int *ptr;

    public:
        Array();
        Array(size_t sz);
        Array(const Array& orig);
        ~Array();

        size_t getSize() const;
        void setAt(size_t i, int value);
        void print() const;
};

#endif
