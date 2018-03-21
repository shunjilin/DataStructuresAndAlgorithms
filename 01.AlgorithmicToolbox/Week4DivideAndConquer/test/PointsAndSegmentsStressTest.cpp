#include "PointsAndSegments.hpp"
#include "UniformRandom.hpp"
#include <vector>
#include <iostream>

using namespace DivideAndConquer;

std::vector<unsigned>
naiveCountSegmentsCoveringPoints(std::vector<int> points,
                                 std::vector<int> starts,
                                 std::vector<int> ends) {
    std::vector<unsigned> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}


int main(int argc, char *argv[])
{
    UniformRandom<unsigned> N_rng(0, 100);
    UniformRandom<int> point_rng(-100, 100);

    for (int trials = 0; trials < 10000; ++trials) {
        std::vector<int> points(N_rng.generate());
        std::vector<int> left_ends(N_rng.generate());
        std::vector<int> right_ends(left_ends.size());
        for (std::size_t i = 0; i < points.size(); ++i) {
            points[i] = point_rng.generate();
        }
        for (std::size_t i = 0; i < left_ends.size(); ++i) {
            auto start = point_rng.generate();
            auto end = point_rng.generate();
            if (start > end) std::swap(start, end);
            left_ends[i] = start;
            right_ends[i] = end;
        }
        auto expected = naiveCountSegmentsCoveringPoints(points, left_ends, right_ends);
        auto actual = countSegmentsCoveringPoints(points, left_ends, right_ends);
        if (actual == expected) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            for (std::size_t i = 0; i < actual.size(); ++i) {
                std::cout << "index : " << i << " actual : " << actual[i]
                          << " expected : " << expected[i] << "\n";
            }
            return 0;
        }
    }
}
