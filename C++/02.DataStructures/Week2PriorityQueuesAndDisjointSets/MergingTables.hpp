#ifndef MERGING_TABLES_HPP
#define MERGING_TABLES_HPP

struct DisjointSetEntry {
    size_t parent_index;
    size_t size;
    DisjointSetEntry(size_t index, size_t size = 1) :
        parent_index(index), size(size) {}
};

class DisjointSet {
    std::vector<DisjointSetEntry> entries;
    size_t max_size = 0;
public:
    DisjointSet(std::vector<size_t> const & entry_sizes) {
        for (size_t i = 0; i < entry_sizes.size(); ++i) {
            auto entry_size = entry_sizes[i];
            entries.emplace_back(i, entry_size);
            if (entry_size > max_size) {
                max_size = entry_size;
            }
            
        }
    }

    void Union(size_t source_index, size_t destination_index) {
        auto source_parent_index = Find(source_index);
        auto destination_parent_index = Find(destination_index);
        if (source_parent_index != destination_parent_index) {
            entries[source_parent_index].parent_index = destination_parent_index;
            entries[destination_parent_index].size +=
                entries[source_parent_index].size;
            if (entries[destination_parent_index].size > max_size) {
                max_size = entries[destination_parent_index].size;
            }
        }
    }

    size_t Find(size_t index) {
        auto parent_index = entries[index].parent_index;
        // path halving
        while (index != parent_index) {
            entries[index].parent_index = entries[parent_index].parent_index;
            index = parent_index;
            parent_index = entries[index].parent_index;
        }
        return index;
    }

    size_t getMaxSize() const {
        return max_size;
    }
};

#endif
