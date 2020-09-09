#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	Stack<double> doubleStack;
	const size_t doubleStackSize = 5;
	double doubleValue = 1.1;
	
	cout << "Dedame elementus i doubleStack" << endl;
	
	for (size_t i = 0; i < doubleStackSize; i++) {
		doubleStack.push (doubleValue);
		cout << doubleValue << ' ';
		doubleValue = doubleValue + 1.1;
	}
	
	cout << "\n\nIsimame elementus is doubleStack" << endl;
	
	while (!doubleStack.isEmpty()) {
		cout << doubleStack.top() << ' ';
		doubleStack.pop();
	}
	
	cout << "\n\nStekas yra tuscias" << endl << endl;
	
	Stack<int> intStack;
	const size_t intStackSize = 5;
	int intValue = 1;
	
	cout << "Dedame elementus i intStack" << endl;
	
	for (size_t i = 0; i < intStackSize; i++) {
		intStack.push (intValue);
		cout << intValue << ' ';
		intValue = intValue + 1;
	}
	
	cout << "\n\nIsimame elementus is intStack" << endl;
	
	while (!intStack.isEmpty()) {
		cout << intStack.top() << ' ';
		intStack.pop();
	}
	
	cout << "\n\nStekas yra tuscias" << endl;
}

/*
Dedame elementus i doubleStack
1.1 2.2 3.3 4.4 5.5

Isimame elementus is doubleStack
5.5 4.4 3.3 2.2 1.1

Stekas yra tuscias

Dedame elementus i intStack
1 2 3 4 5

Isimame elementus is intStack
5 4 3 2 1

Stekas yra tuscias

*/
