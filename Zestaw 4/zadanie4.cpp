//
// Created by Arek on 27.03.2023.
//
#include "iostream"
#include "vector"

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

template<typename IT>
typename sum_traits<typename std::iterator_traits<IT>::value_type>::sum_type sum(IT beg, IT end) {

    typedef typename std::iterator_traits<IT>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;

    sum_type total = sum_traits<value_type>::zero();
    while (beg != end) {
        total += *beg;
        beg++;
    }

    return total;
}

int main(){

   std::vector<double> v = {1.2 , 2.3, 3.4, 4.5};
   std::cout<< sum(v.begin(), v.end()) <<std::endl;

    return 0;
}