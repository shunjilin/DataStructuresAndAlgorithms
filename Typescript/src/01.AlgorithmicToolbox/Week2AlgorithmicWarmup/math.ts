export const fibonacci = (n: number): number => {
  let pair: [number, number] = [0, 1];
  for (let i = 0; i < n; ++i) {
    const [a, b] = pair;
    pair = [b, a + b];
  }
  return pair[0];
};

// returns nth fibonacci modulo
const fibonacciModulo = (n: number, modulo: number): number => {
  let pair: [number, number] = [0, 1];
  for (let i = 0; i < n; ++i) {
    const [a, b] = pair;
    pair = [b, (a + b) % modulo];
  }
  return pair[0];
};

// returns last digit of fibonacci
export const fibonacciLastDigit = (n: number): number => {
  return fibonacciModulo(n, 10);
};

// greatest common divisor
export const gcd = (a: number, b: number): number => {
  if (b === 0) {
    return a;
  }
  return gcd(b, a % b);
};

// least common multiple
export const lcm = (a: number, b: number): number => {
  return (a * b) / gcd(a, b);
};

// returns the period length of the fibonacci modulo
export const pisanoPeriod = (modulo: number): number => {
  if (modulo === 1) {
    return 1;
  }
  let pair: [number, number] = [0, 1];
  let sequenceLength = 0;
  while (true) {
    const [a, b] = pair;
    pair = [b, (a + b) % modulo];
    sequenceLength += 1;
    if (pair[0] === 0 && pair[1] === 1) {
      // sequence has repeated
      return sequenceLength;
    }
  }
};

// returns the modulo of the nth fibonacci (faster version)
// uses fact that fibonacci modulo sequence repeats after
// length of pisano period
export const fibonacciModuloFast = (n: number, modulo: number): number => {
  return fibonacciModulo(n % pisanoPeriod(modulo), modulo);
};

// returns the last digit of the sum of fibonacci numbers
export const fibonacciSumLastDigit = (n: number): number => {
  // can show that reduces to fib(n+2) - fib(2)
  return (10 + fibonacciModuloFast(n + 2, 10) - 1) % 10;
};

// returns the last digit of the sum of fibonacci numbers from n to m
export const fibonacciPartialSumLastDigit = (n: number, m: number): number => {
  if (m < n) {
    throw Error("m cannot be less than n");
  }
  // can show that reduces to fib(m+2) - fib(n+1)
  return (
    (10 + fibonacciModuloFast(m + 2, 10) - fibonacciModuloFast(n + 1, 10)) % 10
  );
};

// returns the last digit of sum of squares of fibonacci numbers
export const fibonacciSumOfSquaresLastDigit = (n: number): number => {
  // can show that reduces to fib(n) * fib(n+1)
  // from fact that fib(n) = fib(n+1) - fib(n-1)
  // fib(n)^2 = fib(n) * (fib(n+1) - fib(n-1))
  // fib(n)^2 = fib(n) * fib(n+1) - fib(n) * fib(n-1)
  // then write out as sequence
  return (fibonacciModuloFast(n, 10) * fibonacciModuloFast(n + 1, 10)) % 10;
};
