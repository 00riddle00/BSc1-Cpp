/* mystack.h -- Stack declaration and function prototypes:  */
#ifndef __MYSTACK_H
#define __MYSTACK_H

#include "automobilis.h"

#define SIZE 20
class AutoStack
{
    void* v[SIZE];
    int top;

    public:
        AutoStack();
        AutoStack(void* [], int);
        ~AutoStack();
        bool push(void* val);
        void* pop();
        void init();
        bool full();
        bool empty();
        void MyStackPrint();
};

#endif
