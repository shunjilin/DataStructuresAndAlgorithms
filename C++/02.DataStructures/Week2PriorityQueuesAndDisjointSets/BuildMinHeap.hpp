#ifndef BUILD_MIN_HEAP_HPP
#define BUILD_MIN_HEAP_HPP

#include <vector>
#include <utility>
#include <limits>

using SwapIndexPair = std::pair<int, int>;

size_t getLeftChildIndex(size_t parent_index) {
    return parent_index * 2 + 1;
}

size_t getRightChildIndex(size_t parent_index) {
    return getLeftChildIndex(parent_index) + 1;
}

// siftDown heap at index, recursively bubbling down if parent has value more
// than child node
// stores index swap pairs as part of input swap_pairs
void siftDown(std::vector<int>& input, size_t index,
              std::vector<SwapIndexPair>& swap_pairs) {
    auto input_size = input.size();
    auto left_child_index = getLeftChildIndex(index);
    auto right_child_index = getRightChildIndex(index);
    auto min_index = index;
    if (left_child_index < input_size &&
        input[left_child_index] < input[min_index]) {
        min_index = left_child_index;
    }
    if (right_child_index < input_size &&
        input[right_child_index] < input[min_index]) {
        min_index = right_child_index;
    }
    
    if (index != min_index) {
        std::swap(input[index], input[min_index]);
        swap_pairs.push_back(std::make_pair(index, min_index));
        siftDown(input, min_index, swap_pairs);
    }
}

// build min heap and return index swap pairs
std::vector<SwapIndexPair> buildMinHeap(std::vector<int>& input) {
    auto swapIndexPairs = std::vector<SwapIndexPair>();
    for (int i = (input.size() / 2) - 1; i >= 0; --i) {
        siftDown(input, i, swapIndexPairs);
    }
    return swapIndexPairs;
}

#endif
