#include "Fraction.hpp"

using namespace ariel;
#define LONG long long

bool is_empty(std::istream& stream)
{
    return stream.peek() == std::istream::traits_type::eof();
}

ariel::Fraction::Fraction()
{
    this->num = 0;
    this->den = 1;
    this->simplify();
}

ariel::Fraction::Fraction(float flo)
{
    this->num = flo * 1000;
    this->den = 1000;
    this->simplify();
}

ariel::Fraction::Fraction(int num, int den)
{
    this->num = num;
    this->den = den;

    if(den == 0){
        throw std::invalid_argument("");
    }

    this->simplify();
}

int GCD(int a, int b){
    if (b == 0) return a;
    return GCD(b, a % b);
}

void ariel::Fraction::simplify()
{
    if(den == 0){
        throw std::runtime_error("");
    }

    int ld;
    ld = GCD(this->num, this->den);
    this->num = this->num / ld;
    this->den = this->den / ld;

    if(this->den < 0){
        this->den *= -1;
        this->num *= -1;
    }
}

Fraction ariel::operator+(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.num * frac2.den + frac2.num * frac1.den;
    int den = frac1.den * frac2.den;

    LONG expectednum = (LONG)frac1.num * (LONG)frac2.den + (LONG)frac2.num * (LONG)frac1.den;
    LONG expectedden = (LONG)frac1.den * (LONG)frac2.den;

    Fraction ret = Fraction(num, den);

    if(expectednum != num || expectedden != den){
        throw std::overflow_error("");
    }

    ret.simplify();
    return ret;
}

Fraction ariel::operator-(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.num * frac2.den - frac2.num * frac1.den;
    int den = frac1.den * frac2.den;

    LONG expectednum = (LONG)frac1.num * (LONG)frac2.den - (LONG)frac2.num * (LONG)frac1.den;
    LONG expectedden = (LONG)frac1.den * (LONG)frac2.den;

    Fraction ret = Fraction(num, den);

    if(expectednum != num || expectedden != den){
        throw std::overflow_error("");
    }

    ret.simplify();
    return ret;
}

Fraction ariel::operator*(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.num * frac2.num;
    int den = frac1.den * frac2.den;

    LONG expectednum = (LONG)frac1.num * (LONG)frac2.num;
    LONG expectedden = (LONG)frac1.den * (LONG)frac2.den;

    Fraction ret = Fraction(num, den);

    if(expectednum != num || expectedden != den){
        throw std::overflow_error("");
    }

    ret.simplify();
    return ret;
}

Fraction ariel::operator/(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.num * frac2.den;
    int den = frac1.den * frac2.num;

    LONG expectednum = (LONG)frac1.num * (LONG)frac2.den;
    LONG expectedden = (LONG)frac1.den * (LONG)frac2.num;

    if(expectedden == 0){
        throw std::runtime_error("");
    }

    Fraction ret = Fraction(num, den);

    if(expectednum != num || expectedden != den){
        throw std::overflow_error("");
    }

    ret.simplify();
    return ret;
}

bool ariel::operator==(const Fraction &frac1, const Fraction &frac2)
{
    return frac1.num == frac2.num && frac1.den == frac2.den;
}

bool ariel::operator>(const Fraction &frac1, const Fraction &frac2)
{
    Fraction sub = frac1 - frac2;
    return sub.num > 0;
}

bool ariel::operator<(const Fraction &frac1, const Fraction &frac2)
{
    Fraction sub = frac2 - frac1;
    return sub.num > 0;
}

bool ariel::operator>=(const Fraction &frac1, const Fraction &frac2)
{
    Fraction sub = frac1 - frac2;
    return sub.num >= 0;
}

bool ariel::operator<=(const Fraction &frac1, const Fraction &frac2)
{
    Fraction sub = frac2 - frac1;
    return sub.num >= 0;
}

Fraction &ariel::Fraction::operator++()
{
    this->num += this->den;
    return *this;
}

Fraction &ariel::Fraction::operator--()
{
    this->num -= this->den;
    return *this;
}

Fraction ariel::Fraction::operator++(int)
{
    Fraction tmp(*this);
    operator++();
    return tmp;
}

Fraction ariel::Fraction::operator--(int)
{
    Fraction tmp(*this);
    operator--();
    return tmp;
}

int ariel::Fraction::getNumerator()
{
    return num;
}

int ariel::Fraction::getDenominator()
{
    return den;
}

std::ostream &ariel::operator<<(std::ostream &_os, const Fraction &frac)
{
    _os << frac.num << '/' << frac.den;
    return _os;
}

std::istream &ariel::operator>>(std::istream &_is, Fraction &frac)
{
    if(is_empty(_is)) throw std::runtime_error("");
    _is >> frac.num;
    if(is_empty(_is)) throw std::runtime_error("");
    _is >> frac.den; 

    if(frac.den == 0){
        throw std::runtime_error("");
    }

    frac.simplify();
    return _is;
}
