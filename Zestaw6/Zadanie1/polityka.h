//
// Created by Arek on 16.04.2023.
//

#ifndef ZAAWANSOWANY_CPP_POLITYKA_H
#define ZAAWANSOWANY_CPP_POLITYKA_H
#include <cstdio>
#include <iostream>
#include "kolor.h"

template<int red = 0, int green = 0, int blue = 0>
struct Default_Color_Policy {
    static Kolor perform() {
        return Kolor(red, green, blue);
    }
};

struct Exception_Policy {
    static Kolor perform() {
        throw std::range_error("color does not exist");
    }
};

#endif //ZAAWANSOWANY_CPP_POLITYKA_H
