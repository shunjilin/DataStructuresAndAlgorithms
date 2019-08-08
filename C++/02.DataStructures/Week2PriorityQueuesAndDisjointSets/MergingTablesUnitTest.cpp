#include <gmock/gmock.h>
#include "MergingTables.hpp"

using namespace testing;

TEST(MergingTables, CorrectMaxSizes) {
    std::vector<size_t> entry_sizes = {1, 1, 1, 1, 1};
    auto disjoint_set = DisjointSet(entry_sizes);
    disjoint_set.Union(2, 4);
    EXPECT_EQ(disjoint_set.getMaxSize(), 2);
    disjoint_set.Union(1, 3);
    EXPECT_EQ(disjoint_set.getMaxSize(), 2);
    disjoint_set.Union(0, 3);
    EXPECT_EQ(disjoint_set.getMaxSize(), 3);
    disjoint_set.Union(4, 3);
    EXPECT_EQ(disjoint_set.getMaxSize(), 5);
    disjoint_set.Union(4, 2);
    EXPECT_EQ(disjoint_set.getMaxSize(), 5);    
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
