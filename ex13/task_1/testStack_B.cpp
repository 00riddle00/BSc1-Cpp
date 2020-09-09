#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
void testStack(Stack<T> & theStack, const T& value, const T& increment, size_t size, const string& StackName) {
    cout << "Dedame elementus i " << StackName << endl;
    T stackValue = value;

    for (size_t i = 0; i < size; i++) {
        theStack.push(stackValue);
        cout << stackValue << ' ';
        stackValue += increment;
    }

    cout << "\n\nIsimame elementus is " << StackName << endl;

    while (!theStack.isEmpty()) {
        cout << theStack.top() << ' ';
        theStack.pop();
    }

    cout  << "\n\nStekas yra tuscias" << endl << endl;
}


int main() {
    Stack <double> doubleStack;
    testStack(doubleStack, 1.1, 1.1, 5, "doubleStack");

    Stack <int> intStack;
    testStack(intStack, 1, 1, 5, "intStack");
	
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
