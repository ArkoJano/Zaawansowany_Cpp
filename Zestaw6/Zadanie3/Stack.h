//
// Created by Arek on 16.04.2023.
//

#ifndef ZAAWANSOWANY_CPP_STACK_H
#define ZAAWANSOWANY_CPP_STACK_H

#include<iostream>


#include"checking_policy.h"
#include"allocator_policy.h"


template<typename T = int , size_t N = 100,
        typename Checking_policy = No_checking_policy,
        template<typename U,size_t M>  class Allocator_policy
        = Static_table_allocator >
class Stack {

    typedef typename Allocator_policy<T,N>::rep_type rep_type;
    rep_type  _rep;
    size_t _top;
    Allocator_policy<T,N> alloc;
public:
    Stack(size_t n = N):_top(0) {
        alloc.init(_rep,n);
    };

    void push(const T &val) {
        alloc.expand_if_needed(_rep,_top);
        Checking_policy::check_push(_top,alloc.size());
        _rep[_top++]=val;
    }

    void pop()              {
        Checking_policy::check_pop(_top);
        --_top;
        alloc.shrink_if_needed(_rep,_top);
    }

    const T& top()  const   {
        Checking_policy::check_top(_top);
        return _rep[_top-1];
    }

    T& top()     {
        Checking_policy::check_top(_top);
        return _rep[_top-1];
    }


    bool is_empty()         {
        return !_top;
    }

    ~Stack() {alloc.dealocate(_rep);}

};


#endif //ZAAWANSOWANY_CPP_STACK_H
