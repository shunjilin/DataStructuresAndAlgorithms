#include <gmock/gmock.h>
#include "PointsAndSegments.hpp"

using namespace testing;
using namespace DivideAndConquer;

TEST(PointsAndSegments, PointsOnSegments) {
    std::vector<int> points = {-100, 100, 0};
    std::vector<int> left_ends = {-10};
    std::vector<int> right_ends = {10};
    ASSERT_THAT(countSegmentsCoveringPoints(points, left_ends, right_ends),
                ElementsAre(0, 0, 1));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
