//
// Created by Arek on 24.04.2023.
//

#include "iostream"

template<int N> inline double pow(double x) {return x*pow<N-1>(x);}
template<>      inline double pow<0>(double x) {return 1.0;}

int main() {
    const double x = 2.0;
    const int N = 5;
    std::cout << x << " do potegi " << N << " wynosi: " << pow<N>(x) << std::endl;
    return 0;
}