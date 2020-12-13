///
/// Problem 4 - Inversions
/// Given a sequence of n integers a0, a1,..., a(n-1), returns the number of inversions,
/// where an inversion is a pair of indices i, j where 0 <= i < j < n and ai > aj.
pub fn inversions(sequence: &mut [i64]) -> usize {
    let sequence_length = sequence.len();
    if sequence_length == 1 {
        return 0;
    }
    let middle_index = sequence_length / 2;
    let left_inversions = inversions(&mut sequence[..middle_index]);
    let right_inversions = inversions(&mut sequence[middle_index..]);
    merge_with_inversions(sequence, middle_index) + left_inversions + right_inversions
}

fn merge_with_inversions(sequence: &mut [i64], middle_index: usize) -> usize {
    let mut inversions = 0;
    let mut left_iter = sequence[..middle_index].to_vec().into_iter();
    let mut right_iter = sequence[middle_index..].to_vec().into_iter();
    let mut left_value = left_iter.next();
    let mut right_value = right_iter.next();
    let mut left_count = middle_index;
    for value in sequence {
        match (left_value, right_value) {
            (Some(left), Some(right)) if left <= right => {
                *value = left;
                left_value = left_iter.next();
                left_count -= 1;
            }
            (Some(_left), Some(right)) => {
                *value = right;
                right_value = right_iter.next();
                inversions += left_count;
            }
            (Some(left), None) => {
                *value = left;
                left_value = left_iter.next();
            }
            (None, Some(right)) => {
                *value = right;
                right_value = right_iter.next();
            }
            _ => panic!("unreachable"),
        }
    }
    inversions
}

#[cfg(test)]
mod test {
    use super::*;
    use rand;

    fn is_sorted<I>(data: I) -> bool
    where
        I: IntoIterator,
        I::Item: Ord,
    {
        let mut it = data.into_iter();
        match it.next() {
            None => true,
            Some(first) => it
                .scan(first, |state, next| {
                    let cmp = *state <= next;
                    *state = next;
                    Some(cmp)
                })
                .all(|b| b),
        }
    }

    #[test]
    fn sorts_array_of_random_elements() {
        let mut random_elements: [i64; 32] = rand::random();
        inversions(&mut random_elements);
        assert_eq!(is_sorted(random_elements.iter()), true)
    }

    #[test]
    fn gets_correct_number_of_inversions() {
        assert_eq!(inversions(&mut vec![1, 2, 3]), 0);
        assert_eq!(inversions(&mut vec![3, 1, 2, 3, 1, 2]), 7);
        assert_eq!(inversions(&mut vec![0, -1, 1, -2, 2]), 4);
    }
}
