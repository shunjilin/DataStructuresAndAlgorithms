/// Problem 2 - Majority Element
///
/// Given a sequence of elements (non-negative integers), check whether it contains an element that appears more than n/2 times.
/// If found, output that element, otherwise, output None
pub fn majority_element(elements: Vec<u64>) -> Option<u64> {
    majority_element_helper(&elements[..])
}

fn majority_element_helper(elements: &[u64]) -> Option<u64> {
    let elements_length = elements.iter().count();
    if elements_length == 1 {
        return Some(elements[0]);
    }
    let middle_index = elements_length / 2;

    let left_majority = majority_element_helper(&elements[..middle_index]);
    let right_majority = majority_element_helper(&elements[middle_index..]);

    let majority_threshold = elements_length / 2;

    match (left_majority, right_majority) {
        (Some(left), Some(right)) if left == right => Some(left),
        (Some(left), _) if get_element_count(elements, left) > majority_threshold => Some(left),
        (_, Some(right)) if get_element_count(elements, right) > majority_threshold => Some(right),
        _ => None,
    }
}

fn get_element_count(elements: &[u64], element: u64) -> usize {
    elements.iter().filter(|&x| *x == element).count()
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_majority_element_if_exists() {
        assert_eq!(majority_element(vec![2, 3, 9, 2, 2]), Some(2));
        assert_eq!(majority_element(vec![2, 2, 3, 3, 4]), None);
        assert_eq!(majority_element(vec![2, 2, 3, 3]), None);
        assert_eq!(majority_element(vec![3, 3, 2, 3]), Some(3));
        assert_eq!(majority_element(vec![1, 2]), None);
        assert_eq!(majority_element(vec![1, 1]), Some(1));
        assert_eq!(majority_element(vec![1, 2, 3, 4, 5]), None);
    }
}
