//
// Created by Arek on 24.04.2023.
//

#include "iostream"

template<int number> int factorial() {
    return number*factorial<number-1>();
}

template<> int factorial<1>() {
    return 1;
}

int main(){
    std::cout<<"factorial<1>() = "<< factorial<1>() <<std::endl;
    std::cout<<"factorial<2>() = "<< factorial<2>() <<std::endl;
    std::cout<<"factorial<3>() = "<< factorial<3>() <<std::endl;
    std::cout<<"factorial<4>() = "<< factorial<4>() <<std::endl;
    std::cout<<"factorial<5>() = "<< factorial<5>() <<std::endl;

    return 0;
}