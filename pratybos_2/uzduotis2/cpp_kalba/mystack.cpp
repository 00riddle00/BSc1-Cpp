#include<iostream>
#include "mystack.h"
using namespace std;

void Stack::push(float val)
{
    this->v[ this->top ] = val; 
   (this->top)++;    
/*  Equivalent to: S->v[ (S->top)++ ] = val;   */
}

float Stack::pop()
{
    (this->top)--;
    return (this->v[this->top]);
/*  Equivalent to: return (S->v[--(S->top)]);  */
}

void Stack::init()
{
    this->top = 0;
}

int Stack::full()
{
    return (this->top >= 20);
}

void Stack::MyStackPrint()
{
    int i;
    if (this->top == 0)
       cout << "Stack is empty." << endl;
    else
    {
       cout << "Stack contents: " << endl;
       for (i=0;i<this->top;i++)
       {
          printf("%g  ",this->v[i]); 
       }
       printf("\n");
    }
}
