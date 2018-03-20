#include <gmock/gmock.h>
#include "Inversions.hpp"
#include <algorithm>

using namespace testing;
using namespace DivideAndConquer;

class InversionsInitialize: public Test {
public:
    std::vector<int> numbers = {4, 7, 3, 1, 6, 2, 8, 5};
    std::vector<int> numbers_small = {3, 2, 1, 4};
    std::vector<int> numbers_with_duplicates = {3, 1, 2, 3, 1, 2};
    std::vector<int> numbers_with_negatives = {0, -1, 1, -2, 2};
};

TEST_F(InversionsInitialize, MergeTwoSortedListsCorrectly) {
    std::vector<int> sorted_one = {1, 3, 5, 7};
    std::vector<int> sorted_two = {2, 4, 6, 8};
    std::vector<int> merged(sorted_one.size() + sorted_two.size());
    merge(std::begin(sorted_one), std::end(sorted_one),
                     std::begin(sorted_two), std::end(sorted_two),
                     merged.begin(), nullptr, std::less<int>());
    ASSERT_THAT(merged, ElementsAre(1, 2, 3, 4, 5, 6, 7, 8));
}

TEST_F(InversionsInitialize, SortListCorrectly) {
    sort(numbers.begin(), numbers.end());
    ASSERT_THAT(numbers, ElementsAre(1, 2, 3, 4, 5, 6, 7, 8));
}

TEST_F(InversionsInitialize, ReturnCorrectInverseCount) {
    ASSERT_THAT(sortAndGetInversionCount(std::begin(numbers_small),
                                                  std::end(numbers_small)),
                3);
}

TEST_F(InversionsInitialize, ReturnCorrectInverseCountOnDuplicates) {
    auto inversion_count =
        sortAndGetInversionCount
                (std::begin(numbers_with_duplicates),
                 std::end(numbers_with_duplicates));
    EXPECT_THAT(numbers_with_duplicates, ElementsAre(1, 1, 2, 2, 3, 3));
    ASSERT_THAT(inversion_count, 7);
}

TEST_F(InversionsInitialize, ReturnCorrectInverseCountOnNegatives) {
    auto inversion_count =
        sortAndGetInversionCount
                (std::begin(numbers_with_negatives),
                 std::end(numbers_with_negatives));
    EXPECT_THAT(numbers_with_negatives, ElementsAre(-2, -1, 0, 1, 2));
    ASSERT_THAT(inversion_count, 4);
}



int main(int argc, char *argv[]) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

