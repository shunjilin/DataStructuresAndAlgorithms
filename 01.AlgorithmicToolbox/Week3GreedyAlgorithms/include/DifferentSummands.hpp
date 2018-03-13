#ifndef DIFFERENT_SUMMANDS_HPP
#define DIFFERENT_SUMMANDS_HPP

#include <set>

namespace GreedyAlgorithms {
    std::set<unsigned> maxDifferentSummands(unsigned sum) {
        auto summands = std::set<unsigned>();
        unsigned summand = 1;
        while (sum > 0) {
            unsigned remainder = sum - summand;
            if (remainder <= summand) {
                summands.insert(sum);
                return summands;
            }
            sum -= summand;
            summands.insert(summand);
            ++summand;
        }
        return summands;
    }
}

#endif
