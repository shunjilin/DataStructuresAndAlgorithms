/// Problem 5 - Longest Common Subsequence of Three Sequence
/// Compute the length of a longest common subsequence of three sequences
pub fn longest_common_subsequence_three(first: &[u64], second: &[u64], third: &[u64]) -> u64 {
    let mut longest_common_subsequence_lengths =
        vec![vec![vec![0; third.len() + 1]; second.len() + 1]; first.len() + 1];

    for x in 1..=first.len() {
        for y in 1..=second.len() {
            for z in 1..=third.len() {
                if first[x - 1] == second[y - 1] && second[y - 1] == third[z - 1] {
                    // add 1 to existing subsequence
                    longest_common_subsequence_lengths[x][y][z] =
                        longest_common_subsequence_lengths[x - 1][y - 1][z - 1] + 1;
                } else {
                    // max of prefixes
                    longest_common_subsequence_lengths[x][y][z] = std::cmp::max(
                        std::cmp::max(
                            longest_common_subsequence_lengths[x - 1][y][z],
                            longest_common_subsequence_lengths[x][y - 1][z],
                        ),
                        longest_common_subsequence_lengths[x][y][z - 1],
                    )
                }
            }
        }
    }
    longest_common_subsequence_lengths[first.len()][second.len()][third.len()]
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn return_longest_common_subsequence_of_two_sequences() {
        assert_eq!(
            longest_common_subsequence_three(&vec![1, 2, 3], &vec![2, 1, 3], &vec![1, 3, 5]),
            2,
        );
        assert_eq!(
            longest_common_subsequence_three(
                &vec![8, 3, 2, 1, 7],
                &vec![8, 2, 1, 3, 8, 10, 7],
                &vec![6, 8, 3, 1, 4, 7]
            ),
            3,
        );
    }
}
