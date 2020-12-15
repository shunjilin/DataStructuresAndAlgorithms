use rand::Rng;

/// Problem 2 - Majority Element
///
///  Problem 3 - Improving Quick Sort
/// Sorts a sequence of elements in place
/// Implements randomized quick sort with three way partition: less than, equal and more than
pub fn quick_sort(elements: &mut [u64]) -> () {
    if elements.len() <= 1 {
        return;
    }
    let (equal_start_index, equal_end_index) = three_way_partition(elements);
    quick_sort(&mut elements[..equal_start_index]);
    quick_sort(&mut elements[equal_end_index + 1..]);
}

// partition three ways: less than, equal, greater than random pivot element
// return the start and end index (inclusive) of the equal segment of the three way partition
fn three_way_partition(elements: &mut [u64]) -> (usize, usize) {
    let pivot_index = get_pivot_index(elements.len());
    let pivot_element = elements[pivot_index];
    // swap pivot element to start
    elements.swap(0, pivot_index);
    let mut equal_start_index = 1;
    let mut equal_end_index = elements.len() - 1;
    let mut index = 1;
    while index <= equal_end_index {
        match elements[index] {
            element if element < pivot_element => {
                elements.swap(index, equal_start_index);
                index += 1;
                equal_start_index += 1;
            }
            element if element > pivot_element => {
                elements.swap(index, equal_end_index);
                equal_end_index -= 1;
            }
            element if element == pivot_element => index += 1,
            _ => panic!("unreachable"),
        }
    }
    // return pivot element to middle
    equal_start_index -= 1;
    elements.swap(0, equal_start_index);
    return (equal_start_index, equal_end_index);
}

fn get_pivot_index(max_index: usize) -> usize {
    let mut rng = rand::thread_rng();
    rng.gen_range(0, max_index)
}

#[cfg(test)]
mod test {
    use super::*;

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
        let mut random_elements: [u64; 32] = rand::random();
        quick_sort(&mut random_elements);
        assert_eq!(is_sorted(random_elements.iter()), true)
    }
}
