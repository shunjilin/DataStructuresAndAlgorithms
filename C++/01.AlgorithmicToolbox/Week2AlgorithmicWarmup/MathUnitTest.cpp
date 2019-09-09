#include "Math.hpp"
#include <gmock/gmock.h>

TEST(Fibonacci, ReturnCorrectFibonacciNumber) {
  ASSERT_THAT(fibonacci(10), 55);
}

TEST(Fibonacci, ReturnCorrectFibonacciNumberLastDigit) {
  ASSERT_THAT(fibonacciLastDigit(10), 5);
}

TEST(GCD, ReturnCorrectGCD) {
    ASSERT_THAT(GCD(28851538, 1183019), 17657);
}

TEST(LCM, ReturnCorrectLCM) {
    ASSERT_THAT(LCM(28851538, 1183019), 1933053046);
}

TEST(Fibonacci, ReturnCorrectFibonacciModFast) {
  ASSERT_THAT(fibonacciModFast(2816213588, 239), 151);
}

TEST(Fibonacci, ReturnCorrectFibonacciSumLastDigit) {
  ASSERT_THAT(fibonacciSumLastDigit(100), 5);
}

TEST(Fibonacci, ReturnCorrectFibonacciPartialSumLastDigit) {
  ASSERT_THAT(fibonacciPartialSumLastDigit(10, 200), 2);
}

TEST(Fibonacci, ReturnCorrectFibonacciSumOfSquaresLastDigit) {
  ASSERT_THAT(fibonacciSumOfSquaresLastDigit(1234567890), 0);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
