#include <limits>
#include <iostream>
#include "UniformRandom.hpp"
#include "MoneyChange.hpp"

unsigned minCoinsNaive(unsigned value) {
    if (value == 0) return 0;
    unsigned min_coins = std::numeric_limits<unsigned>::max();
    if (value >= 10) {
        auto using_10 = 1 +  minCoinsNaive(value - 10);
        if (using_10 < min_coins) min_coins = using_10;
    }
    if (value >= 5) {
        auto using_5 = 1 + minCoinsNaive(value - 5);
        if (using_5 < min_coins) min_coins = using_5;
    }
    auto using_1 = value;
    if (using_1 < min_coins) min_coins = using_1;
    return min_coins;
}

int main(int argc, char *argv[])
{
    UniformRandom<unsigned> rng(0, 100);

    for (int i = 0; i < 10000; ++i) {
        auto value = rng.generate();
        auto expected = minCoinsNaive(value);
        auto actual = GreedyAlgorithms::minCoins(value);
        if (expected == actual) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n"
                      << "Value: " << value << "\n"
                      << "Min Coins (Expected): " << expected
                      << " Min Coins (Actual): " << actual << "\n";
            return 0;
        }

    }
}
