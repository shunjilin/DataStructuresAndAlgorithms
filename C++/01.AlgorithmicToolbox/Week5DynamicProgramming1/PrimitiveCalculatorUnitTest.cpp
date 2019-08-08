#include <gmock/gmock.h>
#include <vector>
#include "PrimitiveCalculator.hpp"

using namespace testing;
using namespace DynamicProgramming;

TEST(PrimitiveCalculator, ReturnCorrectMinimumNumberOfOperations) {
    ASSERT_THAT(getMinCalculatorOperations(5)[5], 3);
}

TEST(PrimitiveCalculator, ReturnCorrectIntermediateResults) {
    ASSERT_THAT(getIntermediateResults(getMinCalculatorOperations(5)),
                ElementsAre(1, 3, 4, 5));
}

int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
