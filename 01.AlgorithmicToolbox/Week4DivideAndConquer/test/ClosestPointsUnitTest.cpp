#include <gmock/gmock.h>
#include "ClosestPoints.hpp"

using namespace testing;
using namespace DivideAndConquer;

#include <vector>

class PointsInitialize: public Test {
public:
    std::vector<Point> points = {{4, 4}, {-2, -2}, {-3, -4}, {-1, 3}, {2, 3},
                                 {-4, 0}, {1, 1}, {-1, -1}, {3, -1}, {-4, 2},
                                 {-2, 4}};
};

TEST_F(PointsInitialize, correctMidPoint) {
    std::sort(points.begin(), points.end());
    ASSERT_THAT(getMidPointX(points.begin(), points.end()), 0);
}

TEST_F(PointsInitialize, correctMidPointIterator) {
    std::sort(points.begin(), points.end());
    ASSERT_THAT(getMidPointIterator(points.begin(), points.end())->x, 1);
}

TEST_F(PointsInitialize, minDistanceBounded) {
    std::sort(points.begin(), points.end());
    ASSERT_LE(getClosestPointsDistanceHelper(points.begin(), points.end()), 2);
}

TEST_F(PointsInitialize, correctMidrange) {
    std::sort(points.begin(), points.end());
    auto min_dist = 2.0;
    auto midrange = getMidRange(points.begin(), points.end(), min_dist);
    ASSERT_THAT(std::distance(midrange.first, midrange.second), 3);
}

TEST_F(PointsInitialize, correctMidrangeMinDist) {
    std::sort(points.begin(), points.end());
    auto min_dist = 2.0;
    auto midrange = getMidRange(points.begin(), points.end(), min_dist);
    auto min_dist_midrange = getMinDistMidRange(midrange.first, midrange.second);
    ASSERT_DOUBLE_EQ(min_dist_midrange,2*sqrt(2));
}

TEST_F(PointsInitialize, correctClosestPointsMinDistHelper) {
    std::sort(points.begin(), points.end());
    ASSERT_DOUBLE_EQ(getClosestPointsDistanceHelper(points.begin(),
                                                    points.end()), sqrt(2));
}

TEST_F(PointsInitialize, correctClosestPointsMinDist) {
    ASSERT_DOUBLE_EQ(getClosestPointsDistance(points.begin(), points.end()),
                     sqrt(2));
}

class PointsWithSameX: public Test {
public:
    std::vector<Point> points = {{2, 9}, {2, 4}, {2, 3}};
};

TEST_F(PointsWithSameX, correctMidPoint) {
    std::sort(points.begin(), points.end());
    ASSERT_THAT(getMidPointX(points.begin(), points.end()), 2);
}

TEST_F(PointsWithSameX, correctMidPointIterator) {
    std::sort(points.begin(), points.end());
    ASSERT_THAT(getMidPointIterator(points.begin(), points.end())->x, 2);
}

TEST_F(PointsWithSameX, correctMidrange) {
    std::sort(points.begin(), points.end());
    auto min_dist = 2.0;
    auto midrange = getMidRange(points.begin(), points.end(), min_dist);
    ASSERT_THAT(std::distance(midrange.first, midrange.second), 3);
}

TEST_F(PointsWithSameX, correctMidrangeMinDist) {
    std::sort(points.begin(), points.end());
    auto min_dist = 2.0;
    auto midrange = getMidRange(points.begin(), points.end(), min_dist);
    auto min_dist_midrange = getMinDistMidRange(midrange.first, midrange.second);
    ASSERT_DOUBLE_EQ(min_dist_midrange,1);
}

TEST_F(PointsWithSameX, correctClosestPointsMinDistHelper) {
    std::sort(points.begin(), points.end());
    ASSERT_DOUBLE_EQ(getClosestPointsDistanceHelper(points.begin(),
                                                    points.end()), 1);
}

TEST_F(PointsWithSameX, correctClosestPointsMinDist) {
    ASSERT_DOUBLE_EQ(getClosestPointsDistance(points.begin(), points.end()),
                     1);
}


int main(int argc, char *argv[])
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
