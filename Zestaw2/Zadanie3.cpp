//
// Created by Arko on 13.03.2023.
//

// Zaimplementuj szablon funkcji accumulate, której pierwszy i drugi argument są
// iteratorami dowolnego kontenera STL. Funkcja ma za zadanie wyliczać sumę
// wszystkich elementów w przedziale podanych iteratorów.

#include<iostream>
#include<vector>
#include<list>


template <class Iterator, class T>
T accumulate(Iterator first, Iterator last, T init) {
    T total=init;
    while(first != last){
        total += *first;
        first++;
    }
    return total;
}

int main() {

    std::list<int> int_list;

    int_list.push_back(1);
    int_list.push_back(2);
    int_list.push_back(3);
    int_list.push_back(4);

    std::cout<<accumulate(int_list.begin(),int_list.end(),0)<<std::endl;

    std::vector<float> float_vector;

    float_vector.push_back(1.12);
    float_vector.push_back(4.23);
    float_vector.push_back(5.21);

    std::cout<<accumulate(float_vector.begin(),float_vector.end(),0.0)<<std::endl;

}