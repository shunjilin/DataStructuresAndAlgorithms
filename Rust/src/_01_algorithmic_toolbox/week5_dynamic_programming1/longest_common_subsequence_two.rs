/// Problem 4 - Longest Common Subsequence of Two Sequence
/// Compute the length of a longest common subsequence of two sequences
pub fn longest_common_subsequence_two(first: &[u64], second: &[u64]) -> u64 {
    let mut longest_common_subsequence_lengths = vec![vec![0; second.len() + 1]; first.len() + 1];

    for row in 1..=first.len() {
        for col in 1..=second.len() {
            if first[row - 1] == second[col - 1] {
                // add 1 to existing subsequence
                longest_common_subsequence_lengths[row][col] =
                    longest_common_subsequence_lengths[row - 1][col - 1] + 1;
            } else {
                // max of prefixes
                longest_common_subsequence_lengths[row][col] = std::cmp::max(
                    longest_common_subsequence_lengths[row - 1][col],
                    longest_common_subsequence_lengths[row][col - 1],
                )
            }
        }
    }
    longest_common_subsequence_lengths[first.len()][second.len()]
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn return_longest_common_subsequence_of_two_sequences() {
        assert_eq!(
            longest_common_subsequence_two(&vec![2, 7, 5], &vec![2, 5]),
            2,
        );
        assert_eq!(
            longest_common_subsequence_two(&vec![7], &vec![1, 2, 3, 4]),
            0,
        );
        assert_eq!(
            longest_common_subsequence_two(&vec![2, 7, 8, 3], &vec![5, 2, 8, 7]),
            2,
        );
    }
}
