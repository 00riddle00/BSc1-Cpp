#ifndef __RACIONALUS_SK_H_
#define __RACIONALUS_SK_H_

class RacionalusSk {
    private:
        int numerator;
        int denominator;

        // private methods
        int gcd(int n1, int n2);
        void simplify();

    public:
        // constructors
        
        RacionalusSk();

        RacionalusSk(int num, int den);

        // destructor 
        
        ~RacionalusSk();

        // setter

        void setNumber(int num, int den);

        // getters
        
        float getNumerator();

        float getDenominator();

        float getFloat();

        // member functions

        void printRational();

        void printFloat();

        void multiply(const RacionalusSk &rs);

        void divide(const RacionalusSk &rs);
};

#endif
