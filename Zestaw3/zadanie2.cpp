//
// Created by Arek on 16.03.2023.
//

//Na przykładzie szablonu funkcji convert pokazać, że jest możliwe zdefiniowanie dwóch funkcji o tej samej
// nazwie i argumentach wywołania, różniących się tylko zwracanym typem.

#include <iostream>

template<typename T, typename U> T convert(U u) {
    return static_cast<T>(u);
}

template <> int convert<int, double> (double u){
    return static_cast<int>(u);
}
template <> double convert<double, double> (double u){
    return static_cast<double>(u);
}

int main(){

    double one_d = 1.0, two_d = 2;

    std::cout << "one_d = " << one_d << std::endl;
    std::cout << "two_d = " << two_d << std::endl;


    std::cout << "convert<int, double>(one) = "<< convert<int, double>(one_d) << std::endl;
    std::cout << "convert<double, int>(one_d) = "<< convert<double, int>(one_d) << std::endl;
}