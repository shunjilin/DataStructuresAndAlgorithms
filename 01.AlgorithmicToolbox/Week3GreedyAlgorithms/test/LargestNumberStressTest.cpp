#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "LargestNumber.hpp"
#include "UniformRandom.hpp"

using namespace GreedyAlgorithms;

std::string LargestNumberNaive(std::vector<std::string> digits) {
    std::sort(std::begin(digits), std::end(digits));
    auto max_number = std::accumulate(std::begin(digits), std::end(digits),
                                      std::string(""));
    while (std::next_permutation(std::begin(digits), std::end(digits))) {
        auto number = std::accumulate(std::begin(digits), std::end(digits),
                                      std::string(""));
        if (number > max_number) max_number = number;
    }
    return max_number;
}




int main(int argc, char *argv[])
{
    UniformRandom<unsigned> n_digits_rng(1, 10);
    UniformRandom<unsigned> digits_rng(1, 1000);

    for (unsigned i = 0; i < 100; ++i) {
        auto n_digits = n_digits_rng.generate();
        auto digits = std::vector<std::string>();
        for (unsigned j = 0; j < n_digits; ++j) {
            digits.push_back(std::to_string(digits_rng.generate()));
        }
        auto expected = LargestNumberNaive(digits);
        auto actual = LargestNumber(digits);
        if (expected == actual) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n"
                      << "Expected largest number: " << expected
                      << " Actual largest number: " << actual << "\n";
            std:: cout << "Digits are: \n";
            for (auto digit : digits) {
                std::cout << digit << " ";
            }
            std::cout << "\n";
            return 0;
        }
    }
    return 0;
}
