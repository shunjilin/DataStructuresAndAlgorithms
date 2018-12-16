#include <gmock/gmock.h>
#include "StackWithMax.hpp"

using namespace testing;

TEST(StackWithMax, TrackMaxCorrectly) {
    StackWithMax<int> stack_with_max;
    stack_with_max.push(2);
    stack_with_max.push(3);
    stack_with_max.push(9);
    stack_with_max.push(7);
    stack_with_max.push(2);
    ASSERT_THAT(stack_with_max.max(), 9);
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
