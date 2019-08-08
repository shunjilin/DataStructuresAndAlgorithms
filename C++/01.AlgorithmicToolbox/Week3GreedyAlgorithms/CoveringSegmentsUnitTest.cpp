#include <gmock/gmock.h>
#include "CoveringSegmentsByPoints.hpp"

using namespace testing;
using namespace GreedyAlgorithms;

class CoveringSegmentsInitialize: public Test {
public:
    std::vector<Segment> segments;
    void SetUp() override {
        segments.emplace_back(Segment{1, 3});
        segments.emplace_back(Segment{2, 5});
        segments.emplace_back(Segment{3, 6});
    }
};

TEST_F(CoveringSegmentsInitialize, ReturnsPoints) {
    auto points = getMinCoveringPoints(segments);
    ASSERT_GT(points.size(), 0);
}

TEST_F(CoveringSegmentsInitialize, PointsCoverSegments) {
    auto points = getMinCoveringPoints(segments);
    for (auto point : points) {
        segments.erase(std::remove_if
                       (std::begin(segments), std::end(segments),
                        [point](Segment segment) {
                           return pointWithinSegment(point, segment);
                       }), std::end(segments));
    }
    ASSERT_THAT(segments.size(), 0);
}

TEST(CoveringSegments, PointsAreMinimal) {
    std::vector<Segment> segments;
    segments.emplace_back(Segment{4, 7});
    segments.emplace_back(Segment{1, 3});
    segments.emplace_back(Segment{2, 5});
    segments.emplace_back(Segment{5, 6});
    ASSERT_THAT(getMinCoveringPoints(segments).size(), 2);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
