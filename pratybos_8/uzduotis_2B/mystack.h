/* mystack.h -- Stack declaration and function prototypes:  */
#ifndef __MYSTACK_H
#define __MYSTACK_H

#include "automobilis.h"
#include "object.h"

#define SIZE 20
class AutoStack
{
    Object* v[SIZE];
    int top;

    public:
        AutoStack();
        AutoStack(Object* [], int);
        ~AutoStack();
        bool push(Object* val);
        Object* pop();
        void init();
        bool full();
        bool empty();
        void MyStackPrint();
};

#endif
