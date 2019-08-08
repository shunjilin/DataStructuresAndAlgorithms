#include <gmock/gmock.h>
#include "MaxPairwiseProduct.hpp"

using namespace testing;
using namespace MPP;

class MaxPairwiseProductInitialize: public Test {
public:
    std::vector<unsigned long long>
    numbers = {21468, 16859, 82178, 70496, 82939, 44491};
};

TEST_F(MaxPairwiseProductInitialize, MaxPairReturnsCorrectly) {
    ASSERT_THAT(getMaxPair(numbers),
                (std::pair<unsigned long long, unsigned long long>
                 (82939, 82178)));
                
}

TEST_F(MaxPairwiseProductInitialize, MaxPairwiseProductReturnsCorrectProduct) {
    ASSERT_THAT(maxPairwiseProduct(numbers), 6815761142);   
}

int main(int argc, char *argv[]) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

