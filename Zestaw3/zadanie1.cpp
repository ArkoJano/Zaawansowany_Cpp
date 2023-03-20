//
// Created by Arek on 16.03.2023.
//

// Podaj implementacje funkcji max dla różnego typu argumentów. Skorzystaj z możliwości przeciążania i specjalizacji szablonów funkcji
#include <iostream>
#include <cstring>

template<typename T> T max(T a, T b) {
    return (a > b) ? a : b;
}
template<typename T> T* max(T *a, T *b){
    return (*a > *b) ? a : b;
}
template<typename T> T max(T *data, size_t n){
    T max = data[0];
    for (size_t i=0; i<n; i++) if (data[i] > max) max = data[i];
    return max;
    }
template<> char* max<char *>(char* a,char* b){
    return (strcmp(a, b) > 0 ? a : b);
}
template<> const char* max(const char *a,const char *b){
    return (strcmp(a, b) > 0 ? a : b);
}
template<typename T> const T* max(T *a, const T* b){
    return (strcmp(a, b) > 0 ? a : b);
}

int main(){
    std::cout<< "====== template<typename T> T max(T a, T b) ======"<<std::endl;
    std::cout<< "max(5, 10) = "<< max(5, 10) <<std::endl;
    std::cout<< "max(22, 10) = "<< max(22, 10) <<std::endl;
    std::cout<< "max(2.2, 1.0) = "<< max(2.2, 1.0) <<std::endl;



    std::cout<< "====== template<typename T> T* max(T *a, T *b) ======"<<std::endl;
    int a = 10, b = 5;
    std::cout<<"a = " <<a<<"b = " << b << std::endl;
    std::cout<< "*max(&a, &b) = "<< *max(&a, &b) <<std::endl;
    int* c = new int(10);
    int* d = new int(5);
    std::cout<<"*c = " <<*c<<" *d = " << *d << std::endl;
    std::cout<< "*max(c, d) = "<< *max(c, d) <<std::endl;



    std::cout<< "====== template<typename T> T max(T *data, size_t n) ======"<<std::endl;
    int array[5] = {1, 2, 3, 4, 5};
    std::cout<< "max(array, 5) = "<< max(array, 5) <<std::endl;


    std::cout<< "====== template<> char* max<char *>(char *a,char *b) ======"<<std::endl;
    char first[] = "kot";
    char second[] = "pies";
    std::cout << "first = "<< first <<std::endl;
    std::cout << "second = "<< second <<std::endl;
    std::cout << "max(first, second) = " << max(first, second) <<std::endl;

    std::cout<< "====== template<> const char* max(const char *a,const char *b) ======"<<std::endl;
    std::cout << "max(\"first\", \"second\") = " << max("first", "second") <<std::endl;


    std::cout<< "====== template<typename T> const T* max(T *a, const T* b) ======"<<std::endl;
    std::cout << "first = "<< first <<std::endl;
    std::cout << "max(first, \"second\") = " << max(first, "second") <<std::endl;
}