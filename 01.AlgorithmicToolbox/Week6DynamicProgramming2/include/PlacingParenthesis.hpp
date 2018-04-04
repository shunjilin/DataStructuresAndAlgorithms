#ifndef PLACING_PARENTHESIS_HPP
#define PLACING_PARENTHESIS_HPP

#include <vector>
#include <string>
#include <utility>
#include <limits>

namespace DynamicProgramming {

    long long applyOperator(long long first, long long second, char op) {
        if (op == '+') return first + second;
        if (op == '-') return first - second;
        if (op == '*') return first * second;
        return 0;
    }
    
    std::pair<long long, long long>
    minAndMax(const std::string& expression,
              int start, int end,
              const std::vector< std::vector<long long> >& max_table,
              const std::vector< std::vector<long long> >& min_table) {
        auto min = std::numeric_limits<long long>::max();
        auto max = std::numeric_limits<long long>::min();
        
        for (auto mid = start; mid < end; ++mid) {
            auto a = applyOperator(max_table[start][mid],
                                   max_table[mid+1][end],
                                   expression[mid*2+1]);
            auto b = applyOperator(max_table[start][mid],
                                   min_table[mid+1][end],
                                   expression[mid*2+1]);
            auto c = applyOperator(min_table[start][mid],
                                   max_table[mid+1][end],
                                   expression[mid*2+1]);
            auto d = applyOperator(min_table[start][mid],
                                   min_table[mid+1][end],
                                   expression[mid*2+1]);
            min = std::min(min, std::min(a, std::min(b, std::min(c, d))));
            max = std::max(max, std::max(a, std::max(b, std::max(c, d))));
        }
        return std::make_pair(min, max);
    }
    
    long long maxValueFromPlacingParenthesis(const std::string& expression) {
        auto n_numbers = (expression.size() + 1) / 2;
        auto max_table = std::vector< std::vector<long long> >
            (n_numbers, std::vector<long long>(n_numbers, 0));
        auto min_table = std::vector< std::vector<long long> >
            (n_numbers, std::vector<long long>(n_numbers, 0));
        // fill for single digits diagonal
        for (std::size_t i = 0; i < n_numbers; ++i) {
            max_table[i][i] = expression[i*2] - '0';
            min_table[i][i] = expression[i*2] - '0';
        }
        // fill for single operation diagonal
        for (std::size_t start = 0; start < n_numbers - 1; ++start) {
            auto end = start + 1;
            max_table[start][end] = applyOperator(max_table[start][start],
                                                  max_table[end][end],
                                                  expression[start*2+1]);
            min_table[start][end] = applyOperator(min_table[start][start],
                                                  min_table[end][end],
                                                  expression[start*2+1]);
        }
        for (std::size_t subprob_sz = 3; subprob_sz <= n_numbers; ++subprob_sz) {
            for (std::size_t start = 0; start <= n_numbers - subprob_sz; ++start) {
                auto end = start + subprob_sz - 1;
                auto min_max = minAndMax(expression, start, end,
                                         max_table, min_table);
                max_table[start][end] = min_max.second;
                min_table[start][end] = min_max.first;
            }
        }
        return max_table[0][n_numbers-1];
    }
}

#endif
