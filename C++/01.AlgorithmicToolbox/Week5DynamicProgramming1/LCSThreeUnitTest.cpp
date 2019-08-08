#include <gmock/gmock.h>
#include "LongestCommonSubsequence.hpp"

using namespace testing;
using namespace DynamicProgramming;

TEST(LCS, CorrectLCSLengthForOneCommonSubsequence) {
    std::vector<int> sequence1 = {1, 2, 3};
    std::vector<int> sequence2 = {2, 1, 3};
    std::vector<int> sequence3 = {1, 3, 5};
    ASSERT_THAT(getLongestCommonSubsequenceLength(sequence1, sequence2, sequence3),
                2);
}

TEST(LCS, CorrectLCSLengthForNoCommonSubsequence) {
    std::vector<int> sequence1 = {1, 2, 3};
    std::vector<int> sequence2 = {4, 5, 6};
    std::vector<int> sequence3 = {9, 7, 8};
    ASSERT_THAT(getLongestCommonSubsequenceLength(sequence1, sequence2, sequence3),
                0);
}

TEST(LCS, CorrectLCSLengthForMultipleCommonSubsequence) {
    std::vector<int> sequence1 = {8, 3, 2, 1, 7};
    std::vector<int> sequence2 = {8, 2, 1, 3, 8, 10, 7};
    std::vector<int> sequence3 = {6, 8, 3, 1, 4, 7};
    ASSERT_THAT(getLongestCommonSubsequenceLength(sequence1, sequence2, sequence3),
                3);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

