//
// Created by Arek on 22.05.2023.
//

/*
 * Execution policy wprowadzona w C++17 pozwala na kontrolę sposobu wykonania algorytów równoległych.
 * Można wykorzystywać go z takimi funkcjami jak `std::for_each`, `std::transform`, `std::sort` aby określić
 * w jaki sposób mają być wykonywane operacje na elementach kontenera.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <thread>


/*
 * std::execution::sequence_policy
 *
 * Polityka która wymusza sekwencyjne wykonanie algorytmu. Będą się wykonywać zawsze w ustalonej kolejności.
 * Jest to domyślna polityka wykonania.
 */

void performAlgorithm(const std::execution::sequenced_policy& policy) {
    std::vector<int> numbers(1000000, 1);

    auto start = std::chrono::high_resolution_clock::now();

    std::for_each(policy, numbers.begin(), numbers.end(), [](int& num) {
        for (int i = 0; i < 1000; ++i) {
            num += i;
        }
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

/*
 * std::execution::parallel_policy:
 *
 * Ta polityka wykonania pozwala na równoległe wykonanie algorytmu, jeśli to możliwe.
 * Oznacza to, że operacje mogą być wykonywane jednocześnie przez wiele wątków, co może przyspieszyć wykonanie.
 */

void performAlgorithm(const std::execution::parallel_policy& policy) {
    std::vector<int> numbers(1000000, 1);

    auto start = std::chrono::high_resolution_clock::now();

    std::for_each(policy, numbers.begin(), numbers.end(), [](int& num) {
        for (int i = 0; i < 1000; ++i) {
            num += i;
        }
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

/*
 * std::execution::parallel_unsequenced_policy:
 * Ta polityka wykonania pozwala na równoległe wykonanie operacji i nie wymaga zachowania ustalonej kolejności.
 * Oznacza to, że kolejność operacji na elementach może być dowolna, a wynik może być niejednoznaczny.
 */

void performAlgorithm(const std::execution::parallel_unsequenced_policy& policy) {
    std::vector<int> numbers(1000000, 1);

    auto start = std::chrono::high_resolution_clock::now();

    std::for_each(policy, numbers.begin(), numbers.end(), [](int& num) {
        for (int i = 0; i < 1000; ++i) {
            num += i;
        }
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

int main() {
    std::cout << "std::execution::sequenced_policy:\n";
    performAlgorithm(std::execution::sequenced_policy{});

    std::cout << "std::execution::parallel_policy:\n";
    performAlgorithm(std::execution::parallel_policy{});

    std::cout << "std::execution::parallel_unsequenced_policy:\n";
    performAlgorithm(std::execution::parallel_unsequenced_policy{});

    return 0;
}