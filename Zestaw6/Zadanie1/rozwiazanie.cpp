//
// Created by Arek on 16.04.2023.
//

//
// Created by Arek on 15.04.2023.
//

#include <iostream>
using std::cin;
using std::cout;

#include "fab_kol.h"
#include "polityka.h"

int main()
{
    FabrykaKolorow<Default_Color_Policy<0,0,0>> fabryka;
    try {
        fabryka.zwrocKolor("zielony").rgb();
        fabryka.zwrocKolor("green").rgb();
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }
    FabrykaKolorow<> fabryka_wyjatek;
    try {
        fabryka_wyjatek.zwrocKolor("zielony").rgb();
        fabryka_wyjatek.zwrocKolor("green").rgb();
    } catch(std::range_error) {
        cout << "Zlapano wyjatek.\n";
    }

    return 0;
}

