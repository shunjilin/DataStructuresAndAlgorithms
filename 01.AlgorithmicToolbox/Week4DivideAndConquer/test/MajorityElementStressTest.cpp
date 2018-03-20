#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "MajorityElement.hpp"
#include "UniformRandom.hpp"

int getMajorityElementNaive(const std::vector<int>& sequence) {
    auto key_count = std::unordered_map<int, int>();
    for (auto key : sequence) {
        ++key_count[key];
    }
    auto min_majority_count = (sequence.size() / 2) + 1;
    for (auto key_count_pair : key_count) {
        if (key_count_pair.second >= min_majority_count)
            return key_count_pair.first;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    UniformRandom<unsigned> length_generator(0, 5);
    UniformRandom<int> key_generator(0, 1); // likely majority
    //UniformRandom<int> key_generator(0, pow(10, 4)); // unlikely majority
    for (int i = 0; i < 10000; ++i) {
        std::vector<int> sequence(length_generator.generate());
        std::generate(sequence.begin(), sequence.end(), [&]() {
                return key_generator.generate();
            }
            );
        auto expected = getMajorityElementNaive(sequence);
        auto actual = DivideAndConquer::getMajorityElement(sequence);
        if (expected == actual) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            std::cout << "Expected majority: " << expected
                      << "; Actual majority: " << actual << "\n Sequence: ";
            for (auto key : sequence) {
                std::cout << key << " ";
            }
            std::cout << "\n";
            return 0;
        }
    }
}
