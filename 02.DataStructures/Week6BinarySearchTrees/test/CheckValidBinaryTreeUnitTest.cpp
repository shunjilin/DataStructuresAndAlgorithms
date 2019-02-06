#include <gmock/gmock.h>
#include "CheckValidBinaryTree.hpp"

using namespace testing;

TEST(ValidBinaryTreeInitialize, returnsTrue) {
    BinaryTree tree = BinaryTree(
        {{0, 2, 1, 2}, {1, 1, -1, -1}, {2, 3, -1, -1}}
        );
    ASSERT_TRUE(isBinaryTreeValid(tree));
}

TEST(InvlidBinaryTreeInitialize, returnsFalse) {
    BinaryTree tree = BinaryTree(
        {{0, 1, 1, 2}, {1, 2, -1, -1}, {2, 3, -1, -1}}
        );
    ASSERT_FALSE(isBinaryTreeValid(tree));
}

int main(int argc, char*argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
