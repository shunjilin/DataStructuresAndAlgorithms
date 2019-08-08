#include <iostream>
#include <vector>
#include <algorithm>
#include "UniformRandom.hpp"
#include "ThreeWayPartition.hpp"

using namespace DivideAndConquer;


int main()
{
    UniformRandom<int> length_gen(0, 5);//pow(10, 5));
    UniformRandom<int> key_gen(0,5);// pow(10, 9));

    for (int trials = 0; trials < 10000; ++trials) {
        std::vector<int> sequence(length_gen.generate());
         std::generate(sequence.begin(), sequence.end(), [&]() {
                return key_gen.generate();
             }
             );
                      for (auto key : sequence) {
                 std::cout << key << " ";
             }
             std::cout << "\n";
             randomizedQuickSort(sequence);
         if (std::is_sorted(sequence.begin(), sequence.end())) {
             std::cout << "OK\n";
         } else {
             std::cout << "WRONG\n";
             for (auto key : sequence) {
                 std::cout << key << " ";
             }
             std::cout << "\n";
             return 0;
         }
    }
}
