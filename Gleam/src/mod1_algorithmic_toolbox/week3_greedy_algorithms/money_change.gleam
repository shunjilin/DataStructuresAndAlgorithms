import gleam/should
import gleam/iterator
import gleam/pair

//
// Problem 1 - Money Change
//
// Given the total `value` of coins, returns the minimum number of coins of denominator 1, 5 and 10 that exactly changes `value`
//
pub fn min_coins(value: Int) {
  [10, 5, 1]
  |> iterator.from_list
  |> iterator.fold(
    tuple(0, value),
    fn(coin, pair) {
      let tuple(n_coins, value) = pair
      tuple(n_coins + value / coin, value % coin)
    },
  )
  |> pair.first
}

pub fn money_change_test() {
  2
  |> min_coins
  |> should.equal(2)

  28
  |> min_coins
  |> should.equal(6)
}
