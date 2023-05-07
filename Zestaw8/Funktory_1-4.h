//
// Created by Arek on 07.05.2023.
//

#ifndef ZAAWANSOWANY_CPP_FUNKTORY_1_4_H
#define ZAAWANSOWANY_CPP_FUNKTORY_1_4_H

#include<cmath>

// Zadanie 1
template<typename F>
double integrate(F f, double min, double max, double ds) {
    double integral = 0.0;
    for (double x = min; x < max; x += ds) integral += f(x);
    return integral * ds;
}

// Zadanie 2
class Variable {
public:
    double operator()(double x) {
        return x;
    }
};

class Constant {
    double _c;

public:
    Constant(double c): _c(c) {};
    double operator()(double x) {return _c;};
};


// Zadanie 3

template <typename FirstFunct, typename SecondFunct> class AddExpr {
    FirstFunct _first;
    SecondFunct _second;
public:
    AddExpr(const FirstFunct &f, const SecondFunct &s): _first(f), _second(s) {};
    double operator()(double x) {
        return _first(x) + _second(x);
    }
};


template <typename FirstFunct, typename SecondFunct> AddExpr<FirstFunct, SecondFunct> operator+(const FirstFunct &f, const SecondFunct &s) {
    return AddExpr<FirstFunct, SecondFunct>(f, s);
};

template <typename FirstFunct> AddExpr<FirstFunct, Constant> operator+(const FirstFunct &f, double s) {
    return AddExpr<FirstFunct, Constant> (f, Constant(s));
};

template <typename SecondFunct> AddExpr<Constant, SecondFunct> operator+(double f, const SecondFunct &s) {
    return AddExpr<Constant, SecondFunct>(Constant(f), s);
};

// Zadanie 4

template<typename FirstFunct, typename SecondFunct> class DivExpr {
    FirstFunct _first;
    SecondFunct _second;

public:
    DivExpr(const FirstFunct &f, const SecondFunct &s) : _first(f), _second(s) {};
    double operator()(double x) {
        return _first(x)/_second(x);
    }
};

template<typename FirstFunct, typename SecondFunct> DivExpr<FirstFunct, SecondFunct> operator/(const FirstFunct &f, const SecondFunct &s) {
    return DivExpr<FirstFunct, SecondFunct> (f, s);
}

template<typename FirstFunct> DivExpr<FirstFunct, Constant> operator/(const FirstFunct &f, double s) {
    return DivExpr<FirstFunct, Constant> (f, Constant(s));
}

template<typename SecondFunct> DivExpr<Constant, SecondFunct> operator/(double f, const SecondFunct &s) {
    return DivExpr<Constant, SecondFunct> (Constant(f), s);
}


template <typename Arg> class SinExpr{
  Arg _arg;
public:
    SinExpr(const Arg &arg) : _arg(arg) {};
    double operator()(double x) {
        return sin(_arg(x));
    }
};

template <typename Arg> SinExpr<Arg> sin (const Arg &a){
    return SinExpr<Arg>(a);
}

#endif //ZAAWANSOWANY_CPP_FUNKTORY_1_4_H
