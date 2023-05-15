//
// Created by Arek on 15.05.2023.
//

#include <iostream>
#include <memory>

class Test {
public:
    static void hello() { std::cout << "hello" << std::endl; }
};

int main() {

    auto unique_smart = std::make_unique<Test>();
    auto shared_smart = std::make_shared<Test>();
    auto standard = new Test();

    std::cout << "size of unique smart: " << sizeof(unique_smart) << std::endl;
    std::cout << "size of shared smart: " << sizeof(shared_smart) << std::endl;
    std::cout << "size of standard: " << sizeof(standard) << std::endl;

    return 0;
}
