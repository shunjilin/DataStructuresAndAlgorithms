/// Problem 1 - Binary Search
///
/// Given an input set of distinct positive integers in increasing order and a positive integer key,
/// output the index corresponding to the position of the key in the input set, None if not found
pub fn binary_search(input: &[u64], key: u64) -> Option<usize> {
    let end_index = input.len();
    binary_search_helper(input, key, 0, end_index)
}

fn binary_search_helper(
    input: &[u64],
    key: u64,
    start_index: usize,
    end_index: usize,
) -> Option<usize> {
    if start_index == end_index {
        // key not found
        return None;
    }
    let middle_index = start_index + (end_index - start_index) / 2;
    match input[middle_index] {
        middle_value if middle_value == key => Some(middle_index),
        middle_value if middle_value < key => {
            binary_search_helper(input, key, middle_index + 1, end_index)
        }
        middle_value if middle_value > key => {
            binary_search_helper(input, key, start_index, middle_index)
        }
        _ => panic!("invalid index"),
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_binary_search_index() {
        assert_eq!(binary_search(&vec![1, 5, 8, 12, 13], 8), Some(2));
        assert_eq!(binary_search(&vec![1, 5, 8, 12, 13], 1), Some(0));
        assert_eq!(binary_search(&vec![1, 5, 8, 12, 13], 23), None)
    }
}
