#include <gmock/gmock.h>
#include "Mathematics.hpp"

using namespace testing;
using namespace Mathematics;

TEST(Fibonacci, ReturnCorrectModPeriod) {
    ASSERT_THAT(fibonacciModPeriod(10), 60);
}

TEST(Fibonacci, ReturnCorrectFibonacciNumber) {
    ASSERT_THAT(fibonacci(10), 55);
}

TEST(Fibonacci, ReturnCorrectFibonacciNumberLastDigit) {
    ASSERT_THAT(fibonacciMod10(10), 5);
}

TEST(Fibonacci, ReturnCorrectFibonacciSumLastDigit) {
    ASSERT_THAT(fibonacciSumMod10(13), 9);
}

TEST(Fibonacci, ReturnCorretFibonacciPartialSumLastDigit) {
    ASSERT_THAT(fibonacciPartialSumMod10(10, 200), 2);
}

TEST(GCD, ReturnCorrectGCD) {
    ASSERT_THAT(GCD(28851538, 1183019), 17657);
}

TEST(LCM, ReturnCorrectLCM) {
    ASSERT_THAT(LCM(28851538, 1183019), 1933053046);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
