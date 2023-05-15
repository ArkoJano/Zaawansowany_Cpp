#include <memory>
#include <iostream>

class MyClass {
public:
    ~MyClass() {
        std::cout << "MyClass destructor called" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> ptr1(new MyClass);
    {
        std::shared_ptr<MyClass> ptr2 = ptr1;
        std::shared_ptr<MyClass> ptr3 = ptr1;
        std::cout << "Number of shared_ptrs pointing to MyClass: " << ptr1.use_count() << std::endl;
    }
    std::cout << "Number of shared_ptrs pointing to MyClass: " << ptr1.use_count() << std::endl;
    return 0;
}
