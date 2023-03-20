//
// Created by Arek on 16.03.2023.
//

// W przeciwieństwie do szablonów funkcji, szablony klas nie mogą być przeciążane, a jedynie specjalizowane.
//  Oznacza to, że w programie może istnieć tylko jeden szablon podstawowy o danej nazwie.
//  Proszę zaimplementować specjalizację częściową, która jest dozwolona tylko dla szablonów
//  klas, dla podanych podzbiorów parametrów:
//
// Stack<T,666>
// Stack<T*,N>
// Stack<double ,N>
// Stack<int *,N>
// Stack<double,666>
// Stack<double *,44>

#include <iostream>

template <typename T, int N>
class Stack {
    T data[N];
    int top = -1;
public:
    Stack(){
        std::cout<<"<T, N>"<<std::endl;
    }
    void push(T x) {
        if (top < N - 1) {
            data[++top] = x;
        }
        else {
            std::cerr << "Stack overflow\n";
        }
    }
    T pop() {
        if (top >= 0) {
            return data[top--];
        }
        else {
            std::cerr << "Stack underflow\n";
            return T();
        }
    }
    bool is_empty() const {
        return top < 0;
    }
};

template <typename T>
class Stack<T, 666> {
    T data[666];
    int top = -1;
public:
    Stack(){
        std::cout<<"<T, 666>"<<std::endl;
    }
    void push(T x) {
        if (top < 665) {
            data[++top] = x;
        }
        else {
            std::cerr << "Stack overflow\n";
        }
    }
    T pop() {
        if (top >= 0) {
            return data[top--];
        }
        else {
            std::cerr << "Stack underflow\n";
            return T();
        }
    }
    bool is_empty() const {
        return top < 0;
    }
};

template <typename T, int N>
class Stack<T*, N> {
    T* data[N];
    int top = -1;
public:
    Stack(){
        std::cout<<"<T*, N>"<<std::endl;
    }
    void push(T* x) {
        if (top < N - 1) {
            data[++top] = x;
        }
        else {
            std::cerr << "Stack overflow\n";
        }
    }
    T* pop() {
        if (top >= 0) {
            return data[top--];
        }
        else {
            std::cerr << "Stack underflow\n";
            return nullptr;
        }
    }
    bool is_empty() const {
        return top < 0;
    }
};

template <int N>
class Stack<double, N> {
    double data[N];
    int top = -1;
public:
    Stack(){
        std::cout<<"<double, N>"<<std::endl;
    }
    void push(double x) {
        if (top < N - 1) {
            data[++top] = x;
        }
        else {
            std::cerr << "Stack overflow\n";
        }
    }
    double pop() {
        if (top >= 0) {
            return data[top--];
        }
        else {
            std::cerr << "Stack underflow\n";
            return 0.0;
        }
    }
    bool is_empty() const {
        return top < 0;
    }
};

template <int N>
class Stack<int*, N> {
    int* data[N];
    int top = -1;
public:
    Stack(){
        std::cout<<"<int*, N>"<<std::endl;
    }
    void push(int* x) {
        if (top < N - 1) {
            data[++top] = x;
        }
        else {
            std::cerr << "Stack overflow\n";
        }
    }
    int* pop() {
        if (top >= 0) {
            return data[top--];
        }
        else {
            std::cerr << "Stack underflow\n";
            return nullptr;
        }
    }
    bool is_empty() const {
        return top < 0;
    }
};

template <>
class Stack<double,666>{
private:
    double data[666];
    int top = -1;
public:
    Stack(){
        std::cout<<"<double, 666>"<<std::endl;
    }
    void push(double x){
        if (top < 665) {
            data[++top] = x;
        }
    }
    double pop(){
        if (top >= 0){
            return data[top--];
        } else {
            std::cerr << "Stack underflow\n";
            return 0.0;
        }
    }

    bool is_empty() {
        return top < 0;
    }
    };

template<>
class Stack<double *,44>{
private:
    double* data[44];
    int top = -1;
public:
    Stack(){
        std::cout<<"<double*, 44>"<<std::endl;
    }
    void push(double* x){
        if (top < 43){
            data[++top] = x;
        } else {
            std::cerr << "Stack overflow\n";
        }
    }
    double* pop() {
        if (top >= 0) {
            return data[top--];
        }
        else {
            std::cerr << "Stack underflow\n";
            return nullptr;
        }
    }
    bool is_empty() const {
        return top < 0;
    }
};

int main(){
    Stack<int,20>      s0;
    Stack<int,666>     s1;
    Stack<double *,30> s2;
    Stack<double ,30>  s3;
    Stack<double *,44> s4;
    Stack<int *,20>    s5;
    Stack<double,666>  s6;


}
