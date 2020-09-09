#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
    int size;
    int *ptr;

    public:
        Array();
        Array(int sz);
        Array(const Array& orig);
        ~Array();

        int getSize() const;
        void setAt(int i, int value);
        void print() const;
        const Array& operator=(const Array&);
        int& operator[] (int);
        int operator[] (int) const;
 
        friend std::ostream& operator<<(std::ostream &, const Array&);
        friend std::istream& operator>>(std::istream &, Array&);
        friend bool operator==(const Array&, const Array&);
};

#endif
