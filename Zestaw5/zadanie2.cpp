//
// Created by Arek on 03.04.2023.
//
#include <iostream>
#include <vector>

template <typename T>
class has_value_type {
    template<typename U> static char test(typename U::value_type*);

    template<typename U> static int test(...);
public:
    static const bool yes = (sizeof(test<T>(0)) == sizeof(char));
};

int main(){
    std::cout<<std::boolalpha;
    std::cout<<has_value_type<std::vector<int>>::yes <<std::endl;
    std::cout<<has_value_type<int>::yes <<std::endl;

    return 0;
}