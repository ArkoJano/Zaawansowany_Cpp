//
// Created by Arek on 15.05.2023.
//
#include <iostream>
#include <memory>

class MyClass {
public:
    ~MyClass() {
        std::cout << "MyClass destructor called" << std::endl;
    }

    std::weak_ptr<MyClass> get_weak_ptr() {
        return weak_ptr_;
    }

    void set_weak_ptr(std::weak_ptr<MyClass> wp) {
        weak_ptr_ = wp;
    }

private:
    std::weak_ptr<MyClass> weak_ptr_;
};

int main() {
    std::shared_ptr<MyClass> ptr1(new MyClass);
    std::shared_ptr<MyClass> ptr2(new MyClass);
    ptr1->set_weak_ptr(ptr2->get_weak_ptr());
    ptr2->set_weak_ptr(ptr1->get_weak_ptr());
    std::cout << "Number of shared_ptrs pointing to MyClass: " << ptr1.use_count() << std::endl;
    std::cout << "Number of shared_ptrs pointing to MyClass: " << ptr2.use_count() << std::endl;
    return 0;
}
