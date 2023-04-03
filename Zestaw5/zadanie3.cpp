//
// Created by Arek on 03.04.2023.
//

#include <iostream>
#include <vector>

template<typename T, typename U> class is_convetible{
    static char test(U);
    static int test(...);
    static T makeT();

public:
    static const bool yes = (sizeof(test(makeT())) == sizeof(char));
    static const bool same_type = false;
};

template <typename T> class is_convetible<T, T>{
public:
    static const bool yes = true;
    static const bool same_type = true;
};

int main() {
    std::cout<<std::boolalpha;
    std::cout<<is_convetible<int,double>::yes<<std::endl;
    std::cout<<is_convetible<double,int>::yes<<std::endl;

    std::cout<<is_convetible<double,int>::same_type<<std::endl;

    std::cout<<is_convetible<size_t,unsigned int>::same_type<<std::endl;
    std::cout<<is_convetible<std::vector<double>::value_type,
            double >::same_type<<std::endl;

    std::cout<<is_convetible<std::vector<double>::iterator,
            double *>::same_type<<std::endl;
}