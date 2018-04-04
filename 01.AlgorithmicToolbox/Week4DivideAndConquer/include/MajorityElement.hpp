#ifndef MAJORITY_ELEMENT_HPP
#define MAJORITY_ELEMENT_HPP

#include <vector>
#include <algorithm>

namespace DivideAndConquer {

    int getCount(const std::vector<int>& sequence, int key,
                 std::size_t start, std::size_t end) {
        return std::count(sequence.begin() + start, sequence.begin() + end, key);
    }

    int getMajorityElementHelper(const std::vector<int>& sequence,
                                 std::size_t start, std::size_t end) {
        if ((end - start) < 1) return -1;
        if ((end - start) == 1) return sequence[start];
        auto mid_index = start + (end - start) / 2;
        int majority_count_min = ((end - start) / 2) + 1;
        auto left_majority = getMajorityElementHelper(sequence, start, mid_index);
        auto right_majority = getMajorityElementHelper(sequence, mid_index, end);
        if (left_majority != -1 &&
            getCount(sequence, left_majority, start, end) >= majority_count_min) {
            return left_majority;
        } else if (right_majority != -1 &&
                   getCount(sequence, right_majority, start, end) >= majority_count_min) {
            return right_majority;
        } else {
            return -1;
        }
    }

    int getMajorityElement(const std::vector<int>& sequence) {
        return getMajorityElementHelper(sequence, 0, sequence.size());
    }
}

#endif
