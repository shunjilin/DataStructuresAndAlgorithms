#include <gmock/gmock.h>
#include <vector>
#include "Knapsack.hpp"

using namespace testing;
using namespace DynamicProgramming;

TEST(Knapsack, ReturnsOptimalWeight) {
    std::vector<unsigned> weights = {8, 4, 1};
    unsigned max_weight = 10;
    ASSERT_THAT(optimalWeight(max_weight, weights), 9);
}

TEST(Knapsack, ReturnsOptimalWeight2) {
    std::vector<unsigned> weights = {40};
    unsigned max_weight = 71;
    ASSERT_THAT(optimalWeight(max_weight, weights), 40);
}


int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
