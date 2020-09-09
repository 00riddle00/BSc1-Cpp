#include <iostream>
#include <string>
#include <vector>
#include "mystack.h"
#include "automobilis.h"
using namespace std;


int main() {

    Automobilis* automobilis1 = new Automobilis();
    automobilis1->setGamintojas("BMW");
    automobilis1->setModelis("520d");
    automobilis1->setVariklioTuris(3.0);

    Automobilis* automobilis2 = new Automobilis();
    automobilis2->setGamintojas("Audi");
    automobilis2->setModelis("A4");
    automobilis2->setVariklioTuris(2.0);

    //vector<Automobilis> v;

    //v.push_back(automobilis1);
    //v.push_back(automobilis2);
     
    Stack <Automobilis*> s1;

    s1.init();

    //for(int i = 0; i < v.size(); i++) {
       //s1.push(v[i]);
    //}

    s1.push(automobilis1);
    s1.push(automobilis2);

    s1.printStack();
    s1.pop();
    s1.printStack();


    Stack <float> s2;
    s2.init();
    s2.push(3.14);
    s2.push(2.72);
    s2.printStack();
    s2.pop();
    s2.printStack();


    Stack <string> s3;
    s3.init();
    s3.push("Hello");
    s3.push("World");
    s3.printStack();
    s3.pop();
    s3.printStack();


}

