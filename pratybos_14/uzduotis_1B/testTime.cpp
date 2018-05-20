#include <iostream>
#include "time.h"
using namespace std;

int main() {

Time t1(0, 4, 50);
t1.printStandard();
t1.printUniversal();

t1.setTime(23, 39, 5);
t1.printStandard();
t1.printUniversal();

try {
    Time t2(100, 4, 38);
} catch(IncorrectTimeException &e) {
    cout << "------EXCEPTION------ caught" << e.what() << endl;
} catch(range_error &e) {
    cout << "------EXCEPTION------" << e.what() << endl;
} catch(runtime_error &e) {
    cout << "------EXCEPTION------" << e.what() << endl;
} catch(...) {
    cout << "------EXCEPTION------ Unknown exception caught" << endl;
}



}
