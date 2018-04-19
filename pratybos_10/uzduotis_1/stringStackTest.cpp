#include <string>
#include <iostream>
#include "stringStack.h"
#include "MyString.h"
using namespace std;

MyString* iceCream[] = {
   new MyString("pralines & cream"),
   new MyString("fudge ripple"),
   new MyString("jamocha almond fudge"),
   new MyString("wild mountain blackberry"),
   new MyString("raspberry sorbet"),
   new MyString("lemon swirl"),
   new MyString("rocky road"),
   new MyString("deep chocolate fudge")
};

const int iCsz = 
  sizeof iceCream / sizeof *iceCream;

int main() {
  StringStack ss;
  for(int i = 0; i < iCsz; i++)
    ss.push(iceCream[i]);
  const MyString* cp;
  while((cp = ss.pop()) != NULL)
    cp->print();
} 
