#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include "UniformRandom.hpp"
#include "PrimitiveCalculator.hpp"

// recursive method with cache
unsigned getMinCalculatorOperations(unsigned value,
                                    std::unordered_map<unsigned, unsigned>& cache) {
    if (value == 1) return 0;
    
    auto subtract_one_it = cache.find(value -1);
    auto subtract_one = subtract_one_it != cache.end() ? subtract_one_it->second :
        getMinCalculatorOperations(value - 1, cache);
    auto min_operation = subtract_one + 1;
    if (value % 2 == 0) {
        auto divide_by_two_it = cache.find(value / 2);
        auto divide_by_two = divide_by_two_it != cache.end() ? divide_by_two_it->second :
            getMinCalculatorOperations(value / 2, cache);
        if (min_operation > (divide_by_two + 1)) min_operation = divide_by_two + 1;
    }
    if (value % 3 == 0) {
        auto divide_by_three_it = cache.find(value / 3);
        auto divide_by_three = divide_by_three_it != cache.end() ? divide_by_three_it->second :
            getMinCalculatorOperations(value / 2, cache);
        if (min_operation > (divide_by_three + 1)) min_operation = divide_by_three + 1;
    }
    cache[value] = min_operation;
    return min_operation;
}

int main(int argc, char *argv[])
{
    UniformRandom<unsigned> value_rng(1, 1000);

    for (int trials = 0; trials < 1000; ++trials) {
        auto value = value_rng.generate();
        auto cache = std::unordered_map<unsigned, unsigned>();
        auto expected_min_operations = getMinCalculatorOperations(value, cache);
        auto actual_min_operations = DynamicProgramming::getMinCalculatorOperations(value)[value];
         if (expected_min_operations == actual_min_operations) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            std::cout << "value : " << value << "\n"
                      << "expected minimum operations : " << expected_min_operations
                      << " actual minimum operations : " << actual_min_operations << "\n";
            return 0;
        }

    }
    
    
    return 0;
}
