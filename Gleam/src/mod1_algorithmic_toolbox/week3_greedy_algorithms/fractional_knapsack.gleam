import gleam/list
import gleam/int
import gleam/float
import gleam/should
import gleam/iterator
import gleam/pair
import gleam/io

//
// Problem 2 - Maximum Value of the Loot
//
// Fractional Knapsack Problem
//
// Given items with corresponding values and weights, and a knapsack capacity,
// returns the maximum value of items that can fit into the knapsack 
//
pub fn max_value_fractional_knapsack(items: List(Item), capacity: Int) -> Float {
  items
  // sort by descending order of value / weight
  |> list.sort(by: fn(a: Item, b: Item) {
    float.compare(value_over_weight(b), value_over_weight(a))
  })
  |> iterator.from_list
  |> iterator.fold(
    from: tuple(0.0, capacity),
    with: fn(item: Item, pair) {
      let tuple(value, capacity) = pair
      // take as much of item as possible
      case capacity >= item.weight {
        True -> tuple(value +. int.to_float(item.value), capacity - item.weight)
        False -> tuple(
          value +. value_over_weight(item) *. int.to_float(capacity),
          0,
        )
      }
    },
  )
  |> pair.first
}

pub type Item {
  Item(value: Int, weight: Int)
}

fn value_over_weight(item: Item) -> Float {
  let Item(value, weight) = item
  int.to_float(value) /. int.to_float(weight)
}

pub fn max_value_fractional_knapsack_test() {
  [Item(2, 1), Item(2, 2)]
  |> max_value_fractional_knapsack(2)
  |> should.equal(3.0)

  [Item(60, 20), Item(100, 50), Item(120, 30)]
  |> max_value_fractional_knapsack(50)
  |> should.equal(180.0)
}
