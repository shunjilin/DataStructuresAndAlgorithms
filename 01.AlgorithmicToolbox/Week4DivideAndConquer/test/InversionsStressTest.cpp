#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>
#include "UniformRandom.hpp"
#include "Inversions.hpp"

using namespace DivideAndConquer;

//naive O(n^2) method
unsigned long long countInversions(const std::vector<int>& numbers) {
    unsigned long long inversion_count = 0;
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        for (auto j = i; j < numbers.size(); ++j) {
            if (numbers[j] < numbers[i]) ++inversion_count;
        }
    }
    return inversion_count;
}

int main() {
    UniformRandom<unsigned> vector_size_rng(0, 10000);
    UniformRandom<int> number_rng(-1000, 1000);

    for (int i = 0; i < 10000; ++i) {
        std::vector<int> numbers(vector_size_rng.generate());
        std::generate(std::begin(numbers), std::end(numbers),
                    std::bind(&UniformRandom<int>::generate, number_rng));

        auto expected = countInversions(numbers);
        auto actual = sortAndGetInversionCount(std::begin(numbers),
                                                          std::end(numbers));

        if (actual == expected) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            for (auto number : numbers) {
                std::cout << number << " ";
            }
            std::cout << "\n";
        }
        std::cout << "Expected: " << expected
                  << " Actual: " << actual << "\n";
        if (actual != expected) break;

    }
}
