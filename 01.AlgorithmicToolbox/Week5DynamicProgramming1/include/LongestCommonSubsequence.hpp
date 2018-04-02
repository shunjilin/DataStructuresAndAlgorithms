#ifndef LONGEST_COMMON_SUBSEQUENCE
#define LONGEST_COMMON_SUBSEQUENCE

#include <vector>
#include <algorithm>

namespace DynamicProgramming {
    unsigned getLongestCommonSubsequenceLength(const std::vector<int>& sequence1,
                                               const std::vector<int>& sequence2) {
        auto LCS_table =
            std::vector< std::vector<unsigned> >
            (sequence1.size() + 1,
             std::vector<unsigned>(sequence2.size() + 1, 0));
        for (std::size_t row = 1; row <= sequence1.size(); ++row) {
            for (std::size_t col = 1; col <= sequence2.size(); ++col) {
                if (sequence1[row-1] == sequence2[col-1]) {
                    LCS_table[row][col] = LCS_table[row-1][col-1] + 1;
                } else {
                    LCS_table[row][col] = std::max(LCS_table[row-1][col],
                                                   LCS_table[row][col-1]);
                }
            }
        }
        return LCS_table[sequence1.size()][sequence2.size()];
    }

    unsigned getLongestCommonSubsequenceLength(const std::vector<int>& sequence1,
                                               const std::vector<int>& sequence2,
                                               const std::vector<int>& sequence3) {
        auto LCS_table =
            std::vector< std::vector< std::vector<unsigned> > >
            (sequence1.size() + 1,
             std::vector< std::vector<unsigned> >
             (sequence2.size() + 1,
              std::vector<unsigned>(sequence3.size() + 1, 0)));
        for (std::size_t x = 1; x <= sequence1.size(); ++x) {
            for (std::size_t y = 1; y <= sequence2.size(); ++y) {
                for (std::size_t z = 1; z <= sequence3.size(); ++z) {
                    if (sequence1[x-1] == sequence2[y-1] &&
                        sequence2[y-1] == sequence3[z-1]) {
                        LCS_table[x][y][z] = LCS_table[x-1][y-1][z-1] + 1;
                    } else {
                        LCS_table[x][y][z] =std::max(LCS_table[x-1][y][z],
                                                     std::max(LCS_table[x][y-1][z],
                                                              LCS_table[x][y][z-1]));
                    }
                }
            }
        }
        return LCS_table[sequence1.size()][sequence2.size()][sequence3.size()];
    }
}
#endif
