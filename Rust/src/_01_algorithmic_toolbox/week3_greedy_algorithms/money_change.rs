/// Problem 1 - Money Change
///
/// Returns the minimum number of 1, 5 and 10 valued coins that make up a given input `value`
///
/// * `value` the total value of the coins
pub fn money_change(value: u64) -> u64 {
    let number_of_10 = value / 10;
    let value = value % 10;
    let number_of_5 = value / 5;
    let value = value % 5;
    let number_of_1 = value;
    return number_of_10 + number_of_5 + number_of_1;
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_returns_minimum_amount_of_coins() {
        assert_eq!(money_change(2), 2);
        assert_eq!(money_change(28), 6);
    }
}
