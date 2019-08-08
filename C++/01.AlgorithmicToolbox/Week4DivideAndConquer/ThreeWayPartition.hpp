#ifndef THREE_WAY_PARTITION_HPP
#define THREE_WAY_PARTITION_HPP

#include <vector>
#include <limits>
#include <algorithm>
#include "UniformRandom.hpp"

namespace DivideAndConquer {

    // returns start and end indexes of equal segment
    std::pair<std::size_t, std::size_t>
    threeWayPartition(std::vector<int>& sequence,
                      std::size_t start, std::size_t end) {
        auto less_end = start + 1, equal_end = start + 1, more_end = start + 1;
        auto pivot = sequence[start];
        using std::swap;
        while (more_end < end) {
            if (sequence[more_end] <= pivot) {
                swap(sequence[more_end++], sequence[equal_end]);
                if (sequence[equal_end] < pivot) {
                    swap(sequence[equal_end], sequence[less_end++]);
                }
                ++equal_end;
            } else {
                ++more_end;
            }
        }
        swap(sequence[start], sequence[--less_end]);
        return std::make_pair(less_end, equal_end);
    }

    void randomizedQuickSortHelper(std::vector<int>& sequence,
                                   std::size_t start, std::size_t end,
                                   UniformRandom<std::size_t>& pivot_index_gen) {
        while (start < end) {
            if (end - start <= 1) return;
            auto pivot_index = start + pivot_index_gen.generate() % (end - start);
            using std::swap;
            swap(sequence[start], sequence[pivot_index]);
            auto pivot_start_end = threeWayPartition(sequence, start, end);
            randomizedQuickSortHelper(sequence, start, pivot_start_end.first,
                                      pivot_index_gen);
            start = pivot_start_end.second;
        }
    }

    void randomizedQuickSort(std::vector<int>& sequence) {
        UniformRandom<std::size_t>
            pivot_index_gen(0, std::numeric_limits<std::size_t>::max());;
        randomizedQuickSortHelper(sequence, 0, sequence.size(), pivot_index_gen);
    }
        
                             
}

#endif
