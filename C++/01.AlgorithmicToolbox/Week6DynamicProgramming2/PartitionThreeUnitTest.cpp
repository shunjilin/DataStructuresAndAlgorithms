#include <gmock/gmock.h>
#include <vector>
#include "PartitionThree.hpp"

using namespace testing;
using namespace DynamicProgramming;

TEST(PartitionThree, NoPossiblePartitionReturnsFalse) {
    std::vector<unsigned> weights = {3, 3, 3, 3};
    ASSERT_FALSE(partitionThree(weights));
}

TEST(PartitionThree, SingleItemReturnsFalse) {
    std::vector<unsigned> weights = {30};
    ASSERT_FALSE(partitionThree(weights));
}

TEST(PartitionThree, PossiblePartitionReturnsTrue) {
    std::vector<unsigned> weights = {1, 1, 1};
    ASSERT_TRUE(partitionThree(weights));
}

TEST(PartitionThree, BiggerPossiblePartitionReturnsTrue) {
    std::vector<unsigned> weights = {17, 59, 34, 57, 17, 23, 67, 1, 18, 2, 59};
    ASSERT_TRUE(partitionThree(weights));
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
