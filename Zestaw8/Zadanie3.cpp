//
// Created by Arek on 07.05.2023.
//

#include "Funktory_1-4.h"
#include <iostream>

int main() {
    Variable x;

    std::cout << "Wynik calkowania: " << integrate(x + 1.,0,1,0.001)<< std::endl;

    return 0;
}
