/* mystack.h -- Stack declaration and function prototypes:  */
#ifndef __MYSTACK_H
#define __MYSTACK_H

#include "automobilis.h"

#define SIZE 20
class AutoStack
{
    Automobilis* v[SIZE];
    int top;

    public:
        AutoStack();
        ~AutoStack();
        void push(Automobilis* val);
        Automobilis* pop();
        void init();
        int full();
        bool empty();
        void MyStackPrint();
};

#endif
