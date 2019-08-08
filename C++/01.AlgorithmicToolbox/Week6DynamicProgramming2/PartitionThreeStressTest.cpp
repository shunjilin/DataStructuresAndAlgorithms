#include <iostream>
#include <vector>
#include <numeric>
#include "UniformRandom.hpp"
#include "PartitionThree.hpp"


bool partitionThreeHelper(unsigned subset1_capacity,
                          unsigned subset2_capacity,
                          std::vector<unsigned> weights) {
    if (subset1_capacity == 0 && subset2_capacity == 0) return true;
    if (weights.size() == 0) return false;
    auto weight = weights.back();
    weights.pop_back();
    if (partitionThreeHelper(subset1_capacity, subset2_capacity, weights))
        return true;
    if (weight <= subset1_capacity &&
        partitionThreeHelper(subset1_capacity - weight, subset2_capacity, weights))
        return true;
     if (weight <= subset2_capacity &&
        partitionThreeHelper(subset1_capacity, subset2_capacity - weight, weights))
         return true;
     return false;
}

// recursive
bool partitionThree(std::vector<unsigned> weights) {
    auto sum = std::accumulate(std::begin(weights), std::end(weights), 0);
    if (sum % 3 != 0) return false;
    auto partition = sum / 3;
    return partitionThreeHelper(partition, partition, weights);
}

int main()
{
    UniformRandom<unsigned> weight_rng(0, 100);
    UniformRandom<unsigned> n_weights_rng(0, 6);

    for (int trials = 0; trials < 10000; ++trials) {
        std::vector<unsigned> weights(n_weights_rng.generate());
        for (std::size_t i = 0; i < weights.size(); ++i) {
            weights[i] = weight_rng.generate();
        }
        auto expected = partitionThree(weights);
        auto actual = DynamicProgramming::partitionThree(weights);
        if (expected == actual) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            std::cout << "Expected : " << expected
                      << "\nActual : " << actual
                      << "\nWeights : ";
            for (auto weight : weights) {
                std::cout << weight << " ";
            }
            std::cout << "\n";
            return 0;
        }
    }
}
