//
// Created by Arko on 13.03.2023.
//

//Zaimplementuj krótki program w którym wykorzystany będzie polimorfizm dynamiczny oraz polimorfizm statyczny.

#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
public:
    Animal(std::string animal_name) : name(animal_name) {}
    virtual void hello() {}
};

class Cat : public Animal {
protected:
    std::string cat_name;
    int age;
public:
    Cat(std::string cat_name, int age) : Animal(cat_name), cat_name(cat_name), age(age) {}
    void hello() override {
        std::cout << "Hello! My name is "<< cat_name <<" and I'm "<<age<<" y.o. :)"<<std::endl;
    }
};

void call_hello_animals(Animal* animal_list[], int size){
    for (int i=0; i<size; i++){
        animal_list[i]->hello();
    }
}

class Helloable{
protected:
    std::string name;
public:
    Helloable(std::string name) : name(name) {};
    void hello(){
        std::cout<<"I'm helloable "<< name <<" class, not a animal :("<<std::endl;
    }
};

template <typename T> void call_helloable (T list_helloable[], int size){
    for (int i=0; i<size; i++){
        list_helloable[i]->hello();
    }
}

int main() {
    Cat cat1("Puszek", 5);
    Cat cat2("Tytus", 2);
    Cat cat3("Tadeusz", 3);
    Animal* animals[3] = {&cat1, &cat2, &cat3};
    std::cout<<"============= call_hello_animals - animals ============="<<std::endl;
    call_hello_animals(animals, 3);

    Helloable hello1("hello");
    Helloable hello2("hellno");
    Helloable hello3("hell no");
    Helloable* hello_list[3] = {&hello1, &hello2, &hello3};
    std::cout<<"============= call_helloable - hello_list ============="<<std::endl;
    call_helloable(hello_list, 3);
    std::cout<<"============= call_helloable - animals ============="<<std::endl;
    call_helloable(animals, 3);
    return 0;
}