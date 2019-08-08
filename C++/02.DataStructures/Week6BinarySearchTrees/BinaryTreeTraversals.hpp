#ifndef BINARY_TREE_TRAVERSALS_HPP
#define BINARY_TREE_TRAVERSALS_HPP

#include <vector>
#include <stack>
#include <optional>

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

std::vector<int> inOrderTraversal(BinaryTree const & tree) {
    std::stack<Node> stack;
    std::vector<int> result;
    auto const *current = &tree.nodes[0];

    while (!stack.empty() || current) {
        if (current) {
            // go left
            stack.push(*current);
            if (current->left_index != -1) {
                current = &tree.nodes[current->left_index];                
            } else {
                current = nullptr;
            }
        } else {
            // go up
            current = &stack.top();
            stack.pop();
            result.push_back(current->key);
            // go right
            if (current->right_index != -1) {
                current = &tree.nodes[current->right_index];
            } else {
                current = nullptr;
            }
            
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

std::vector<int> postOrderTraversal(BinaryTree const & tree) {
    std::stack<Node> stack;
    std::vector<int> result;
    auto current = tree.nodes[0];
    auto previous = current;
    
    stack.push(current);
    while (!stack.empty()) {
        current = stack.top();
        // if children not traversed yet
        if (current.left_index != previous.index &&
              current.right_index != previous.index) {
            // keep traversing left
            while (current.left_index != -1) {
                previous = current;
                current = tree.nodes[current.left_index];
                stack.push(current);
            }
        }
        // if no right child, add to result
        if (current.right_index == -1) {
            result.push_back(current.key);
            previous = current;
            stack.pop();
        }
        // if came up from right child, done processing children and add to result
        else if (current.right_index == previous.index) {
            result.push_back(current.key);
            previous = current;
            stack.pop();
        }
        // traverse right
        else {
            previous = current;
            current = tree.nodes[current.right_index];
            stack.push(current);
        }
        
    }
    return result;
}


#endif
