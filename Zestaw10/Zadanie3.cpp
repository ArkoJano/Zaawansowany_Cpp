//
// Created by Arek on 22.05.2023.
//

#include <iostream>
#include <numeric>
#include <vector>
#include <execution>
#include <chrono>

/*
 * std::sort
 *
 * Sortuje elementy w kontenerze
 */

void sort(){

    std::cout<<"\n std::sort" << std::endl;

    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    auto start = std::chrono::high_resolution_clock::now();

    std::sort(std::execution::par, vec.begin(), vec.end());

    auto end = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();

    std::vector<int> vecSeq(10'000'000);
    std::iota(vecSeq.begin(), vecSeq.end(), 0);

    std::sort(std::execution::seq, vecSeq.begin(), vecSeq.end());

    end = std::chrono::high_resolution_clock::now();
    auto durationSequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);


    std::cout << "Czas przetwarzania dla polityki rownoleglej: " << durationParallel.count() << " ms\n";
    std::cout << "Czas przetwarzania dla polityki sekwencyjnej: " << durationSequential.count() << " ms\n";


}

/*
 * std::min_element
 *
 *  Zlicza wystąpienia określonej wartości w zadanym zakresie
 */

void min(){

    std::cout<<"\n std::min_element" << std::endl;

    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    auto start = std::chrono::high_resolution_clock::now();

    auto minParallel = std::min_element(std::execution::par, vec.begin(), vec.end());

    auto end = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();

    auto minSequential = std::min_element(std::execution::seq, vec.begin(), vec.end());

    end = std::chrono::high_resolution_clock::now();
    auto durationSequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Czas przetwarzania dla polityki rownoleglej: " << durationParallel.count() << " ms\n";
    std::cout << "Czas przetwarzania dla polityki sekwencyjnej: " << durationSequential.count() << " ms\n";

}

/*
 * std::partial_sort
 *
 * cząstkowo sortuje zakres, tak aby elementy na początku zakresu były posortowane, ale nie jest wymagane pełne posortowanie.
 */

void partial_sort(){

    std::cout<<"\n std::partial_sort" << std::endl;

    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    auto start = std::chrono::high_resolution_clock::now();

    std::partial_sort(std::execution::par, vec.begin(), vec.begin() + 5, vec.end());

    auto end = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();

    std::vector<int> vecSeq(vec.size());
    std::iota(vecSeq.begin(), vecSeq.end(), 0);

    std::partial_sort(std::execution::seq, vecSeq.begin(), vecSeq.begin() + 5, vecSeq.end());

    end = std::chrono::high_resolution_clock::now();
    auto durationSequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Czas przetwarzania dla polityki rownoleglej: " << durationParallel.count() << " ms\n";
    std::cout << "Czas przetwarzania dla polityki sekwencyjnej: " << durationSequential.count() << " ms\n";

}

/*
 * std::transform
 *
 * wykonuje operację na każdym elemencie z jednej sekwencji i zapisuje wyniki do innej sekwencji.
 */

void transform(){
    std::cout<<"\n std::transform" << std::endl;

    std::vector<int> input(10'000'000);
    std::iota(input.begin(), input.end(), 0);

    std::vector<int> output(input.size());

    auto start = std::chrono::high_resolution_clock::now();

    std::transform(std::execution::par, input.begin(), input.end(), output.begin(), [](int elem) {
        return elem * 2;  // Podwojenie wartości
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();

    std::vector<int> outputSeq(input.size());

    std::transform(std::execution::seq, input.begin(), input.end(), outputSeq.begin(), [](int elem) {
        return elem * 2;  // Podwojenie wartości
    });

    end = std::chrono::high_resolution_clock::now();
    auto durationSequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Czas przetwarzania dla polityki rownoleglej: " << durationParallel.count() << " ms\n";
    std::cout << "Czas przetwarzania dla polityki sekwencyjnej: " << durationSequential.count() << " ms\n";
}

/*
 * std::remove_if
 *
 * Usuwa elementy spełniające warunek
 */

void remove_if(){
    std::cout<<"\n std::remove_if" << std::endl;

    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    auto start = std::chrono::high_resolution_clock::now();

    auto newEnd = std::remove_if(std::execution::par, vec.begin(), vec.end(), [](int elem) {
        return elem % 2 == 0;  // Usuwanie parzystych elementów
    });

    vec.erase(newEnd, vec.end());

    auto end = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();

    std::vector<int> vecSeq(10'000'000);
    std::iota(vecSeq.begin(), vecSeq.end(), 0);

    newEnd = std::remove_if(std::execution::seq, vecSeq.begin(), vecSeq.end(), [](int elem) {
        return elem % 2 == 0;  // Usuwanie parzystych elementów
    });

    vecSeq.erase(newEnd, vecSeq.end());

    end = std::chrono::high_resolution_clock::now();
    auto durationSequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Czas przetwarzania dla polityki rownoleglej: " << durationParallel.count() << " ms\n";
    std::cout << "Czas przetwarzania dla polityki sekwencyjnej: " << durationSequential.count() << " ms\n";
}

int main(){
    sort();
    min();
    partial_sort();
    transform();
    remove_if();
}