#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <vector>

namespace DivideAndConquer {

    int binarySearchHelper(const std::vector<int>& sorted_list,
                     int key, std::size_t start, std::size_t end) {
        if (start >= end) return -1;
        auto mid_index = start + (end - start)/2;
        auto mid_key = sorted_list[mid_index];
        if (key == mid_key) {
            return mid_index;
        } else if (key < mid_key) {
            return binarySearchHelper(sorted_list, key, start, mid_index);
        } else {
            return binarySearchHelper(sorted_list, key, mid_index + 1, end);
        }
    }

    int binarySearch(const std::vector<int>& sorted_list, int key) {
        return binarySearchHelper(sorted_list, key, 0, sorted_list.size());
    }

}


#endif
