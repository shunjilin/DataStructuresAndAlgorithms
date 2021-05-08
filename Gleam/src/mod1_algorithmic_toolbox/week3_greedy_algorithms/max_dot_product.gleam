import gleam/list
import gleam/int
import gleam/result
import gleam/should

/// Problem 3 - Maximum Advertisement Revenue
///
/// Max Dot Product
///
/// Returns the maximum dot product of two given sequence of integers of equal lengths
///
pub fn max_dot_product(sequence1: List(Int), sequence2: List(Int)) -> Int {
  list.zip(list.sort(sequence1, int.compare), list.sort(sequence2, int.compare))
  |> list.fold(
    0,
    fn(pair, max) {
      let #(first, second) = pair
      first * second + max
    },
  )
}

pub fn max_dot_product_test() {
  max_dot_product([23], [39])
  |> should.equal(897)

  max_dot_product([1, 3, -5], [-2, 4, 1])
  |> should.equal(23)
}
