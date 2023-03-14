//
// Created by Arko on 05.03.2023.
//
#include "iostream"


template <typename T> T maksimum(T a, T b){
    return a >= b ? a : b;
}

int main(){

    std::cout<<maksimum<int>(11, 6)<<std::endl;
    std::cout<<maksimum<int>(5, 6)<<std::endl;
    std::cout<<maksimum(5, 6)<<std::endl;
    std::cout<<maksimum<double>(5.5, 6)<<std::endl;
    std::cout<<maksimum(5.5, 6.3)<<std::endl;
    std::cout<<maksimum("Cpp", "ppC")<<std::endl;
    std::cout<<maksimum("Cpp", "Cap")<<std::endl;

}