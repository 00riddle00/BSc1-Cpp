#include <iostream>
#include "Namespace1.h"
#include "Namespace2.h"

using namespace std;

namespace Test1 {

    void testNamespace1() {
        cout << "From namespace Test1" << endl;
        Namespace::Time t(12,40,45);
        t.printStandard();
        t.printUniversal();
        cout << "--------" << endl;
    }

    void testNamespace2() {
        cout << "From namespace Test1" << endl;
        using namespace Namespace;
        Time t(4,20,0);
        t.printStandard();
        t.printUniversal();
        cout << "--------" << endl;
    }
}


namespace Test2 {

    void testNamespace1() {
        cout << "From namespace Test2" << endl;
        Namespace::Time t(12,40,45);
        t.printStandard();
        t.printUniversal();
        cout << "--------" << endl;
    }

    void testNamespace2() {
        cout << "From namespace Test2" << endl;
        using namespace Namespace;
        Time t(4,20,0);
        t.printStandard();
        t.printUniversal();
        cout << "--------" << endl;
    }
}

using namespace Test1;



int main() {

    using Test2::testNamespace2;

    Test1::testNamespace1();

    testNamespace2();

    namespace Clock = Namespace;

    Clock::Time t1(0, 4, 50);
    t1.printStandard();
    t1.printUniversal();

    t1.setTime(23, 39, 5);
    t1.printStandard();
    t1.printUniversal();

try {
    Clock::Time t2(100, 4, 38);
} catch(Clock::IncorrectTimeException &e) {
    cout << "------EXCEPTION------ " << "In function: [" << e.getFunctionName() << "] " << e.what() << endl;
} catch(range_error &e) {
    cout << "------EXCEPTION------" << e.what() << endl;
} catch(runtime_error &e) {
    cout << "------EXCEPTION------" << e.what() << endl;
} catch(...) {
    cout << "------EXCEPTION------ Unknown exception caught" << endl;
}



}
