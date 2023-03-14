//
// Created by Arko on 05.03.2023.
//
#include "iostream"

template <typename T, int vector_lenght> T dot_product(T *vector1, T *vector2){
    T result = 0.0;
    for(int i=0; i<vector_lenght; i++){
        result += vector1[i] * vector2[i];
    }

    return result;
}

int main(){
    int vector1[] = {1, 2, 3};
    int vector2[] = {1, 2, 3};
    int result = dot_product<int, 3>(vector1, vector2);
    std::cout<<"result: "<<result<<std::endl;
}