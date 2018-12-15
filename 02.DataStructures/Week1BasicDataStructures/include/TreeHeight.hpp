#ifndef TREE_HEIGHT_HPP
#define TREE_HEIGHT_HPP

#include <vector>
#include <queue>

struct Node {
    std::vector<Node*> children;
};

// build tree from each node's parent, return parent node ptr
// nodes are the indexed nodes, and parents is an array associating each node
// with its parent node by index
Node* buildTree(std::vector<Node> & nodes, std::vector<int> const & parents) {
    Node* parent_node_ptr = nullptr;
    for (size_t node_index = 0; node_index < parents.size(); ++node_index) {
        auto parent_index = parents[node_index];
        auto current_node_ptr = &nodes[node_index];
        if (parent_index == -1){
            parent_node_ptr = current_node_ptr;
        } else {
            nodes[parent_index].children.push_back(current_node_ptr);
        }
    }
    return parent_node_ptr;
}

int getTreeHeight(Node* root_node_ptr) {
    std::queue<Node*> queue;
    int height = 0;
    queue.push(root_node_ptr);
    while (!queue.empty()) {
        size_t node_count = queue.size();
        for (size_t i = 0; i < node_count; ++i) {
            auto node_ptr = queue.front();
            for (auto child_ptr : node_ptr->children) {
                queue.push(child_ptr);
            }
            queue.pop();
        }
        ++height;
    }
    return height;
}

#endif
