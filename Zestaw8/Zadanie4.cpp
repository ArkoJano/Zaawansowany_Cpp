//
// Created by Arek on 07.05.2023.
//
#include "Funktory_1-4.h"
#include "iostream"

int main() {
    double result = integrate(1./sin(Variable() + 1.), 0, 1, 0.001);
    std::cout << "Result: " << result << std::endl;
    return 0;
}