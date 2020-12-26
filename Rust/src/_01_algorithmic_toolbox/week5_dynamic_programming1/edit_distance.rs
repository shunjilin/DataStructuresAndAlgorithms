/// Problem 3 - Edit Distance
/// Calculate the minimum number of operations
/// (insertions, deletions and substitutions)
/// needed to transform one string to another.
/// Assumes each character is of byte length!
/// Return minimum edit distance.
pub fn edit_distance(first: &String, second: &String) -> usize {
    let mut edit_distances = vec![vec![usize::MAX; second.len() + 1]; first.len() + 1];

    // initialize outer row / col
    // these are the number of operations to convert empty string to each input string
    for row in 0..=first.len() {
        edit_distances[row][0] = row;
    }
    for col in 0..=second.len() {
        edit_distances[0][col] = col;
    }
    // fill rest of the elements
    for row in 1..=first.len() {
        for col in 1..=second.len() {
            if first.as_bytes()[row - 1] == second.as_bytes()[col - 1] {
                edit_distances[row][col] = edit_distances[row - 1][col - 1];
            } else {
                let substitution = edit_distances[row - 1][col - 1] + 1;
                let deletion = edit_distances[row][col - 1] + 1;
                let addition = edit_distances[row - 1][col] + 1;
                edit_distances[row][col] =
                    std::cmp::min(std::cmp::min(substitution, deletion), addition);
            }
        }
    }
    edit_distances[first.len()][second.len()]
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_minimum_edit_distance() {
        assert_eq!(edit_distance(&String::from("ab"), &String::from("ab")), 0);
        assert_eq!(
            edit_distance(&String::from("short"), &String::from("ports")),
            3
        );
        assert_eq!(
            edit_distance(&String::from("editing"), &String::from("distance")),
            5
        );
        assert_eq!(
            edit_distance(&String::from("abcdef"), &String::from("azced")),
            3
        );
    }
}
