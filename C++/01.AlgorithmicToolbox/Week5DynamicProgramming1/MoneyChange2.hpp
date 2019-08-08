#ifndef MONEY_CHANGE_2_HPP
#define MONEY_CHANGE_2_HPP
#include <vector>
#include <limits>

namespace DynamicProgramming {
    unsigned getMinCoins(const std::vector<unsigned>& coins, unsigned value) {
        std::vector<unsigned> min_coins(value + 1, std::numeric_limits<unsigned>::max());
        min_coins[0] = 0;
        for (std::size_t val = 1; val < min_coins.size(); ++val) {
            for (auto coin : coins) {
                if (coin <= val) {
                    unsigned temp_coins = min_coins[val - coin];
                    if (temp_coins != std::numeric_limits<unsigned>::max() &&
                        temp_coins + 1 < min_coins[val]) {
                        min_coins[val] = temp_coins + 1;
                    }
                }
            }
        }
        return min_coins[value];
    }
}

#endif
