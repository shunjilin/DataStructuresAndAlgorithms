#ifndef MAX_DOT_PRODUCT_HPP
#define MAX_DOT_PRODUCT_HPP

#include <vector>
#include <algorithm>

namespace GreedyAlgorithms {

    // max dot product between two same sized arrays
    long long
    maxDotProduct(std::vector<int> list1, std::vector<int> list2) {
        std::sort(std::begin(list1), std::end(list1));
        std::sort(std::begin(list2), std::end(list2));
        long long max = 0;
        for (std::size_t i = 0; i < list1.size(); ++i) {
            max += static_cast<long long>(list1[i]) *
                static_cast<long long>(list2[i]);
        }
        return max;
    }
    
}

#endif
