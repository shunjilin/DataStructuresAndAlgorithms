#ifndef EDIT_DISTANCE_HPP
#define EDIT_DISTANCE_HPP
#include <string>
#include <vector>
#include <algorithm>

namespace DynamicProgramming {
    unsigned editDistance(const std::string& first, const std::string& second) {
        auto edit_distances =
            std::vector<
                std::vector<unsigned> >
            (first.length() + 1,
             std::vector<unsigned>(second.length() + 1,0));
        
        for (std::size_t row = 0; row <= first.length(); ++row) {
            edit_distances[row][0] = row;
        }
        for (std::size_t col = 0; col <= second.length(); ++col) {
            edit_distances[0][col] = col;
        }
        for (std::size_t row = 1; row <= first.length(); ++row) {
            for (std::size_t col = 1; col <= second.length(); ++col) {
                if (first[row-1] == second[col-1]) {
                    edit_distances[row][col] = edit_distances[row-1][col-1];
                } else {
                    edit_distances[row][col] =
                        1 + std::min(edit_distances[row-1][col-1],
                                     std::min(edit_distances[row-1][col],
                                              edit_distances[row][col-1]));
                }
            }
        }
        return edit_distances[first.length()][second.length()];
    }
}
#endif
