#include <gmock/gmock.h>
#include "HashingWithChains.hpp"

using namespace testing;

TEST(HashingWithChains, correctRollingHash) {
    ASSERT_EQ(hashString("world"), 407643594);
}

TEST(HashingWithChains, chainCorrectly) {
    auto table = ChainedHashTable(5);
    table.add("world");
    table.add("Hell0");
    ASSERT_THAT(table.check(4), ElementsAre("Hell0", "world"));
};

TEST(HashingWithChains, findCorrectly) {
    auto table = ChainedHashTable(5);
    table.add("world");
    EXPECT_FALSE(table.find("World"));
    EXPECT_TRUE(table.find("world"));
}

TEST(HashingWithChains, deleteCorrectly) {
    auto table = ChainedHashTable(5);
    table.add("world");
    table.add("Hell0");
    table.del("hello"); //ignored
    table.del("Hell0");
    EXPECT_FALSE(table.find("Hell0"));
    EXPECT_THAT(table.check(4), ElementsAre("world"));
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
