#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "UniformRandom.hpp"
#include "ClosestPoints.hpp"

using namespace DivideAndConquer;

double naiveGetClosestPointsDistance(const std::vector<Point>& points) {
    double min_dist = std::numeric_limits<double>::max();
    for (auto point1 = std::cbegin(points); point1 != std::cend(points); ++point1) {
        auto point2 = point1 + 1;
        while (point2 != std::cend(points)) {
            auto dist = distance(*point1, *point2);
            if (dist < min_dist) min_dist = dist;
            ++point2;
        }
    }
    return min_dist;
}

int main()
{
    UniformRandom<int> point_coordinates_rng(-10, 10);
    UniformRandom<unsigned> n_points_rng(2, 3);

    for (int i = 0; i < 10000; ++i) {
        auto n_points = n_points_rng.generate();
        std::vector<Point> points(n_points);
        std::generate(points.begin(), points.end(),
                      [&]() {
                          return Point{point_coordinates_rng.generate(),
                                  point_coordinates_rng.generate()};
                      });
        std::sort(std::begin(points), std::end(points));
        points.erase(std::unique(std::begin(points), std::end(points)),
                   std::end(points));
        auto expected_min_dist = naiveGetClosestPointsDistance(points);
        auto actual_min_dist = getClosestPointsDistance(std::begin(points),
                                                        std::end(points));
        if (expected_min_dist == actual_min_dist) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            for (auto point: points) {
                std::cout << "x : " << point.x << " y : " << point.y << std::endl;
            }
            return 0;
        }
    }
}
