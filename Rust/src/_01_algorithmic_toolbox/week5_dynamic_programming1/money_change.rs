/// Problem 1 - Money Change Again
///
/// Returns the minimum number of coins of denominator 1, 3, and 4 that exactly changes value
pub fn min_coins(value: u64) -> u64 {
    let mut coins_to_value = vec![u64::MAX; value as usize + 1];
    coins_to_value[0] = 0;

    for i in 1..coins_to_value.len() {
        let coins_after_add_1 = if i >= 1 {
            coins_to_value[i - 1] + 1
        } else {
            u64::MAX
        };
        let coins_after_add_3 = if i >= 3 {
            coins_to_value[i - 3] + 1
        } else {
            u64::MAX
        };
        let coins_after_add_4 = if i >= 4 {
            coins_to_value[i - 4] + 1
        } else {
            u64::MAX
        };
        coins_to_value[i] = std::cmp::min(
            std::cmp::min(coins_after_add_1, coins_after_add_3),
            coins_after_add_4,
        );
    }
    *coins_to_value.last().unwrap()
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_min_coins() {
        assert_eq!(min_coins(2), 2);
        assert_eq!(min_coins(34), 9);
    }
}
