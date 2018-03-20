#include <iostream>
#include <vector>
#include <algorithm>
#include "UniformRandom.hpp"
#include "BinarySearch.hpp"

using namespace DivideAndConquer;

int main(int argc, char *argv[])
{
    UniformRandom<unsigned> length_generator(0, pow(10, 4));
    UniformRandom<int> key_generator(0, pow(10, 9));

    for (int i = 0; i < 10000; ++i) {
        std::vector<int> sequence(length_generator.generate());
        std::generate(sequence.begin(), sequence.end(), [&]() {
                return key_generator.generate();
            }
            );
        sequence.erase(std::unique(sequence.begin(), sequence.end()),
                       sequence.end());
        std::sort(sequence.begin(), sequence.end());
        for (int j = 0; j < 10000; ++j) {
            auto key_to_find = key_generator.generate();
            auto actual = binarySearch(sequence, key_to_find);
            auto found = std::binary_search(sequence.begin(), sequence.end(),
                                            key_to_find);
            if (!found && actual == -1 || found && key_to_find == sequence[actual]) {
                std::cout << "OK\n";
            } else {
                std::cout << "WRONG\n";
                return 0;
            }
        }
    }
}
