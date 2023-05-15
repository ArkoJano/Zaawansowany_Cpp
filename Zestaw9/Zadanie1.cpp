//
// Created by Arek on 15.05.2023.
//

#include <iostream>
#include <memory>




int main() {

    std::shared_ptr<int> ptr1(new int(5));
    std::cout << *ptr1 << std::endl;

    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << *ptr2 << std::endl;

    std::shared_ptr<int> ptr3 = ptr1;
    std::cout << *ptr3 << std::endl;

    ptr1.reset();

    std::unique_ptr<int> ptr4(new int(5));
    std::cout << *ptr4 << std::endl; // wydrukuje 5

    // std::unique_ptr<int> ptr5(ptr4); // ten kod się nie skompiluje, ponieważ unique_ptr nie może być kopiowany
    std::unique_ptr<int> ptr5(std::move(ptr4)); // wywołanie std::move jest potrzebne, ponieważ unique_ptr nie ma konstruktora kopiującego
    std::cout << *ptr5 << std::endl; // wydrukuje 5

    // std::unique_ptr<int> ptr6 = ptr4; // ten kod się nie skompiluje, ponieważ unique_ptr nie może być kopiowany
    std::unique_ptr<int> ptr6 = std::move(ptr5); // wywołanie std::move jest potrzebne, ponieważ unique_ptr nie ma konstruktora kopiującego
    std::cout << *ptr6 << std::endl; // wydrukuje 5
    // std::cout << *ptr4 << std::endl; // ten kod spowoduje błąd wykonania, ponieważ ptr2 jest już nieważny


}
