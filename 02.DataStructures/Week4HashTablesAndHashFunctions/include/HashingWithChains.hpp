#ifndef HASHING_WITH_CHAINS_HPP
#define HASHING_WITH_CHAINS_HPP

#include <vector>
#include <forward_list>
#include <string>
#include <algorithm>

long hashString(std::string const & input_string,
               long modulo=1000000007,
               long multiplicative_constant=263) {
    long hash_value = 0;
    for (auto rit = input_string.rbegin(); rit != input_string.rend(); ++rit) {
        hash_value *= multiplicative_constant;
        hash_value = (hash_value + *rit) %  modulo;
    }
    return hash_value;
}

class ChainedHashTable {
    std::vector<std::forward_list<std::string>> table;

    std::forward_list<std::string>& get_bucket_list(std::string const& input) {
        auto bucket_to_hash = hashString(input) % table.size();
        return table[bucket_to_hash];
    }

    bool stringInBucketList(std::forward_list<std::string> const & bucket_list,
                            std::string const& input) {
        auto find_it = std::find(bucket_list.begin(), bucket_list.end(), input);
        return find_it != bucket_list.end() ? true : false;
    }

public:
    ChainedHashTable(int n_buckets) : table(n_buckets) {}

    void add(std::string input) {
        auto& bucket_list = get_bucket_list(input);
        if (!stringInBucketList(bucket_list, input)) {
            bucket_list.push_front(std::move(input));
        }
    }

    void del(std::string input) {
        auto& bucket_list = get_bucket_list(input);
        bucket_list.remove(input);
    }

    bool find(std::string input) {
        auto& bucket_list = get_bucket_list(input);
        return stringInBucketList(bucket_list, input);
    }

    // returns strings at bucket
    std::vector<std::string> check(int bucket) {
        std::vector<std::string> result;
        auto& bucket_list = table[bucket];
        for (auto const& string_element: bucket_list) {
            result.push_back(string_element);
        }
        return result;
    }
};


#endif
