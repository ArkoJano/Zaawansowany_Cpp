//
// Created by Arko on 13.03.2023.
//

// Zaimplementuj klasę (funktor typu generator) SeqenceGen przy wykorzystaniu
// której wypełnij, za pomocą algorytmu generate_n, wektor sekwencją 20
// pierwszych nieparzystych liczb całkowitych. Znajdź element większy od 4
// przy wykorzystaniu adaptera bind2nd oraz algorytmu find_if.

#include<iostream>
#include<vector>
#include<functional>

template<typename T>
class SequenceGen {
private:
    T _start;
    T _step;
public:
    SequenceGen(T start = T(), T step = 1) : _start(start), _step(step) {};
    T operator()() {
        T tmp = _start;
        _start += _step;
        return tmp;
    }
};

const size_t n = 20;

int main() {
    std::vector<int> v(n);
    generate_n(v.begin(), n, SequenceGen<int>(1, 2));
    auto it = std::find_if(
            v.begin(),
            v.end(),
            std::bind(std::greater<int>(), std::placeholders::_1, 4)
    );
    std::cout << *it << std::endl;

    return 0;
}