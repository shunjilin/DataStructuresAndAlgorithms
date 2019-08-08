#include <cmath>
#include <iostream>
#include "Mathematics.hpp"
#include "UniformRandom.hpp"

using namespace Mathematics;

unsigned long long fibonacciModNaive(unsigned long long n,
                                     unsigned long long m) {
        if (n <= 1) return n;
        unsigned long long prev_prev = 0, prev = 1;

        for (unsigned long long i = 2; i <= n; ++i) {
            unsigned long long current = (prev_prev + prev) % m;
            prev_prev = prev;
            prev = current;
        }
        return prev;
}

int main()
{
    UniformRandom<unsigned long long> n_rng(1, std::pow(10, 7));
    UniformRandom<unsigned long long> m_rng(2, std::pow(10, 5));

    for (int i = 0; i < 1000; ++i) {
        auto n = n_rng.generate();
        auto m = m_rng.generate();
        if (fibonacciModNaive(n, m) != fibonacciMod(n, m)) {
            std::cout << "fibMod(" << n << " , " << m << "\n"
                      << "WRONG\n";
            break;
        }
        std::cout << "OK\n";
    }
}
