//
// Created by Arek on 03.04.2023.
//

#include<iostream>
#include<vector>
#include <cassert>


template<bool flag,typename T1,typename T2> struct If_then_else { // gdy flag true
    typedef T1 Result;
};

template<typename T1,typename T2>
struct If_then_else<false,T1,T2> {
    typedef T2 Result;
};


template<typename T1,typename T2> struct Promote {
    typedef typename
    If_then_else<(sizeof(T1) > sizeof(T2)),
            T1,
            typename If_then_else< (sizeof(T1)< sizeof(T2)),
                    T2,
                    void>::Result >::Result Result;
};

template<typename T> struct Promote<T,T> {
    typedef T Result;
};




#define MK_PROMOTION(T1,T2,Tr)             \
    template<> class Promote<T1, T2> {     \
      public:                              \
        typedef Tr ResultT;                \
    };                                     \
                                           \
    template<> class Promote<T2, T1> {     \
      public:                              \
        typedef Tr ResultT;                \
    };

MK_PROMOTION(bool, char, int)
MK_PROMOTION(bool, unsigned char, int)
MK_PROMOTION(bool, signed char, int)
MK_PROMOTION(unsigned char, signed char, int)


template<typename T> std::vector<T>
operator+(const std::vector<T>  &a,
          const std::vector<T>  &b) {


    assert(a.size()==b.size());

    std::vector<T> res(a);
    for(size_t i=0;i<a.size();++i)
        res[i]+=b[i];

    return res;
}



template<typename T,typename U>
std::vector<typename Promote<T,U>::Result>
operator+(const std::vector<T>  &a,
          const std::vector<U>  &b) {

    assert(a.size()==b.size());

    std::vector<typename Promote<T,U>::Result> res(a.size());
    for(size_t i=0;i<a.size();++i)
        res[i]=a[i]+b[i];

    return res;
}


int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    std::vector<double> v3 = {1.5, 2.5, 3.5};
    std::vector<double> v4 = {4.5, 5.5, 6.5};
    std::vector<bool> v5 = {true, false, true};
    std::vector<unsigned char> v6 = {'a', 'b', 'c'};
    std::vector<signed char> v7 = {'x', 'y', 'z'};

    // Przykład 1: Dodawanie dwóch wektorów typu int
    std::vector<int> result1 = v1 + v2;
    for (auto i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Przykład 2: Dodawanie dwóch wektorów typu double
    std::vector<double> result2 = v3 + v4;
    for (auto d : result2) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    // Przykład 3: Dodawanie dwóch wektorów różnych typów
    std::vector<double> result3 = v1 + v3;
    for (auto d : result3) {
        std::cout << d << " ";
    }
    std::cout << std::endl;


    return 0;
}