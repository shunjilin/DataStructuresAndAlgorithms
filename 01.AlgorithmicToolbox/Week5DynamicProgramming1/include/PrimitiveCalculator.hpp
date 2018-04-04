#ifndef PRIMITIVE_CALCULATOR_HPP
#define PRIMITIVE_CALCULATOR_HPP

#include <vector>
#include <limits>
#include <algorithm>

namespace DynamicProgramming {

    bool divisibleByTwo(unsigned value) {
        return value % 2 == 0;
    }

    bool divisibleByThree(unsigned value) {
        return value % 3 == 0; 
    }

    std::vector<unsigned> getMinCalculatorOperations(unsigned value) {
        auto min_operations =
            std::vector<unsigned>(value + 1, std::numeric_limits<unsigned>::max());
        min_operations[1] = 0;
        for (unsigned val = 2; val <= value; ++val) {
            min_operations[val] = min_operations[val - 1] + 1; // add 1 operation
            if (divisibleByTwo(val)) {
                auto val_div_two = val / 2;
                if (min_operations[val_div_two] + 1 < min_operations[val])
                    min_operations[val] = min_operations[val_div_two] + 1;
            }
            if (divisibleByThree(val)) {
                auto val_div_three = val / 3;
                if (min_operations[val_div_three] + 1 < min_operations[val])
                    min_operations[val] = min_operations[val_div_three] + 1; 
            }
        }
        return min_operations;
    }

    std::vector<unsigned>
    getIntermediateResults(const std::vector<unsigned>& min_operations) {
        auto intermediate_results = std::vector<unsigned>();
        unsigned value = min_operations.size() - 1;
        while (value > 1) {
            intermediate_results.push_back(value);
            if (min_operations[value] == min_operations[value-1] + 1) {
                value = value - 1;
            } else if (divisibleByTwo(value) &&
                       min_operations[value] == min_operations[value/2] + 1) {
                value = value/2;
            } else if (divisibleByThree(value) &&
                       min_operations[value] == min_operations[value/3] + 1) {
                value = value/3;
            }
        }
        intermediate_results.push_back(1);
        std::reverse(std::begin(intermediate_results), std::end(intermediate_results));
        return intermediate_results;
                     
    }
}

#endif
