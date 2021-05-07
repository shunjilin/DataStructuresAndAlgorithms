import gleam/list
import gleam/should

pub fn get_max_pairwise_product(numbers: List(Int)) {
  let max_pair =
    list.fold(
      numbers,
      #(0, 0),
      fn(num, max_pair) {
        let #(largest, second_largest) = max_pair
        case num {
          num if num > largest -> #(num, largest)
          num if num > second_largest -> #(largest, num)
          _ -> max_pair
        }
      },
    )
  let #(largest, second_largest) = max_pair
  largest * second_largest
}

pub fn max_pairwise_product_test() {
  [21468, 16859, 82178, 70496, 82939, 44491]
  |> get_max_pairwise_product()
  |> should.equal(6815761142)

  [10, 9, 8, 7, 6]
  |> get_max_pairwise_product()
  |> should.equal(90)
}
