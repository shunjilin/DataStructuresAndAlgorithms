#include <gmock/gmock.h>
#include "BuildMinHeap.hpp"

using namespace testing;

TEST(BuildHeap, correctLeftChildIndex) {
    ASSERT_EQ(getLeftChildIndex(5), 11);
}

TEST(BuildHeap, correctRightChildIndex) {
    ASSERT_EQ(getRightChildIndex(2), 6);
}

TEST(BuildHeap, correctSiftDown) {
    std::vector<int> input = {5, 3, 4};
    std::vector<SwapIndexPair> swap_pair_index;
    siftDown(input, 0, swap_pair_index);
    ASSERT_EQ(swap_pair_index[0], std::make_pair(0, 1));
}

TEST(BuildHeap, CorrectHeap) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    auto swaps = buildMinHeap(input);
    ASSERT_EQ(input, std::vector<int>({1, 2, 3, 5, 4}));
}

TEST(BuildHeap, CorrectNumberOfSwaps) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    auto swaps = buildMinHeap(input);
    ASSERT_EQ(swaps.size(), 3);
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
