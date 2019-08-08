#ifndef UNIFORM_RANDOM_HPP
#define UNIFORM_RANDOM_HPP

#include <random>
#include <array>
#include <functional>
#include <algorithm>

template<typename T>
class UniformRandom {
    std::mt19937 eng;
    std::uniform_int_distribution<T> dist;
    
public:
    UniformRandom<T>(T range_start, T range_end) {
            std::random_device rd;
            std::array<int, std::mt19937::state_size> seed_data {};
            std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
            std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
            eng = std::mt19937{seq};
            dist = std::uniform_int_distribution<T>
                {range_start, range_end};
    }

    T generate() {
        return dist(eng);
    }

};

#endif
