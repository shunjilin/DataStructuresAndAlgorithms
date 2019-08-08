#ifndef CLOSEST_POINTS_HPP
#define CLOSEST_POINTS_HPP

#include <vector>
#include <limits>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <utility>

namespace DivideAndConquer {
    struct Point {
        int x;
        int y;
        bool operator < (const Point& other) const {
            return x < other.x;
        }
        bool operator == (const Point& other) const {
            return x == other.x && y == other.y;
        }
    };

    double distance(const Point& point1, const Point& point2) {
        return sqrt(pow((point1.x - point2.x), 2) +  pow((point1.y - point2.y), 2));
    }

    template <typename RandomAccessIterator>
    int getMidPointX(RandomAccessIterator sorted_points_begin,
                    RandomAccessIterator sorted_points_end) {
        assert(std::distance(sorted_points_begin, sorted_points_end) >= 2);
        auto xbegin = sorted_points_begin->x;
        auto xend = (sorted_points_end - 1)->x;
        return xbegin + (xend - xbegin)/2;
    }

    template <typename RandomAccessIterator>
    auto getMidPointIterator(RandomAccessIterator sorted_points_begin,
                             RandomAccessIterator sorted_points_end) {
        auto midpoint_x = getMidPointX(sorted_points_begin, sorted_points_end);
        auto mid_point_it =
            std::upper_bound(sorted_points_begin, sorted_points_end,
                                midpoint_x,
                                [](int val, const Point& point) {
                                    return val < point.x;
                                });
        if (mid_point_it == sorted_points_end) {
            mid_point_it = sorted_points_begin +
                (std::distance(sorted_points_begin, sorted_points_end) / 2); 
        }
        return mid_point_it;
    }

    template <typename RandomAccessIterator>
    std::pair<RandomAccessIterator, RandomAccessIterator>
    getMidRange(RandomAccessIterator sorted_points_begin,
                     RandomAccessIterator sorted_points_end,
                     double min_dist) {
        auto midpoint_x = getMidPointX(sorted_points_begin, sorted_points_end);
        while (sorted_points_begin->x <= midpoint_x - min_dist)
            ++sorted_points_begin;
        while ((sorted_points_end - 1)->x >= midpoint_x + min_dist)
            --sorted_points_end;
        return std::make_pair(sorted_points_begin, sorted_points_end);
    }

    template <typename RandomAccessIterator>
    double getMinDistMidRange(RandomAccessIterator midrange_begin,
                              RandomAccessIterator midrange_end) {
        //if (midrange_begin == midrange_end)
            //return std::numeric_limits<double>::max();
        std::vector<Point> midrange(midrange_begin, midrange_end);
        std::sort(std::begin(midrange), std::end(midrange),
                  [](const Point& point1, const Point& point2) {
                      return point1.y < point2.y;
                  });
        double min_dist = std::numeric_limits<double>::max();
        for (auto point1_it = std::cbegin(midrange); point1_it != std::cend(midrange);
             ++point1_it) {
            auto point2_it = point1_it + 1;   
            for (int i = 0; point2_it != std::cend(midrange) && i < 7 ; ++i) {
                auto dist = distance(*point1_it, *point2_it);
                if (dist < min_dist) min_dist = dist;
            }
        }
        return min_dist;
    }
   
    

    template <typename RandomAccessIterator>
    double
    getClosestPointsDistanceHelper(RandomAccessIterator sorted_points_begin,
                                   RandomAccessIterator sorted_points_end) {
        auto n_points = std::distance(sorted_points_begin, sorted_points_end);
        if (n_points < 2) return std::numeric_limits<double>::max();
        if (n_points == 2) return distance(*sorted_points_begin,
                                           *(sorted_points_begin + 1));
        auto sorted_points_mid = getMidPointIterator(sorted_points_begin,
                                          sorted_points_end);

        auto min_first_half =
            getClosestPointsDistanceHelper(sorted_points_begin, sorted_points_mid);
        auto min_second_half =
            getClosestPointsDistanceHelper(sorted_points_mid, sorted_points_end);
        auto min_dist = min_first_half < min_second_half ?
                                         min_first_half : min_second_half;
        auto midrange = getMidRange(sorted_points_begin, sorted_points_end,
                                    min_dist);
        auto min_mid_range = getMinDistMidRange(midrange.first, midrange.second);      
        if (min_mid_range < min_dist) min_dist = min_mid_range;      
        return min_dist; 
        
    }


    template <typename RandomAccessIterator>
    double
    getClosestPointsDistance(RandomAccessIterator points_begin,
                             RandomAccessIterator points_end) {
        std::sort(points_begin, points_end);
        if (std::adjacent_find(points_begin, points_end) != points_end) return 0.0;
        return getClosestPointsDistanceHelper(points_begin, points_end);
    }
    
}
#endif
