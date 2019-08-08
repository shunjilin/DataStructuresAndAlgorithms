#ifndef PARTITION_THREE
#define PARTITION_THREE

#include <vector>
#include <numeric>

namespace DynamicProgramming {
    bool partitionThree(const std::vector<unsigned>& weights) {
        unsigned sum = std::accumulate(std::begin(weights), std::end(weights), 0);
        if (sum % 3 != 0) return false;
        auto partition = sum / 3;       
        auto partition_table =
            std::vector< std::vector< std::vector<unsigned > > >
            (weights.size()+1, std::vector< std::vector<unsigned> >
             (partition+1, std::vector<unsigned>
              (partition+1, false)));
        for (std::size_t item = 0; item <= weights.size(); ++item) {
            partition_table[item][0][0] = true;
        }
        for (std::size_t item = 1; item <= weights.size(); ++item) {
            auto item_weight = weights[item-1];
            for (unsigned sum1 = 0; sum1 <= partition; ++sum1) {
                for (unsigned sum2 = 0; sum2 <= partition; ++sum2) {
                    if (partition_table[item-1][sum1][sum2] || // dont choose item
                        (item_weight <= sum1 && 
                         partition_table[item-1][sum1-item_weight][sum2]) || // put item in subset 1
                        (item_weight <= sum2 &&
                         partition_table[item-1][sum1][sum2-item_weight])) // put item in subset 2
                        partition_table[item][sum1][sum2] = true;
                }
            }
        }
        return partition_table[weights.size()][partition][partition];
    }
}


#endif
