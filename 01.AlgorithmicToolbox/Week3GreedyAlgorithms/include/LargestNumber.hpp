#ifndef LARGEST_NUMBER_HPP
#define LARGEST_NUMBER_HPP
#include <string>
#include <vector>
#include <algorithm>

namespace GreedyAlgorithms {

    struct less_than_key
    {
        bool operator() (const std::string& first,
                         const std::string& second) const {
            if (first[0] == second[0]) {
                auto first_second = first + second;
                auto second_first = second + first;
                return first_second < second_first;
            } else {
                return first < second;
            }
        }
    };
    
    std::string LargestNumber(std::vector<std::string> digits) {
        std::sort(digits.rbegin(), digits.rend(), less_than_key());
        return accumulate(std::begin(digits), std::end(digits), std::string(""));
    }
}


#endif
