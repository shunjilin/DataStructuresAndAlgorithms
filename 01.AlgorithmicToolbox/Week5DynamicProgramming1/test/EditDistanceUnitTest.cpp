#include <gmock/gmock.h>
#include "EditDistance.hpp"
#include <vector>

using namespace testing;
using namespace DynamicProgramming;

TEST(EditDistance, CorrectEditDistanceForEqualStrings) {
    ASSERT_THAT(editDistance("ab", "ab"), 0);
}

TEST(EditDistance, CorrectEditDistanceNonEqualStrings) {
    ASSERT_THAT(editDistance("editing", "distance"), 5);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
