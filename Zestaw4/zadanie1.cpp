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
};
template <>
struct sum_traits<int> {
    typedef long int sum_type;
};
template <>
struct sum_traits<float> {
    typedef float sum_type;
};
template <>
struct sum_traits<double> {
    typedef double sum_type;
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *begin, T *end){
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type();
    while( begin != end) {
        total += *begin;
        begin++;
    }

    return total;
}


int main(){

    char string[] = "abcdefgh";
    auto length_of_string = strlen(string);
    std::cout<< sum(string, &string[length_of_string]) << std::endl;


    int nums[] = {1, 2, 3, 4};
    std::cout<< sum(nums, &nums[4]) << std::endl;

    double nums_double[] = {1.0, 2.0, 3.0, 4.0};
    std::cout<< sum(nums_double, &nums_double[4]) << std::endl;

    float nums_float[] = {1.0f, 2.0f, 3.0f, 4.0f};
    std::cout<< sum(nums_float, &nums_float[4]) << std::endl;


    return 0;
}
