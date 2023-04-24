//
// Created by Arek on 24.04.2023.
//
#include <iostream>

template<size_t N>
double inner(double *x, double *y){
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += x[i] * y[i];
    }
    return result;
}

int main() {
    double a[] = {1, 2, 3};
    double b[] = {4, 5, 6};
    std::cout << "Iloczyn skalarny: " << inner<3>(a, b) << std::endl;
    return 0;
}