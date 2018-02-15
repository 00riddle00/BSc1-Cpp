/* mystack.h -- Stack declaration and function prototypes:  */
#ifndef MYSTACK_H
#define MYSTACK_H

struct Stack {

    float v[20];
    int top;

    void push(float val);
    float pop();
    void init();
    int full();
    void MyStackPrint();
};

#endif
