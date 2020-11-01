/// Problem 3 - Maximum Advertisement Revenue
///
/// Returns the maximum dot product of two given sequence of integers of equal lengths
pub fn max_dot_product(mut sequence1: Vec<i64>, mut sequence2: Vec<i64>) -> i64 {
    sequence1.sort();
    sequence2.sort();
    sequence1
        .iter()
        .zip(sequence2.iter())
        .map(|(first, second)| first * second)
        .sum()
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_max_dot_product_of_two_sequences() {
        assert_eq!(max_dot_product(vec![23], vec![39]), 897);
        assert_eq!(max_dot_product(vec![1, 3, -5], vec![-2, 4, 1]), 23);
    }
}
