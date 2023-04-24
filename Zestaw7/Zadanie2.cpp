//
// Created by Arek on 24.04.2023.
//

#include "iostream"

template <int N, int M> class Pow {
public:
    static int value() {
        return N * Pow<N, M-1>::value();
    }
};
template <int N> class Pow<N, 0> {
public:
    static int value() {
        return 1;
    }
};

int main(){

    std::cout<< "Pow<2,2> = " << Pow<2,2>::value() <<std::endl;
    std::cout<< "Pow<2,3> = " << Pow<2,3>::value() <<std::endl;
    std::cout<< "Pow<3,4> = " << Pow<3,4>::value() <<std::endl;

    return 0;
}
