//
// Created by Arko on 05.03.2023.
//

#include "iostream"

template<typename T>
class Stack {
public:
    static const size_t N = 100;
private:

    T _rep[N];
    size_t _top;

public:

    Stack() : _top(0) {};

    void push(T val) { _rep[_top++] = val; }

    T pop() { return _rep[--_top]; }

    bool is_empty() const { return (_top == 0); }

    typedef T type_value; // Służy do "zapisania" podanego typu elementów przechowywanych przez stos
};

template <typename T> auto sum_stack(T stack){
    typename T::type_value result = 0.0;
    while(!stack.is_empty()){
        result += stack.pop();
    }
    return result;
}


int main(){
    Stack<int> stos;
    for(int i=1; i<=10; i++){
        stos.push(i);
    }
    auto result = sum_stack(stos);
    std::cout<<result<<std::endl;
}