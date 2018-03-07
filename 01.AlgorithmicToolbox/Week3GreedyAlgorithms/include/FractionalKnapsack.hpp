#ifndef FRACTIONAL_KNAPSACK
#define FRACTIONAL_KNAPSACK

#include <vector>
#include <algorithm>

namespace GreedyAlgorithms {

    struct Item {
        unsigned value;
        unsigned weight;

        double getValueWeightRatio() const {
            return static_cast<double>(value) / static_cast<double>(weight);
        }
    
        bool operator <(const Item& rhs) const {
            return getValueWeightRatio() < rhs.getValueWeightRatio();
        }
    };

    double maxValueFractionalKnapsackHelper(unsigned capacity,
                                            std::vector<Item>& items) {
        double max_value = 0;
        while (!items.empty() && capacity > 0) {
            auto item = items.back();
            items.pop_back();
            if (item.weight < capacity) {
                capacity -= item.weight;
                max_value += item.value;
            } else {
                max_value += item.getValueWeightRatio() * capacity;
                break;
            }
        }
        return max_value;
    }
    
    double maxValueFractionalKnapsack(unsigned capacity,
                                      std::vector<Item> items) {
        std::sort(std::begin(items), std::end(items));
        return maxValueFractionalKnapsackHelper(capacity, items);
    }
                                                
}

#endif
