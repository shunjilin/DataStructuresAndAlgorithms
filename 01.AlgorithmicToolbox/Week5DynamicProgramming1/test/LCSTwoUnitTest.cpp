#include <gmock/gmock.h>
#include "LongestCommonSubsequence.hpp"

using namespace testing;
using namespace DynamicProgramming;

TEST(LCS, CorrectLCSLengthForOneCommonSubsequence) {
    std::vector<int> sequence1 = {2, 7, 5};
    std::vector<int> sequence2 = {2, 5};
    ASSERT_THAT(getLongestCommonSubsequenceLength(sequence1, sequence2),
                2);
}

TEST(LCS, CorrectLCSLengthForNoCommonSubsequence) {
    std::vector<int> sequence1 = {7};
    std::vector<int> sequence2 = {1, 2, 3, 4};
    ASSERT_THAT(getLongestCommonSubsequenceLength(sequence1, sequence2),
                0);
}

TEST(LCS, CorrectLCSLengthForMulitpleCommonSubsequence) {
    std::vector<int> sequence1 = {2, 7, 8, 3};
    std::vector<int> sequence2 = {5, 2, 8, 7};
    ASSERT_THAT(getLongestCommonSubsequenceLength(sequence1, sequence2),
                2);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
