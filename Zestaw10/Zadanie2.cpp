//
// Created by Arek on 22.05.2023.
//

#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <chrono>
#include <iostream>

int main() {
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::mutex outputMutex;

    auto start = std::chrono::high_resolution_clock::now();

// Przetwarzanie z polityką std::execution::par
    std::for_each(std::execution::par, vec.begin(), vec.end(), [&output, &outputMutex](int &elem) {
        if (elem % 2 == 0) {
            std::lock_guard<std::mutex> lock(outputMutex);
            output.push_back(elem);
        }
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();

// Przetwarzanie z polityką std::execution::seq
    std::for_each(std::execution::seq, vec.begin(), vec.end(), [&output, &outputMutex](int &elem) {
        if (elem % 2 == 0) {
            std::lock_guard<std::mutex> lock(outputMutex);
            output.push_back(elem);
        }
    });

    end = std::chrono::high_resolution_clock::now();
    auto durationSequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Czas przetwarzania dla polityki rownoleglej: " << durationParallel.count() << " ms\n";
    std::cout << "Czas przetwarzania dla polityki sekwencyjnej: " << durationSequential.count() << " ms\n";
}