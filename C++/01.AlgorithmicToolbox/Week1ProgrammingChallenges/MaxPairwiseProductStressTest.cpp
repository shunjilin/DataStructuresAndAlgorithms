#include "MaxPairwiseProduct.hpp"
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

unsigned long long
maxPairwiseProductNaive(const std::vector<unsigned long long> &numbers) {
  unsigned long long max_pair_product = 0;
  for (std::size_t i = 0; i < numbers.size(); ++i) {
    for (std::size_t j = i + 1; j < numbers.size(); ++j) {
      auto product = numbers[i] * numbers[j];
      if (product > max_pair_product)
        max_pair_product = product;
    }
  }
  return max_pair_product;
}

int main() {
  std::random_device rd;
  std::array<int, std::mt19937::state_size> seed_data{};
  std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
  std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
  auto eng = std::mt19937{seq};
  auto dist = std::uniform_int_distribution<unsigned long long>{0, 100000};
  // auto gen = std::bind(dist, eng);

  for (int i = 0; i < 10000; ++i) {
    std::vector<unsigned long long> numbers(10);
    std::generate(std::begin(numbers), std::end(numbers),
                  [&]() { return dist(eng); });

    auto max_pair_product = maxPairwiseProduct(numbers);
    auto expected = maxPairwiseProductNaive(numbers);
    if (max_pair_product == expected) {
      std::cout << "OK\n";
    } else {
      std::cout << "WRONG\n";
      for (auto number : numbers) {
        std::cout << number << " ";
      }
      std::cout << "\n";
      break;
    }
    std::cout << "Max Pair Product: " << max_pair_product
              << " Expected: " << expected << "\n";
  }
  return 0;
}
