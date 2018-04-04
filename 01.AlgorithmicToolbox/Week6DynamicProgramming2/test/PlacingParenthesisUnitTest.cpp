#include <gmock/gmock.h>
#include "PlacingParenthesis.hpp"
#include <string>

using namespace testing;
using namespace DynamicProgramming;

TEST(PlacingParenthesis, applyOperatorCorrect) {
    std::string expression = "5+2+3";
    ASSERT_THAT(applyOperator(5, 2, expression[1]), 7);
}

TEST(PlacingParenthesis, ReturnMaxValue) {
    std::string expression = "5-8+7*4-8+9";
    ASSERT_THAT(maxValueFromPlacingParenthesis(expression), 200);
}

TEST(PlacingParenthesis, ReturnMaxValue2) {
    std::string expression = "1+0+3*5";
    ASSERT_THAT(maxValueFromPlacingParenthesis(expression), 20);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
