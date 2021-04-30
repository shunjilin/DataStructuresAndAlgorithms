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

pub fn fibonacci_test() {
  10
  |> fibonacci
  |> should.equal(55)

  30
  |> fibonacci
  |> should.equal(832_040)
}

pub fn fibonacci_last_digit_test() {
  3
  |> fibonacci_last_digit
  |> should.equal(2)

  311
  |> fibonacci_last_digit
  |> should.equal(9)
}
