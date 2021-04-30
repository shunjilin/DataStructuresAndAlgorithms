import gleam/iterator
import gleam/should
import gleam/pair

// compute the nth fibonacci number
pub fn fibonacci(n: Int) {
  iterator.fold(
    iterator.range(from: 1, to: n),
    tuple(0, 1),
    fn(_, pair) {
      let tuple(first, second) = pair
      tuple(second, first + second)
    },
  )
  |> pair.second
}

// compute the last digit of a fibonacci number
pub fn fibonacci_last_digit(n: Int) {
  fibonacci(n) % 10
}

// compute the greatest common divisor of two integers
pub fn gcd(a: Int, b: Int) {
  case b {
    0 -> a
    _ -> gcd(b, a % b)
  }
}

// compute the least common multiple of two integers
pub fn lcm(a: Int, b: Int) {
  a * b / gcd(a, b)
}

pub fn fibonacci_test() {
  10
  |> fibonacci
  |> should.equal(55)

  30
  |> fibonacci
  |> should.equal(832040)
}

pub fn fibonacci_last_digit_test() {
  3
  |> fibonacci_last_digit
  |> should.equal(2)

  311
  |> fibonacci_last_digit
  |> should.equal(9)
}

pub fn gcd_test() {
  gcd(28851538, 1183019)
  |> should.equal(17657)
}

pub fn lcm_test() {
  lcm(28851538, 1183019)
  |> should.equal(1933053046)
}
