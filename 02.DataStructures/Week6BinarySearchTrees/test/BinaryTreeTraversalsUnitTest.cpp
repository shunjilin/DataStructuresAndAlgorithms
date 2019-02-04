#include <gmock/gmock.h>
#include "BinaryTreeTraversals.hpp"

using namespace testing;

class BinaryTreeInitialize: public Test {
public:
    BinaryTree tree = BinaryTree({{4, 1, 2}, {2, 3, 4}, {5, -1, -1}, {1, -1, -1}, {3, -1, -1}});
};

TEST_F(BinaryTreeInitialize, inOrderTraversal) {
    ASSERT_THAT(inOrderTraversal(tree), ElementsAre(1, 2, 3, 4, 5));
}

TEST_F(BinaryTreeInitialize, preOrderTraversal) {
    ASSERT_THAT(preOrderTraversal(tree), ElementsAre(4, 2, 1, 3, 5));
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
