#include <iostream>

using namespace std;

class Math {
    static int value;
    static float PI; 
    static int calculations;

    // private constructor/destructor to prohibit instantiation
    Math() {}
    ~Math() {}

    public:
        static void SetCalcuations(int c) {
            calculations = c;
        }

        static int GetCalculations() {
            return calculations;
        }

        static int factorial(int n) {
            int res = n;
            while (n != 1) {
                res *= --n;
            }
            calculations++;
            return res;
        }

        static int fibonacci(int n) {
            if(1 == n || 2 == n) {
                return 1;
            } else {
                return fibonacci(n-1) + fibonacci(n-2);
            }
        }

        static float getPI() {
            return PI;
        }

};

int Math::value;
float Math::PI = 3.14159265358979323846;
int Math::calculations;


int main() {

    Math::SetCalcuations(10);
    cout << "Calculations beforehand: " << Math::GetCalculations() << endl;
    cout << "4 Factorial: " << Math::factorial(4) << endl;
    cout << "6 Factorial: " << Math::factorial(6) << endl;
    cout << "8th Fibonacci number: " << Math::fibonacci(8) << endl;
    cout << "PI: " << Math::getPI() << endl;
    cout << "Calculations afterwards: " << Math::GetCalculations() << endl;
}
