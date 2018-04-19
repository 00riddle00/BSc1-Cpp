#ifndef STRINGSTACK_H
#define STRINGSTACK_H

#include <string>
#include "MyString.h"

class StringStack
{
    static const int size = 100;
    MyString* v[size];
    int top;
    public:
    bool push(MyString* val);
	const MyString* pop();
	bool full();
	bool empty();
	StringStack(); 
	~StringStack();
};
#endif

