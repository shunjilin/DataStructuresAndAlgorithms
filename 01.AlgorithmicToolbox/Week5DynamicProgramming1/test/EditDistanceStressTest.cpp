#include <iostream>
#include <string>
#include "EditDistance.hpp"
#include "UniformRandom.hpp"

// recursive
unsigned editDistance(const std::string& first, const std::string& second) {
    if (first.length() == 0) return second.length();
    if (second.length() == 0) return first.length();
    if (first[first.length() - 1] == second[second.length() - 1]) {
        return editDistance(first.substr(0, first.length()-1),
                            second.substr(0, second.length()-1));
    } else {
        return 1 +
            std::min(editDistance(first.substr(0, first.length()-1),
                                  second.substr(0, second.length()-1)),
                     std::min(editDistance(first.substr(0, first.length()-1),
                                           second),
                              editDistance(first,
                                           second.substr(0, second.length()-1))));
    }
}


int main(int argc, char *argv[])
{
    UniformRandom<unsigned> n_char_rng(1,10);
    UniformRandom<char> char_rng('a', 'z');

    for (int trials = 0; trials < 1000; ++trials) {
        auto first_n_char = n_char_rng.generate();
        auto second_n_char = n_char_rng.generate();
        std::string first, second;
        for (int i = 0; i < first_n_char; ++i) {
            auto character = char_rng.generate();
            first.append(&character, 1);
        }
        for (int i = 0; i < second_n_char; ++i) {
            auto character = char_rng.generate();
            second.append(&character, 1);
        }

        auto expected_edit_distance = editDistance(first, second);
        auto actual_edit_distance = DynamicProgramming::editDistance(first, second);
        if (expected_edit_distance == actual_edit_distance) {
            std::cout << "OK\n";
        } else {
            std::cout << "WRONG\n";
            std::cout << "First string : " << first
                      << " Second string : " << second << "\n"
                      << "Expected edit distance : " << expected_edit_distance
                      << " Actual edit distance : " << actual_edit_distance
                      << "\n";
        }
    }
    
    return 0;
}
