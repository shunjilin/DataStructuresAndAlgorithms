#include <iostream>
#include "Mathematics.hpp"
#include "UniformRandom.hpp"

using namespace Mathematics;

unsigned long long LCM_Naive(unsigned long long a,
                             unsigned long long b) {
    auto a_multiple = a;
    auto b_multiple = b;

    while (a_multiple != b_multiple) {
        a_multiple < b_multiple ? a_multiple += a : b_multiple += b;
    }
    return a_multiple;
}

int main()
{
    UniformRandom<unsigned long long> rng(1, std::pow(10, 9));

    for (int i = 0; i < 1000; ++i) {
        auto a = rng.generate();
        auto b = rng.generate();
        if (LCM(a, b) != LCM_Naive(a, b)) {
            std::cout << "LCM(" << a << " , " << b << "\n"
                      << "WRONG\n";
            break;
        }
        std::cout << "OK\n";
    }
}
