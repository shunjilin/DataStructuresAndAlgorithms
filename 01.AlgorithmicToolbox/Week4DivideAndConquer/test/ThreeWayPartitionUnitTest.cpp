#include <gmock/gmock.h>
#include <vector>
#include <utility>
#include <algorithm>
#include "ThreeWayPartition.hpp"

using namespace testing;
using namespace DivideAndConquer;

class SequenceInitialize: public Test {
public:
    std::vector<int> sequence = {3, 5, 2, 1, 3, 3};
};


TEST(Sequence, UniquePartitionInCorrectIndex) {
    std::vector<int> sequence = {3, 5, 2, 4, 1, 0};
    threeWayPartition(sequence, 0, sequence.size());
    ASSERT_THAT(sequence[3], 3);
}

TEST_F(SequenceInitialize, MultipleEqualPartitionCorrectIndexes) {
    threeWayPartition(sequence, 0, sequence.size());
    ASSERT_THAT(std::vector<int>(sequence.begin() + 2, sequence.begin() + 5),
                ElementsAre(3, 3, 3));
}

TEST_F(SequenceInitialize, LessThanInvariantMaintained) {
    threeWayPartition(sequence, 0, sequence.size());
    EXPECT_LT(sequence[0], 3);
    EXPECT_LT(sequence[1], 3);
}

TEST_F(SequenceInitialize, MoreThanInvariantMaintained) {
    threeWayPartition(sequence, 0, sequence.size());
    ASSERT_GT(sequence[5], 3);
}

TEST_F(SequenceInitialize, CorrectIndexesReturned) {
    auto index_pair = threeWayPartition(sequence, 0, sequence.size());
    ASSERT_THAT(index_pair, std::make_pair(2, 5));
}

TEST_F(SequenceInitialize, QuickSortSortsCorrectly) {
    randomizedQuickSort(sequence);
    ASSERT_TRUE(std::is_sorted(sequence.begin(), sequence.end()));
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
