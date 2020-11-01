/// Problem 6 - Maximum Salary
///
/// Compose the largest number from a sequence of positive integers
pub fn largest_number(mut sequence: Vec<u64>) -> u64 {
    sequence.sort_by(|a, b| {
        let ab = format!("{}{}", a, b);
        let ba = format!("{},{}", b, a);
        return ba.cmp(&ab);
    });

    sequence
        .into_iter()
        .map(|number| format!("{}", number))
        .collect::<Vec<std::string::String>>()
        .join("")
        .parse::<u64>()
        .unwrap()
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_maximum_composable_number_from_sequence() {
        assert_eq!(largest_number(vec![9, 4, 6, 1, 9]), 99641);
        assert_eq!(largest_number(vec![23, 39, 92]), 923923);
        assert_eq!(largest_number(vec![21, 2]), 221);
    }
}
