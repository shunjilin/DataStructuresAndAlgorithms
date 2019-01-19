#ifndef FIND_PATTERN_IN_TEXT_HPP
#define FIND_PATTERN_IN_TEXT_HPP

#include <vector>
#include <cmath>
#include <iostream>

// Rabin-Karp's Algorithm

long const PRIME = 1000000007;
long const BASE = rand() % (PRIME-1) + 1;

// this does not return negative values
long safe_modulus(long value, long modulus) {
    return ((value % modulus) + modulus) % modulus;
}

// does actual comparison
bool textContainsPatternAtIndex(std::string const& pattern,
                                std::string const& text,
                                size_t index) {
    auto pattern_size = pattern.size();
    for (size_t i = 0; i < pattern_size; ++i) {
        if (pattern[i] != text[index + i]) {
            return false;
        }
    }
    return true;
}

long hashString(std::string const & text,
                size_t start_index, size_t end_index,
                long base=BASE, long prime_modulus=PRIME) {
    long hashValue = 0;
    for (size_t i = start_index; i < end_index; ++i) {
        hashValue *= base;
        hashValue = safe_modulus(hashValue + text[i], prime_modulus);
    }
    return hashValue;
}

// precompute
long getSubtractionMultiplier(size_t pattern_size, long base=BASE,
                            size_t prime_modulus=PRIME) {
    long subtraction_multiplier = 1;
    for (size_t i = 0; i < pattern_size-1; ++i) {
        subtraction_multiplier = (subtraction_multiplier * base) % prime_modulus;
    }
    return subtraction_multiplier;
}

long rollingHashString(long previous_hash,
                       std::string const & text,
                       size_t pattern_size,
                       size_t prev_pattern_start_index,
                       long subtraction_multiplier,
                       long base=BASE, long prime_modulus=PRIME) {
    auto new_hash = previous_hash;
    long value_to_subtract = safe_modulus(
        subtraction_multiplier * text[prev_pattern_start_index], prime_modulus
        );
    new_hash = safe_modulus(new_hash - value_to_subtract, prime_modulus);
    new_hash = safe_modulus(new_hash * base, prime_modulus);
    new_hash = safe_modulus(
      new_hash + text[prev_pattern_start_index + pattern_size], prime_modulus
      );
    return new_hash;
}

std::vector<size_t> findPatternInText(std::string const& pattern,
                                      std::string const& text) {
    auto subtraction_multiplier = getSubtractionMultiplier(pattern.size());
    auto pattern_size = pattern.size();
    auto matched_indexes = std::vector<size_t>();

    auto n_possible_substrings = text.size() - pattern.size() + 1;
    
    long pattern_hash = hashString(pattern, 0, pattern.size());
    long rolling_hash = hashString(text, 0, pattern.size());
    if (rolling_hash == pattern_hash) matched_indexes.push_back(0);
    for (size_t i = 1; i < n_possible_substrings; ++i) {
        rolling_hash =
            rollingHashString(
                rolling_hash, text, pattern_size, i-1, subtraction_multiplier);
        if (rolling_hash == pattern_hash) {
            if (textContainsPatternAtIndex(pattern, text, i)) {
                matched_indexes.push_back(i);
            }            
        }
    }
    return matched_indexes;   
}

#endif
