/****************************************************************************/
/*   Sample Cpp stack tester demonstrating the usage of mystack functions.    */
/*   Stack struct is declared and functions are prototyped in mystack.h.    */ 
/*   The Cpp code for the functions is in mystack.cpp.                     */
/*                                                                          */
/****************************************************************************/
#include <iostream>
#include "mystack.h"
using namespace std;

int main()
{
    Stack S;

    S.init();

    S.MyStackPrint();

    S.push(2.31);
    S.push(1.19);
   
    S.MyStackPrint();

    cout << "Popped value is " << S.pop() << endl;
    //printf("Popped value is: %g\n",pop(&S));
    
    S.push(6.7);

    S.MyStackPrint();

    S.push(S.pop() + S.pop()); 

    S.MyStackPrint();
    return 0;
}

