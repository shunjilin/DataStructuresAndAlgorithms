#include <gmock/gmock.h>
#include "CheckBrackets.hpp"

using namespace testing;

TEST(CheckBrackets, SuccessCase) {
    std::string input = "[]";
    ASSERT_EQ(bracketChecker(input), "Success");
}

TEST(CheckBrackets, SuccessCaseTwoPairs) {
    std::string input = "{}[]";
    ASSERT_EQ(bracketChecker(input), "Success");
}

TEST(CheckBrackets, SuccessCaseNested) {
    std::string input = "[()]";
    ASSERT_EQ(bracketChecker(input), "Success");
}

TEST(CheckBrackets, UnmatchedLeftBracket) {
    std::string input = "{";
    ASSERT_EQ(bracketChecker(input), "1");
}

TEST(CheckBrackets, UnmatchedRightBracket) {
    std::string input = "}";
    ASSERT_EQ(bracketChecker(input), "1");
}

TEST(CheckBrackets, UnmatchedRightBracketTwo) {
    std::string input = "{[}";
    ASSERT_EQ(bracketChecker(input), "3");
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
