//
// Created by Arek on 16.04.2023.
//

#ifndef ZAAWANSOWANY_CPP_FAB_KOL_H
#define ZAAWANSOWANY_CPP_FAB_KOL_H
#include "polityka.h"
template <typename Policy = Exception_Policy>
class FabrykaKolorow{
public:
    Kolor zwrocKolor(std::string color_name){
        if (color_name == "zielony"){
            return Kolor(0,0, 255);
        } else return Policy::perform();
    }

};

#endif //ZAAWANSOWANY_CPP_FAB_KOL_H
