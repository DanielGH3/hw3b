#include <iostream>
#include <fstream>

namespace ariel{
    class Fraction{
        private:
            int num;
            int den;

            void simplify();

        public:
            Fraction();
            Fraction(float flo);
            Fraction(int num, int den);

            friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);

            friend bool operator==(const Fraction& frac1, const Fraction& frac2);
            friend bool operator>(const Fraction& frac1, const Fraction& frac2);
            friend bool operator<(const Fraction& frac1, const Fraction& frac2);
            friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
            friend bool operator<=(const Fraction& frac1, const Fraction& frac2);

            Fraction& operator++();
            Fraction& operator--();

            Fraction operator++(int);
            Fraction operator--(int);

            friend std::ostream& operator<<(std::ostream& _os, const Fraction& frac);
            friend std::istream& operator>>(std::istream& _is, Fraction& frac);

            int getNumerator();
            int getDenominator();
    };
}


