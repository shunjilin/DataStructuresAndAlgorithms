#include <iostream>
#include <vector>
#include "UniformRandom.hpp"
#include "Knapsack.hpp"

// recursive
unsigned optimalWeight(unsigned max_weight, std::vector<unsigned> weights) {
    if (max_weight == 0 || weights.size() == 0) return 0;
    auto weight = weights.back();
    weights.pop_back();
    unsigned choose = (weight <= max_weight) ?
        weight + optimalWeight(max_weight - weight, weights) :
        0;
    unsigned dont_choose = optimalWeight(max_weight, weights);
    return std::max(choose, dont_choose);
}


int main()
{
    UniformRandom<unsigned> weight_rng(0, 100);
    UniformRandom<unsigned> n_weights_rng(0, 2);

    for (int trials = 0; trials < 1000; ++trials) {
        std::vector<unsigned> weights(n_weights_rng.generate());
        for (std::size_t i = 0; i < weights.size(); ++i) {
            weights[i] = weight_rng.generate();
        }
        unsigned max_weight = weight_rng.generate();
        auto expected_optimal_weight = optimalWeight(max_weight, weights);
        auto actual_optimal_weight = DynamicProgramming::optimalWeight(max_weight, weights);
        if (expected_optimal_weight == actual_optimal_weight) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n"
                      << "Max weight: " << max_weight
                      << "\nWeights: ";
            for (auto weight : weights) {
                std::cout << weight << " ";
            }
            std::cout << "\nExpected optimal weight : " << expected_optimal_weight
                      << "\nActual optimal weight : " << actual_optimal_weight
                      << "\n";
            return 0;
        }
    }
}
