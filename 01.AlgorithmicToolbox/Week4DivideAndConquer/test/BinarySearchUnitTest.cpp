#include <gmock/gmock.h>
#include <vector>
#include "BinarySearch.hpp"

using namespace testing;
using namespace DivideAndConquer;

TEST(BinarySearch, BinarySearchReturnsCorrectIndexIfKeyFound) {
    std::vector<int> sorted_list = {1, 5, 8, 12, 13};
    ASSERT_THAT(binarySearch(sorted_list, 12), 3);
}

TEST(BinarySearh, BinarySearchReturnsInvalidIfKeyNotFound) {
    std::vector<int> sorted_list = {1, 5, 8, 12, 13};
    ASSERT_THAT(binarySearch(sorted_list, 22), -1);
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
