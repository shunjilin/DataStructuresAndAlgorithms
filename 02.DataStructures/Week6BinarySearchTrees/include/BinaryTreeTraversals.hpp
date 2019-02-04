#ifndef BINARY_TREE_TRAVERSALS_HPP
#define BINARY_TREE_TRAVERSALS_HPP

#include <vector>
#include <stack>
#include <optional>

struct Node {
    int key;
    int left_index;
    int right_index;

    Node(int key, int left_index, int right_index) :
        key(key), left_index(left_index), right_index(right_index) {}
};

struct BinaryTree {
    std::vector<Node> nodes;
    BinaryTree(std::vector<Node> nodes) : nodes(std::move(nodes)) {}
};

std::vector<int> inOrderTraversal(BinaryTree const & tree) {
    std::stack<Node> stack;
    std::vector<int> result;
    auto current = std::optional<Node>(tree.nodes[0]); 
    stack.push(current.value());
    while (!stack.empty()) {
        // keep traversing left
        while (current->left_index != -1) {
            current = tree.nodes[current->left_index];
            stack.push(current.value());
        }

        // end of left, print
        current = stack.top();
        stack.pop();
        result.push_back(current->key);

        // go right
        if (current->right_index != -1) {
            current = tree.nodes[current->right_index];
            stack.push(current.value());
        }
    }
    
    return result;
}

std::vector<int> preOrderTraversal(BinaryTree const & tree) {
    std::stack<Node> stack;
    std::vector<int> result;
    auto root = tree.nodes[0];
    stack.push(root);

    while (!stack.empty()) {
        auto node = stack.top();
        result.push_back(node.key);
        stack.pop();
        
        if (node.right_index != -1) {
            auto right_node = tree.nodes[node.right_index];
            stack.push(right_node);
        }
        
        if (node.left_index != -1) {
            auto left_node = tree.nodes[node.left_index];
            stack.push(left_node);
        }
    }
    
    return result;
}

#endif
