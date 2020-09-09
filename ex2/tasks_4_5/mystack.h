/* mystack.h -- Stack declaration and function prototypes:  */
#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include "automobilis.h"

template <class T>
class Stack {
   public:
        struct Node {
            T data;
            struct Node *link;
        };

       Node *top;

        void init() {
            this->top = NULL;
        }

        void push(T input) {
          Node* temp = new Node();
          temp->data = input;
          temp->link = this->top;
          this->top = temp;
        }

        void pop() {
            Node *temp;
            if(this->top == NULL) return;
            temp = this->top;
            this->top = this->top->link;
            free(temp);
        }

        void printStack() {
            Node *temp = this->top;
            std::cout << "Stack elements from the top: " << std::endl;
            int i = 1;
            while (temp != NULL) {
                std::cout << "[" << i << "] ";
                std::cout << (temp->data) << " ";
                std::cout << std::endl;
                temp = temp->link;
                i++;
            }
            std::cout << std::endl;
        }
};


template <>
class Stack<Automobilis*> {
   public:
        struct Node {
            Automobilis* data;
            struct Node *link;
        };

       Node *top;

        void init() {
            this->top = NULL;
        }

        void push(Automobilis* input) {
          Node* temp = new Node();
          temp->data = input;
          temp->link = this->top;
          this->top = temp;
        }

        void pop() {
            Node *temp;
            if(this->top == NULL) return;
            temp = this->top;
            this->top = this->top->link;
            free(temp);
        }

        void printStack() {
            Node *temp = this->top;
            std::cout << "Stack elements from the top: " << std::endl;
            int i = 1;
            while (temp != NULL) {
                std::cout << "[" << i << "] ";
                temp->data->print();
                std::cout << std::endl;
                temp = temp->link;
                i++;
            }
            std::cout << std::endl;
        }
};


#endif
