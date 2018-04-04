#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>
#include <iostream>

namespace DynamicProgramming {
    unsigned optimalWeight(unsigned max_weight, const std::vector<unsigned>& weights) {
        auto weight_table =
            std::vector< std::vector<unsigned> >
            (weights.size()+1, std::vector<unsigned>(max_weight+1, 0));
        for (std::size_t item = 1; item <= weights.size(); ++item) {
            auto item_weight = weights[item-1];
            for (std::size_t weight = 1; weight <= max_weight; ++weight) {
                // don't choose item
                weight_table[item][weight] = weight_table[item-1][weight];
                // choose item
                if (item_weight <= weight) {
                    auto weight_if_choose = item_weight +
                        weight_table[item-1][weight-item_weight];
                    if (weight_if_choose > weight_table[item][weight]) {
                        weight_table[item][weight] = weight_if_choose;
                    }
                }
            }
        }
        return weight_table[weights.size()][max_weight];
    }
}

#endif
