#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP
#include <cmath>

namespace Mathematics {
    unsigned long long fibonacci(unsigned long long n) {
        if (n <= 1) return n;
        unsigned long long prev_prev = 0, prev = 1;

        for (unsigned long long i = 2; i <= n; ++i) {
            unsigned long long current = prev_prev + prev;
            prev_prev = prev;
            prev = current;
        }
        return prev;
    }
    
    unsigned long long fibonacciModPeriod(unsigned long long mod) {
        if (mod == 1) return 1;
        unsigned long long prev_prev = 0, prev = 1;
        unsigned long long i = 2;
        for (; ; ++i) {
            unsigned long long current = (prev_prev + prev) % mod;
            prev_prev = prev;
            prev = current;
            if (prev_prev == 0 && prev == 1) break;
        }
        return i-1;
    }

    unsigned long long fibonacciMod(unsigned long long n, unsigned long long mod) {
        auto modPeriod = fibonacciModPeriod(mod);
        n = n % modPeriod;
        if (n <= 1) return n;
        unsigned long long prev_prev = 0, prev = 1;
        for (unsigned long long i = 2; i <= n; ++i) {
            unsigned long long current = (prev_prev + prev) % mod;
            prev_prev = prev;
            prev = current;
        }
        return prev;
    }

    unsigned long long fibonacciMod10(unsigned long long n) {
        return fibonacciMod(n, 10);
    }

    unsigned long long fibonacciSumMod10(unsigned long long n) {
        auto fibNPlus2Mod10 = fibonacciMod(n + 2, 10);
        if (fibNPlus2Mod10 == 0) {
            return 9;
        } else return fibNPlus2Mod10 - 1;
    }

    // can be further optimized to cache sum_to while calculating sum_from,
    // but violates DRY
    unsigned long long fibonacciPartialSumMod10(unsigned long long from,
                                                unsigned long long to) {
        if (from == to) return fibonacciMod10(from);
        auto full_sum = fibonacciSumMod10(to);
        auto subtract_sum = fibonacciSumMod10(from - 1);
        return (subtract_sum <= full_sum) ?
            full_sum - subtract_sum : 10 + full_sum - subtract_sum;
    }

    unsigned long long GCD(unsigned long long a, unsigned long long b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    unsigned long long LCM(unsigned long long a, unsigned long long b) {
        return a * b / GCD(a, b);
    }

    
};

#endif
