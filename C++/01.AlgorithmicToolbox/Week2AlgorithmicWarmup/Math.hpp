#ifndef MATH_HPP
#define MATH_HPP

// Returns the nth fibonacci number
unsigned long long fibonacci(unsigned long long n) {
  if (n <= 1) {
    return n;
  }
  unsigned long long previous = 0, current = 1;
  for (unsigned i = 2; i <= n; ++i) {
    auto sum = previous + current;
    previous = current;
    current = sum;
  }
  return current;
}

// Returns the  nth fibonacci number modulo mod
int fibonacciMod(unsigned long long n, unsigned long long mod) {
  if (n <= 1) {
    return n;
  }
  int previous = 0, current = 1;
  for (unsigned i = 2; i <= n; ++i) {
    auto sum_modulo = (previous + current) % mod;
    previous = current;
    current = sum_modulo;
  }
  return current;
}

// Returns the nth fibonacci number's last digit
int fibonacciLastDigit(unsigned long long n) { return fibonacciMod(n, 10); }

// Greatest Common Divisor
unsigned long long GCD(unsigned long long a, unsigned long long b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  return GCD(b, a % b);
}

// Least Common Multiple
unsigned long long LCM(unsigned long long a, unsigned long long b) {
  return a * b / GCD(a, b);
}

// Returns the period length of Fibonacci modulo mod (Pisano period)
unsigned long long pisanoPeriod(unsigned long long mod) {
  if (mod == 1) {
    return 1;
  }
  unsigned long long previous = 0, current = 1;
  unsigned long long sequence_length = 0;
  while (true) {
    auto sum_modulo = (previous + current) % mod;
    previous = current;
    current = sum_modulo;
    ++sequence_length;
    if (previous == 0 && current == 1) { // period repeats
      return sequence_length;
    }
  }
}

// Returns the modulo of the nth Fibonacci (faster version of
// FibonacciLastDigit)
// Uses the fact that Fibonacci Mod sequence repeats
unsigned long long fibonacciModFast(unsigned long long n,
                                    unsigned long long mod) {
  auto mod_period = pisanoPeriod(mod);
  return fibonacciMod(n % mod_period, mod);
}

// Returns the last digit of sum of fibonacci numbers up to n
unsigned fibonacciSumLastDigit(unsigned long long n) {
  // can show that reduces to fib(n+2) - fib(2)
  return (10 + (fibonacciModFast(n + 2, 10) - 1)) % 10;
}

// Returns the last digit of sum of fibonacci numbers from n to m
unsigned fibonacciPartialSumLastDigit(unsigned long long n,
                                      unsigned long long m) {
  // can show that reduces to fib(m+2) - fib(n+1)
  return (10 + (fibonacciModFast(m + 2, 10) - fibonacciModFast(n + 1, 10))) %
         10;
}

// Returns the last digit of sum of squares of fibonacci numbers up to n
unsigned fibonacciSumOfSquaresLastDigit(unsigned long long n) {
  // can show that reduces to fib(n)*fib(n+1)
  // from fact that fib(n) = fib(n+1) - fib(n-1)
  // fib(n)^2 = fib(n) * (fib(n+1) - fib(n-1))
  // fib(n)^2 = fib(n) * fib(n+1) - fib(n) * fib(n-1)
  // then write out as sequence
  return fibonacciModFast(n, 10) * fibonacciModFast(n + 1, 10) % 10;
}

#endif
