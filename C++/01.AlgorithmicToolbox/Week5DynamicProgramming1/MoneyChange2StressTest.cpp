#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include "UniformRandom.hpp"
#include "MoneyChange2.hpp"


// recursive method with cache
unsigned getMinCoins(const std::vector<unsigned>& coins, unsigned value,
                     std::unordered_map<unsigned, unsigned>& cache) {
    if (value == 0) return 0;
    if (coins.size() == 0) return std::numeric_limits<unsigned>::max();
    unsigned min_coins = std::numeric_limits<unsigned>::max();
    for (auto coin : coins) {
        if (coin <= value) {
            auto cache_it = cache.find(value - coin);
            unsigned temp = 0;
            if (cache_it != cache.end()) {
                temp = cache_it->second;
            } else {
                temp = getMinCoins(coins, value - coin, cache);
            }
            if (temp != std::numeric_limits<unsigned>::max() &&
                temp + 1 < min_coins) min_coins = temp + 1;
        }
    }
    cache[value] = min_coins;
    return min_coins;
}

int main()
{
    UniformRandom<unsigned> n_coins_rng(1, 5);
    UniformRandom<unsigned> coin_value_rng(1, 50);

    for (int trials = 0; trials < 1000; ++trials) {
        std::vector<unsigned> coins(n_coins_rng.generate());
        std::generate(std::begin(coins), std::end(coins),
                      [&]() {
                          return coin_value_rng.generate();
                      });

    
        auto value = coin_value_rng.generate();
        std::unordered_map<unsigned, unsigned> cache;
        auto expected_min_coins =
            getMinCoins(coins, value, cache);
        
        auto actual_min_coins =
            DynamicProgramming::getMinCoins(coins, value);                                                                
        if (expected_min_coins == actual_min_coins) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            for (auto coin : coins) {
                std::cout << coin << " ";
            }
            std::cout << "\nvalue: " << value << "\n"
                      << "expected min coins: " << expected_min_coins
                      << "actual min coins: " << actual_min_coins
                      << "\n";
            return 0;
        }
    
    }
}
