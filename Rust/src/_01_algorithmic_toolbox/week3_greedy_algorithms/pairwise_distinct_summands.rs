use std::collections::HashSet;

/// Problem 5 - Maximum Number of Prizes
///
/// Find the maximal set of distinct positive integers that sum up to a given sum
pub fn pairwise_distinct_summands(sum: u64) -> HashSet<u64> {
    let mut summands = HashSet::new();
    let mut summand = 1;
    let mut difference_from_sum = sum;
    while difference_from_sum > 0 {
        let remainder = difference_from_sum - summand;
        if remainder <= summand {
            summands.insert(difference_from_sum);
            return summands;
        }
        summands.insert(summand);
        difference_from_sum -= summand;
        summand += 1;
    }
    return summands;
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_paiwise_distinct_summands() {
        assert_eq!(pairwise_distinct_summands(2), [2].iter().cloned().collect());
        assert_eq!(
            pairwise_distinct_summands(6),
            [1, 2, 3].iter().cloned().collect()
        );
        assert_eq!(
            pairwise_distinct_summands(8),
            [1, 2, 5].iter().cloned().collect()
        );
    }
}
