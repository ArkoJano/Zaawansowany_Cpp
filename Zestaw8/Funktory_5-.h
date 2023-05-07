//
// Created by Arek on 07.05.2023.
//

#ifndef ZAAWANSOWANY_CPP_FUNKTORY_5_H
#define ZAAWANSOWANY_CPP_FUNKTORY_5_H

#include "cmath"

template<typename F> double integrate(F f,double  min,double max,double ds) {
    double integral=.0;
    for(double x=min;x<max;x+=ds) {
        integral+=f(x);
    }
    return integral*ds;
};


template<typename T> class Variable {
public:
    T operator()(T x) {
        return x;
    }
};


template<typename T> class Constant {
    T _c;
public:
    Constant(T c) :_c(c){};
    T operator()(T x) {return _c;}
};

template<typename T, typename R = Variable<T> > class Expr {
    R _rep;
public:
    Expr() {};
    Expr(R rep) : _rep(rep) {};
    T operator() (T x) {return _rep(x);}
    R rep() const {return _rep; };
};


template<typename T, typename FirstFunct,typename SecondFunct > class AddExpr {
    FirstFunct _first;
    SecondFunct _second;
public:
    AddExpr(const FirstFunct &f,const SecondFunct &s) :_first(f),_second(s) {};
    T operator()(T x) {
        return _first(x)+_second(x);
    }
};

template<typename T,typename FirstFunct,typename SecondFunct >
Expr<T,AddExpr<T,FirstFunct,SecondFunct> >  operator+(const Expr<T,FirstFunct> &f,
                                       const Expr<T,SecondFunct> &s) {
    return Expr<T,AddExpr<T,FirstFunct,SecondFunct> >(AddExpr<T,FirstFunct,SecondFunct>(f.rep(),s.rep()));
};


template<typename T,typename FirstFunct >
Expr<T,AddExpr<T,FirstFunct,Constant<T> > >
operator+(const Expr<T,FirstFunct>  &f,
          T s) {
    return Expr<T,AddExpr<T,FirstFunct,Constant<T> > >(AddExpr<T,FirstFunct,Constant<T> >(f.rep(),Constant<T>(s)));
};


template<typename T,typename SecondFunct >
Expr<T,AddExpr<T,Constant<T>,SecondFunct > >  operator+(T f,
                                                const Expr<T,SecondFunct>  &s) {
    return Expr<T,AddExpr<T,Constant<T>,SecondFunct> >(AddExpr<T,Constant<T>,SecondFunct>(Constant<T>(f),s.rep()));
};

#endif //ZAAWANSOWANY_CPP_FUNKTORY_5_H
