// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// modified by I.M. on 24/10/2008; 19/10/2009
#include <iostream>

using namespace std;

class Integer {
	int* p;
public:
   Integer(int x = 0) {
  		p = new int;
		*p = x;
        cout << "Integer object is created with x = " << x << endl;
   }

/*   Integer(const Integer& orig) {*/
       //p = new int;
       //*p = *(orig.p);
        //cout << "Integer object is created by deep copy with x = " << *(orig.p) << endl;
   //}

  ~Integer() {
        cout << "Integer object is destroyed with x = " << *p << endl;
  		delete p;
    }
  
  void set(int x) {*p = x;}
  int get() const {
      if (p == nullptr) {
          // Kodel ne nullptr p yra?
          cout << "nullptr" << endl;
      } else {
          cout << "not null" << endl;
      }
      return *p;
  }

};
 
void daugybos_lentele(const Integer x){
	for ( int i = 0; i < 10; i++) {
		cout << x.get() << " x " << i << " = " << x.get() * i << endl;
	}
}

int main() {
	Integer i1(5);
	cout << "i1 reiksme yra " << i1.get() << endl;

	daugybos_lentele(i1);
	cout << "i1 reiksme yra " << i1.get() << endl;
}



