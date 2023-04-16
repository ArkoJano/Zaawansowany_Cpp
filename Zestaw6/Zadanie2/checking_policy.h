//
// Created by Arek on 16.04.2023.
//

#ifndef ZAAWANSOWANY_CPP_CHECKING_POLICY_H
#define ZAAWANSOWANY_CPP_CHECKING_POLICY_H
#include<iostream>

struct No_checking_policy{
    static void check_push(size_t top, size_t N){};
    static void check_pop(size_t top){};
    static void check_top(size_t top){};
};

struct Abort_on_error_policy{
    static void check_push(size_t top, size_t N){
        if(top >= N){
            std::cerr<<"Trying to push element on full stack: aborting" <<std::endl;
            abort();
        }
    };
    static void check_pop(size_t top){
        if(top == 0){
            std::cerr<<"Trying to pop an empty stack: aborting"<<std::endl;
            abort();
        }
    };
    static void check_top(size_t top){
        if(top == 0){
            std::cerr<<"Tryung to read from empty stack: aborting"<<std::endl;
            abort();
        }
    };
};

#endif //ZAAWANSOWANY_CPP_CHECKING_POLICY_H
