#include <gmock/gmock.h>
#include "MoneyChange2.hpp"
#include <vector>

using namespace testing;
using namespace DynamicProgramming;

TEST(MoneyChange, ReturnsCorrectNumberOfCoins) {
    auto coins = std::vector<unsigned>{1, 3, 4};
    ASSERT_THAT(getMinCoins(coins, 2), 2);
}

TEST(MoneyChange, ReturnsCorrectOptimalNumberOfCoins) {
    auto coins = std::vector<unsigned>{1, 3, 4};
    ASSERT_THAT(getMinCoins(coins, 34) , 9);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
