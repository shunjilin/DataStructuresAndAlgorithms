#include <gmock/gmock.h>
#include "LargestNumber.hpp"

using namespace testing;
using namespace GreedyAlgorithms;


TEST(LargestNumber, LessThanKeyCorrect) {
    less_than_key lt;
    EXPECT_TRUE(lt("10", "1"));
    EXPECT_FALSE(lt("1", "10"));
    EXPECT_TRUE(lt("5", "59"));
}

TEST(LargestNumber, ReturnLargestNumberForSingleDigits) {
    std::vector<std::string> digits = {"9", "4", "6", "1", "9"};
    ASSERT_THAT(LargestNumber(digits), std::string("99641"));
}

TEST(LargestNumber, ReturnLargestNumberForNonSingleDigits) {
    std::vector<std::string> digits = {"23", "39", "92"};
    ASSERT_THAT(LargestNumber(digits), std::string("923923"));
}

TEST(LargestNumber, ReturnLargestNumberMixedDigits) {
    std::vector<std::string> digits = {"21", "2"};
    ASSERT_THAT(LargestNumber(digits), std::string("221"));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

