//
// Created by Arek on 16.04.2023.
//

#ifndef ZAAWANSOWANY_CPP_KOLOR_H
#define ZAAWANSOWANY_CPP_KOLOR_H

class Kolor {
public:
    Kolor() {
        red = 0;
        green = 0;
        blue = 0;
    }
    Kolor(int _red, int _green, int _blue) : red(_red), green(_green), blue(_blue) {};
    void rgb() const {
        std::cout << "(" << red << "," << green << "," << blue << ")" << std::endl;
    }
private:
    int red;
    int green;
    int blue;
};

#endif //ZAAWANSOWANY_CPP_KOLOR_H
