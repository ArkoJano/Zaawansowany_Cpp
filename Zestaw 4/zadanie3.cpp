//
// Created by Arek on 27.03.2023.
//

#include <iostream>
#include <cstring>

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char> {
    typedef int sum_type;
    static  sum_type zero() {return 0;}
};
template <>
struct sum_traits<int> {
    typedef long int sum_type;
    static  sum_type zero() {return 0;}
};
template <>
struct sum_traits<float> {
    typedef float sum_type;
    static  sum_type zero() {return 0.0f;}
};
template <>
struct sum_traits<double> {
    typedef double sum_type;
    static  sum_type zero() {return 0.0;}
};

template<typename Traits,typename T >
typename Traits::sum_type sum(T *beg,T *end) {
    typedef typename Traits::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while(beg != end ) {
        total += *beg; beg++;
    }
    return total;
};

template<typename T >
typename sum_traits<T>::sum_type sum(T *beg,T *end) {
    return sum<sum_traits<T>, T>(beg,end);
}


struct char_sum {
    typedef char sum_type;
};



int main(){

    char name[]="@ @ @";
    int length=strlen(name);

    std::cout<<(int)sum(name,&name[length])<<std::endl;

    std::cout<<(int)sum<char_sum>(name,&name[length])<<std::endl;

    std::cout<<(int)sum<char>(name,&name[length])<<std::endl;


    return 0;
}
