#include <iostream>
#include <vector>
#include "MaxPairwiseProduct.hpp"
#include "SteadyClockTmer.hpp"

int main()
{
    unsigned long long n;
    std::cin >> n;
    std::vector<unsigned long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    SteadyClockTimer timer;
    timer.start();
    auto result = MPP::maxPairwiseProduct(numbers);
    auto time_taken = timer.getMs();
    std::cout << result << "\n";
    std::cout << "Time taken: " << timer.getMs() << "ms\n";
}
