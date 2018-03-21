#ifndef POINTS_AND_SEGMENTS_HPP
#define POINTS_AND_SEGMENTS_HPP

#include <vector>
#include <algorithm>

namespace DivideAndConquer {

    enum class PointType { left = 0, single = 1, right = 2 };
    
    struct Point {
        int coord;
        PointType type;
        std::size_t index;
        bool operator<(const Point& other) const {
            if (coord != other.coord) {
                return coord < other.coord;
            } else {
                return type < other.type;
            }
        }
    };

    std::vector<unsigned>
    countSegmentsCoveringPoints(const std::vector<int>& points,
                                const std::vector<int>& left_ends,
                                const std::vector<int>& right_ends) {
        auto all_points = std::vector<Point>();
        for (std::size_t i = 0; i < points.size(); ++i) {
            all_points.emplace_back(Point{points[i], PointType::single, i});
        }
        for (auto left_end : left_ends) {
            all_points.emplace_back(Point{left_end, PointType::left});
        }
        for (auto right_end : right_ends) {
            all_points.emplace_back(Point{right_end, PointType::right});
        }
        std::sort(all_points.begin(), all_points.end());
        unsigned count = 0;
        auto counts = std::vector<unsigned>(points.size());
        for (auto& point : all_points) {
            if (point.type == PointType::left) ++count;
            if (point.type == PointType::right) --count;
            if (point.type == PointType::single) {
                counts[point.index] = count;
            }
        }
        return counts;
    }
}

#endif
