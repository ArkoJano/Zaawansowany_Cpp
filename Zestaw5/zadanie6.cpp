//
// Created by Arek on 03.04.2023.
//

#include <iostream>
#include "zadanie6.h"

int main() {

    // Tworzenie listy typów
    using TL = TypeList<int, TypeList<double, TypeList<char, Null_type>>>;

    // Pobieranie typu na danym indeksie
    using T1 = At<1, TL>::Result;
    using T2 = At2<2, TL>::Result;
    std::cout << "At<1, TL>::Result = " << typeid(T1).name() << std::endl;
    std::cout << "At2<2, TL>::Result = " << typeid(T2).name() << std::endl;

    // Sprawdzenie, czy typ jest w liście
    std::cout << "In<int, TL>::yes = " << In<int, TL>::yes << std::endl; // 1
    std::cout << "In<float, TL>::yes = " << In<float, TL>::yes << std::endl; // 0

    return 0;
}