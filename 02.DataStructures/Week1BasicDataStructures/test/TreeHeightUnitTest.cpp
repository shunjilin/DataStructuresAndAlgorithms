#include <gmock/gmock.h>
#include "TreeHeight.hpp"

using namespace testing;

TEST(TreeHeight, buildTreeCorrectRoot) {
    std::vector<Node> nodes(3);
    std::vector<int> parents = {2, 2, -1};
    auto root_node_ptr = buildTree(nodes, parents);
    ASSERT_EQ(root_node_ptr, &nodes[2]);
}

TEST(TreeHeight, correctTreeHeight) {
    std::vector<Node> nodes(5);
    std::vector<int> parents = {-1, 0, 4, 0, 3};
    auto root_node_ptr = buildTree(nodes, parents);
    ASSERT_EQ(getTreeHeight(root_node_ptr), 4);
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
