#ifndef COVERING_SEGMENTS_BY_POINTS
#define COVERING_SEGMENTS_BY_POINTS
#include <vector>
#include <algorithm>

namespace GreedyAlgorithms {

    using Point = unsigned;
    
    struct Segment {
        Point begin;
        Point end;

        bool operator<(const Segment& rhs) const {
            return end < rhs.end;
        }

    };

    bool pointWithinSegment(const Point& point, const Segment& segment) {
        return (point >= segment.begin && point <= segment.end);
    }

    std::vector<Point> getMinCoveringPoints(std::vector<Segment> segments) {
        std::vector<Point> points;
        std::sort(segments.rbegin(), segments.rend());
        while(!segments.empty()) {
            auto segment_to_cover = segments.back();
            segments.pop_back();
            Point point = segment_to_cover.end;
            points.push_back(point);
            while (!segments.empty()) {
                auto segment = segments.back();
                if (!pointWithinSegment(point, segment)) break;
                segments.pop_back();
            } 
        }
        return points;
    }
}

#endif
