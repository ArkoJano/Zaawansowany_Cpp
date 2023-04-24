//
// Created by Arek on 24.04.2023.
//
#include <iostream>

template<typename T, size_t N>
T inner(T *x, T *y){
    T result = 0;
    for (int i = 0; i < N; i++) {
        result += x[i] * y[i];
    }
    return result;
}

int main() {
    double a[] = {1, 2, 3};
    double b[] = {4, 5, 6};
    std::cout << "Iloczyn skalarny: " << inner<double, 3>(a, b) << std::endl;
    return 0;
}