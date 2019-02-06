#include <gmock/gmock.h>
#include "BinaryTreeTraversals.hpp"

using namespace testing;

class BinaryTreeInitialize: public Test {
public:
    BinaryTree tree = BinaryTree(
        //{{0, 4, 1, 2}, {1, 2, 3, 4}, {2, 5, -1, -1}, {3, 1, -1, -1}, {4, 3,
        //-1, -1}}
        {{0, 0, 7, 2}, {1, 10, -1, -1}, {2, 20, -1, 6}, {3, 30, 8, 9}, {4, 40, 3, -1}, {5, 50, -1, -1}, {6, 60, 1, -1}, {7, 70, 5, 4}, {8, 80, -1, -1}, {9, 90, -1, -1}}
        );
};

TEST_F(BinaryTreeInitialize, inOrderTraversal) {
    ASSERT_THAT(inOrderTraversal(tree), ElementsAre(50, 70, 80, 30, 90, 40, 0, 20, 10, 60));
}

TEST_F(BinaryTreeInitialize, preOrderTraversal) {
    ASSERT_THAT(preOrderTraversal(tree), ElementsAre(0, 70, 50, 40, 30, 80, 90, 20, 60, 10));
}

TEST_F(BinaryTreeInitialize, postOrderTraversal) {
    ASSERT_THAT(postOrderTraversal(tree), ElementsAre(50, 80, 90, 30, 40, 70, 10, 60, 20, 0));
}

class BinaryTreeInitialize2: public Test {
public:
    BinaryTree tree = BinaryTree(
        {{0, 0, 4, -1}, {1, 1, -1, -1}, {2, 2, 3, -1}, {3, 3, -1, -1}, {4, 4, 1, 2}}
        );
};

TEST_F(BinaryTreeInitialize2, inOrderTraversal) {
    ASSERT_THAT(inOrderTraversal(tree), ElementsAre(1, 4, 3, 2, 0));
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
