#include<iostream>
#include "mystack.h"
#include "automobilis.h"

using namespace std;

AutoStack::AutoStack()
{
    top = 0;
    cout << "Stack was created successfully" << endl;
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
           cout << "The stack is empty" << endl;
           cout << "The memory was successfully freed" << endl;
       }
    }
}

void AutoStack::push(Automobilis* val)
{
    v[ top ] = val; 
    top++;    
}

Automobilis* AutoStack::pop()
{
    top--;
    return (v[top]);
}

int AutoStack::full()
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
          v[i]->print(); 
       }
       cout << endl;
    }
}
