#include <deque>
#include <cstddef>
#include "Stack.h"

//return top element of the Stack
template <class T>
T& Stack<T>::top() {
    return stack.front();
}

//push an element into Stack
template <class T>
void Stack<T>::push(const T& pushValue) {
    stack.push_front(pushValue);
}

//pop an element from the Stack
template <class T>
void Stack<T>::pop() {
    stack.pop_front();
}

//determine if Stack is empty
template <class T>
bool Stack<T>::isEmpty() const {
    return stack.empty();
}

//return size of the Stack
template <class T>
size_t Stack<T>::size() const {
    return stack.size();
}
