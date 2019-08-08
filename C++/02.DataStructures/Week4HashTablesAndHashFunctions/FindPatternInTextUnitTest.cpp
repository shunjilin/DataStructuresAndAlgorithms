#include <gmock/gmock.h>
#include "FindPatternInText.hpp"

using namespace testing;

TEST(FindPatternInText, rollingHashSameForSamePatterns) {
    auto first_hash_value = rollingHashString(hashString("apatter", 0, 7),
                                              "apattern", 7, 0,
                                              getSubtractionMultiplier(7));
    auto second_hash_value = rollingHashString(hashString("bpatter", 0, 7),
                                               "bpattern", 7, 0,
                                               getSubtractionMultiplier(7));
    ASSERT_EQ(first_hash_value, second_hash_value);
}

TEST(FindPatternInText, matchCorrectly) {
    ASSERT_THAT(findPatternInText("aba", "abacaba"), ElementsAre(0, 4));
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
