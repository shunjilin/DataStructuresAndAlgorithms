#ifndef CHECK_VALID_BINARY_TREE_HARD_HPP
#define CHECK_VALID_BINARY_TREE_HARD_HPP

#include <vector>
#include <stack>
#include <limits>

struct Node {
    int index;
    int key;
    int left_index;
    int right_index;

    Node(int index, int key, int left_index, int right_index) :
        index(index), key(key), left_index(left_index), right_index(right_index) {}
};

struct BinaryTree {
    std::vector<Node> nodes;
    BinaryTree(std::vector<Node> nodes) : nodes(std::move(nodes)) {}
};

// duplicates must go to the right
bool isBinaryTreeValid(BinaryTree const & tree) {
    std::stack<Node> stack;
    auto const *current = &tree.nodes[0];
    int prev_processed = std::numeric_limits<int>::min();
    while (!stack.empty() || current) {
        if (current) {
            // go left
            stack.push(*current);
            if (current->left_index != -1) {
                auto left_child = &tree.nodes[current->left_index];
                // duplicates only on right
                if (left_child->key == current->key) return false;
                current = left_child;
            } else {
                current = nullptr;
            }
        } else {
            // go up
            current = &stack.top();
            stack.pop();
            if (current->key < prev_processed) {
                return false;
            }
            prev_processed = current->key;
            // go right
            if (current->right_index != -1) {
                current = &tree.nodes[current->right_index];
            } else {
                current = nullptr;
            }
            
        }
    }
    return true;
}

#endif
