#include <gmock/gmock.h>
#include <vector>
#include "FractionalKnapsack.hpp"

using namespace testing;
using namespace GreedyAlgorithms;

class KnapsackInitialize : public Test {
public:
    std::vector<Item> items;
    unsigned capacity = 50;
    void SetUp() override {
        items.emplace_back(Item{60, 20});
        items.emplace_back(Item{100, 50});
        items.emplace_back(Item{120, 30});
    }
};

TEST_F(KnapsackInitialize, ItemComparatorCorrect) {
    EXPECT_LT(items[1], items[2]);
    EXPECT_LT(items[1], items[0]);
    EXPECT_LT(items[0], items[2]);
}

TEST_F(KnapsackInitialize, MaxValueCorrect) {
    EXPECT_NEAR(maxValueFractionalKnapsack(capacity, items),
                180.0, 0.001);
}

TEST(FractionalKnapsack, getFractionalValueCorrectly) {
    std::vector<Item> items;
    unsigned capacity = 10;
    items.emplace_back(Item{500, 30});
    EXPECT_NEAR(maxValueFractionalKnapsack(capacity, items),
                166.6667, 0.001);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
