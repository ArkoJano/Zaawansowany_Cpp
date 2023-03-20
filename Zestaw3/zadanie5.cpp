//
// Created by Arek on 20.03.2023.
//
//
// Zapoznaj się z rodziną funktorów porównujących, do której należą np.
//  less<>(),
//  greater<>(),
//  less_equal<>(),
//  greater_equal<>()
// Przypomnij sobie pojemnik std::set.
// Następnie napisz programik korzystający ze zbioru liczb posortowanego odwrotnie (czyli malejąco).

#include "iostream"
#include "set"

int main(){
    std::set<int, std::greater<>> my_set;

    my_set.insert(1);
    my_set.insert(2);
    my_set.insert(3);
    my_set.insert(4);

    for( auto x : my_set) {
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
}