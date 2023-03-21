//
// Created by Arek on 19.03.2023.
//

// Zaimplementować szablon klasy Stack wraz z jej specjalizacjami tak aby „działała” ze zwykłymi tablicami oraz kontenerami.
#include "iostream"
#include "vector"

template <typename T, int N, typename R = T*> class Stack;

template <typename T, int N> class Stack<T, N, T*> {
private:
    T data[N];
    int top;
public:
    Stack(): top(-1) {
        std::cout <<"Stack for array created!"<<std::endl;
    };
    void push(T x) {
        if (top < N - 1){
            data[++top] = x;
        } else {
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

template<typename T,int N,template<typename E> class Sequence>
class Stack<T,N,Sequence<T> > {
    Sequence<T> _rep;
public:
    void push(T e) {_rep.push_back(e);};
    T pop() {T top = _rep.top();_rep.pop_back();return top;}
    bool is_empty() const {return _rep.empty();}
};
//
//template <typename T, int N, typename E> class Stack{
//private:
//    E data;
//public:
//    Stack(){
//        std::cout <<"Stack for containers created!"<<std::endl;
//    };
//    void push(T x) {
//        if (data.size() < N - 1){
//            data.push_back(x);
//        } else {
//            std::cerr << "Stack overflow\n";
//        }
//    }
//
//    T pop() {
//        if (!data.empty()) {
//            return data.pop_back();
//        }
//        else {
//            std::cerr << "Stack underflow\n";
//            return T();
//        }
//    }
//    bool is_empty(){
//        return data.empty() ;
//    }
//};


int main(){
    Stack<int,100,int *>            s_table;
    Stack<int,100>                  s_default ;
    Stack<int,10,std::vector<int> >  s_container;

}

