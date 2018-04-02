#include <iostream>
#include <vector>
#include "LongestCommonSubsequence.hpp"
#include "UniformRandom.hpp"

// recursive
unsigned getLongestCommonSubsequenceLength(const std::vector<int>& sequence1,
                                           const std::vector<int>& sequence2,
                                           const std::vector<int>& sequence3) {
    if (sequence1.size() == 0 || sequence2.size() == 0 || sequence3.size() == 0)
        return 0;
    if (sequence1[sequence1.size()-1] == sequence2[sequence2.size()-1] &&
        sequence2[sequence2.size()-1] == sequence3[sequence3.size()-1]) {
        return 1 + getLongestCommonSubsequenceLength
            (std::vector<int>(sequence1.begin(), sequence1.end()-1),
             std::vector<int>(sequence2.begin(), sequence2.end()-1),
             std::vector<int>(sequence3.begin(), sequence3.end()-1));
    } else {
        return std::max
            (getLongestCommonSubsequenceLength
             (std::vector<int>(sequence1.begin(), sequence1.end()-1),
              std::vector<int>(sequence2.begin(), sequence2.end()),
              std::vector<int>(sequence3.begin(), sequence3.end())),
             std::max
             (getLongestCommonSubsequenceLength
              (std::vector<int>(sequence1.begin(), sequence1.end()),
               std::vector<int>(sequence2.begin(), sequence2.end()-1),
               std::vector<int>(sequence3.begin(), sequence3.end())),
              getLongestCommonSubsequenceLength
              (std::vector<int>(sequence1.begin(), sequence1.end()),
               std::vector<int>(sequence2.begin(), sequence2.end()),
               std::vector<int>(sequence3.begin(), sequence3.end()-1))));
    }
}

int main(int argc, char *argv[])
{
    UniformRandom<unsigned> sequence_length_rng(0, 5);
    UniformRandom<int> entry_rng(-10, 10);

    for (int trials = 0; trials < 1000; ++trials) {
        std::vector<int> sequence1(sequence_length_rng.generate());
        std::vector<int> sequence2(sequence_length_rng.generate());
        std::vector<int> sequence3(sequence_length_rng.generate());

        for (std::size_t i = 0; i < sequence1.size(); ++i) {
            sequence1[i] = entry_rng.generate();
        }
        for (std::size_t i = 0; i < sequence2.size(); ++i) {
            sequence2[i] = entry_rng.generate();
        }
        for (std::size_t i = 0; i < sequence3.size(); ++i) {
            sequence3[i] = entry_rng.generate();
        }
        auto expected_LCS_length =
            getLongestCommonSubsequenceLength(sequence1, sequence2, sequence3);
        auto actual_LCS_length =
            DynamicProgramming::getLongestCommonSubsequenceLength(sequence1,
                                                                  sequence2,
                                                                  sequence3);
        if (expected_LCS_length == actual_LCS_length) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            std::cout << "sequence 1 : ";
            for (auto val : sequence1) {
                std::cout << val << " ";
            }
            std::cout << "\nsequence 2: ";
            for (auto val : sequence2) {
                std::cout << val << " ";
            }
            std::cout << "\nexpected LCS length : " << expected_LCS_length
                      << " actual LCS length : " << actual_LCS_length
                      << "\n";
            return 0;
        }
    }
}
