//
// Created by convi on 2020/3/24.
//

#ifndef COMBINATORIALMATHEMATICS_FRACTION_H
#define COMBINATORIALMATHEMATICS_FRACTION_H


#include <cmath>

class Fraction {
private:
    int up;
    int down;

    static Fraction reduction(Fraction result);

    static int gcd(int a, int b);

public:
    int ceil();    //严格大于
    int floor();   //严格小于
    int value();    //down 必须等于1
    bool has_value();


    Fraction(int up, int down);

    explicit Fraction(int up);

    Fraction();

    Fraction operator+(const Fraction &f);

    Fraction operator-(const Fraction &f);

    Fraction operator*(const Fraction &f);

    Fraction operator/(const Fraction &f);

    void operator=(const Fraction &f);

    void operator=(const int &i);

    bool operator==(const Fraction &f);
};


#endif //COMBINATORIALMATHEMATICS_FRACTION_H
