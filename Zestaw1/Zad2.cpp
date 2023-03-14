//
// Created by Arko on 05.03.2023.
//
#include "iostream"

template <typename T, typename Y> T convert(Y arg_to_convert){
    return (T) arg_to_convert;
}

int main(){
    std::cout<< convert<int>('2')<<std::endl;
    std::cout<< convert<double>(3)<<std::endl;
    std::cout<< convert<int>(3.4)<<std::endl;
    std::cout<< convert<char>(97)<<std::endl;

}
