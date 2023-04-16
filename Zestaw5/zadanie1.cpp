//
// Created by Arek on 03.04.2023.
//

#include <iostream>



template<typename T> class is_class {
    template<typename U> static char test(int U::*);
    template<typename U> static int test(...);
public:

    static const bool value = (sizeof(test<T>(0)) == sizeof(char));

};

class MyClass {};

int main() {
    std::cout << std::boolalpha;
    std::cout << is_class<MyClass>::value << std::endl;
    std::cout << is_class<int>::value << std::endl;
    return 0;
}