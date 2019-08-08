#include <gmock/gmock.h>
#include <vector>
#include "MajorityElement.hpp"

using namespace testing;
using namespace DivideAndConquer;

TEST(MajorityElement, EvenAndMajorityExists) {
    std::vector<int> sequence = {1, 2, 2, 2};
    ASSERT_THAT(getMajorityElement(sequence), 2);
}

TEST(MajorityElement, EvenAndMajorityDoesNotExists) {
    std::vector<int> sequence = {1, 2, 2, 3};
    ASSERT_THAT(getMajorityElement(sequence), -1);
}

TEST(MajorityElement, OddAndMajorityExists) {
    std::vector<int> sequence1 = {1, 1, 0, 1, 0};
    std::vector<int> sequence2 = {0, 1, 0, 1, 1};
    EXPECT_THAT(getMajorityElement(sequence1), 1);
    EXPECT_THAT(getMajorityElement(sequence2), 1);
}

TEST(MajorityElement, OddAndMajorityDoesNotExists) {
    std::vector<int> sequence = {2, 2, 1, 1, 3};
    ASSERT_THAT(getMajorityElement(sequence), -1);
}

TEST(MajorityElement, AllDifferent) {
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    ASSERT_THAT(getMajorityElement(sequence), -1);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
