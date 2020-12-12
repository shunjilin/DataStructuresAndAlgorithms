pub fn max_pair(numbers: &[u64]) -> [u64; 2] {
    let mut largest_number: u64 = 0;
    let mut next_largest_number: u64 = 0;
    for number in numbers {
        if *number > largest_number {
            next_largest_number = largest_number;
            largest_number = *number;
        }
    }
    [largest_number, next_largest_number]
}

pub fn max_pairwise_product(numbers: &Vec<u64>) -> u64 {
    return max_pair(numbers).iter().product();
}

#[cfg(test)]
mod test {
    use super::*;

    fn generate_numbers() -> Vec<u64> {
        return vec![21468, 16859, 82178, 70496, 82939, 44491];
    }
    #[test]
    fn get_max_pair_from_vec() {
        let numbers = generate_numbers();
        assert_eq!(max_pair(&numbers).len(), 2);
        assert!(max_pair(&numbers).iter().any(|&x| x == 82178));
        assert!(max_pair(&numbers).iter().any(|&x| x == 82939));
    }

    #[test]
    fn get_max_pairwse_product_from_vec() {
        let numbers = generate_numbers();
        assert_eq!(max_pairwise_product(&numbers), 6815761142);
    }
}
