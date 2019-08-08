#include <gmock/gmock.h>
#include "DifferentSummands.hpp"

using namespace testing;
using namespace GreedyAlgorithms;

TEST(Summand, ReturnMaximumNumberOfSummands) {
    unsigned sum = 6;
    auto different_summands = maxDifferentSummands(sum);
    EXPECT_THAT(different_summands.size(), 3);
}

TEST(Summand, ReturnDifferentSummands) {
    unsigned sum = 2;
    auto different_summands = maxDifferentSummands(sum);
    EXPECT_THAT(different_summands, ElementsAre(2));
}

TEST(Summand, ReturnDifferentSummandsBig) {
    unsigned sum = 8;
    auto different_summands = maxDifferentSummands(sum);
    EXPECT_THAT(different_summands, ElementsAre(1, 2, 5));
}


int main(int argc, char *argv[])
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
