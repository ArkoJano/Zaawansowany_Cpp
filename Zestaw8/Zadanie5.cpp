//
// Created by Arek on 07.05.2023.
//
#include <iostream>
#include "Funktory_5-.h"

int main() {

    Expr<float,Variable<float> > x{};
    std::cout << integrate(x + float(1.0), 0, 1, 0.001) << std::endl;

    Expr<int,Variable<int> > y{};
    std::cout << integrate(y + 1, 0, 1, 0.001) << std::endl;

    return 0;
}