#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include "MaxDotProduct.hpp"
#include "UniformRandom.hpp"

using namespace GreedyAlgorithms;

long long
maxDotProductNaive(std::vector<int> list1,
                  std::vector<int> list2) {
    std::sort(std::begin(list2), std::end(list2));
    long long max = std::numeric_limits<long long>::lowest();
    do {
        long long value = 0;
        for (std::size_t i = 0; i < list2.size(); ++i) {
            value += static_cast<long long>(list1[i]) *
                static_cast<long long>(list2[i]);
        }
        if (value > max) max = value;
    } while (std::next_permutation(std::begin(list2),
                                   std::end(list2)));
    return max;
}

int main(int argc, char *argv[])
{
    int N = 5;
    UniformRandom<int> rng(-100000,
                           100000);

    std::vector<int> list1(N);
    std::vector<int> list2(N);

    for (int trials = 0; trials < 1000; ++trials) {
        for (int i = 0; i < N; ++i) {
            list1[i] = rng.generate();
            list2[i] = rng.generate();
        }
        auto expected = maxDotProductNaive(list1, list2);
        auto actual = maxDotProduct(list1, list2);
        if (expected == actual) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n"
                      << "Expected Max Revenue: " << expected
                      << " Actual Max Revenue: " << actual << "\n";
            return 0;
        }

    }
}
