#ifndef MAX_PAIRWISE_PRODUCT_HPP
#define MAX_PAIRWISE_PRODUCT_HPP
#include <vector>
#include <utility>

namespace MPP {
    std::pair<unsigned long long, unsigned long long>
    getMaxPair(const std::vector<unsigned long long>& numbers) {
        unsigned long long max = 0, next_max = 0;
        for (auto number : numbers) {
            if (max < number) {
                next_max = max;
                max = number;
            } else if (next_max < number) {
                next_max = number;
            }
        }
        return std::make_pair(max, next_max);
    }
    
    unsigned long long
    maxPairwiseProduct(const std::vector<unsigned long long>& numbers) {
        auto max_pair = getMaxPair(numbers);
        return max_pair.first * max_pair.second;
    }
};

#endif
