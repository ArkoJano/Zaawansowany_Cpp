//
// Created by Arko on 05.03.2023.
//
#include<iostream>

template<
    template <int N> class C,       // ten szablon klasy (która zawiera argument int) jest argumentem
            int K>                  // a to zwykły argument int
    void f(C<K>){                   // tutaj mamy funkcję która za argument przyjmuje tego inta którego podajmey
        std::cout<<K<<std::endl;    // wypisujemy go
    };

template<int N> class SomeClass {};

int main() {
    SomeClass<1>  c1;
    SomeClass<2>  c2;

    f(c1);
    f(c2);
}