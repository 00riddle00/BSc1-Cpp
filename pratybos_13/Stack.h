#ifndef STACK_H
#define STACK_H
#include <deque>
#include <cstddef>

template <class T>
class Stack {
	std::deque<T> stack;
	public:
	//return top element of the Stack
	T& top();
	//push an element into Stack
	void push(const T& pushValue);
	//pop an element from the Stack
	void pop();
	//determine if Stack is empty
	bool isEmpty() const;
	//return size of the Stack
	size_t size() const;
};

template class Stack<double>;
template class Stack<int>;

#endif
