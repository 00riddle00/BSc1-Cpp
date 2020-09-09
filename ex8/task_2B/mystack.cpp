#include<iostream>
#include "mystack.h"
#include "automobilis.h"
#include "object.h"

using namespace std;

AutoStack::AutoStack()
{
    top = 0;
    cout << "Stack was created successfully" << endl;
}


AutoStack::AutoStack(Object* autos[], int size)
{
    top = 0;

    if (size > SIZE) {
        cout << "Too many elements are passed into the stack constructor. Stack size is not enough" << endl;
    } else {
        for (int i = 0; i < size; i++) {
            v[ top++ ] = autos[i];
        }
        cout << "Stack from the array was created successfully" << endl;
    }
}

AutoStack::~AutoStack()
{
    cout << "Stack destructor has been called" << endl;
    if (this->empty()) {
        cout << "Stack was destroyed successfully" << endl;
    } else {
        cout << "Stack to be destroyed is not empty!" << endl;

      int i;

       for (i=0; i<top; i++)
       {
          delete v[i];
       }
       top -= i;

       if (this->empty()) {
           cout << "The stack is now empty" << endl;
           cout << "The memory of stack elements was successfully freed" << endl;
       }
    }
}

bool AutoStack::push(Object* val)
{
    if (top == SIZE) {
        cout << "The stack is full. The element cannot be pushed" << endl;
        return false;
    } 
    v[ top++ ] = val; 
    return true;
}

Object* AutoStack::pop()
{
    if (!top--) {
        throw("Stack is empty. The element cannot be popped.");
    }
    return (v[top]);
}

bool AutoStack::full()
{
    return (top >= SIZE);
}

bool AutoStack::empty()
{
    return (top == 0);
}

void AutoStack::MyStackPrint()
{
    int i;
    if (top == 0)
       cout << "Stack is empty." << endl;
    else
    {
       cout << "Stack contents: " << endl;
       for (i=0; i<top; i++)
       {
          cout << "[" << i << "] ";
          cout << v[i] << endl;
          //v[i]->print(); 
       }
       cout << endl;
    }
}
