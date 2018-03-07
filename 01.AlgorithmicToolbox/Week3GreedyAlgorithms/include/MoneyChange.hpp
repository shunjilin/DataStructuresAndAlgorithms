#ifndef MONEY_CHANGE_HPP
#define MONEY_CHANGE_HPP

namespace GreedyAlgorithms {

    // minimum number of coins to make input value,
    // from coins 1, 5, 10
    unsigned minCoins(unsigned value) {
        unsigned min_coins = 0;
        min_coins += value / 10;
        value %= 10;
        min_coins += value / 5;
        value %= 5;
        min_coins += value;
        return min_coins;
    }
}

#endif
