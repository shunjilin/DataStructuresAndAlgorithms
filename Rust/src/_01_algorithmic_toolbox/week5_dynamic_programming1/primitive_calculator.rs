/// Problem 2 - Primitive Calculator
/// Calculator can only perform three operations:
/// multiply by 2, multiply by 3 and add 1
/// output sequence of intermediate results (including final output) of
/// applying operations to starting value of 1 to get given output
pub fn primitive_calculator(output: u64) -> Vec<u64> {
    let mut min_operations = vec![u64::MAX; (output + 1) as usize];
    min_operations[0] = 0;
    min_operations[1] = 1;
    for i in 2..min_operations.len() {
        let add_1 = min_operations[i - 1] + 1;
        let multiply_2 = if i % 2 == 0 {
            min_operations[i / 2] + 1
        } else {
            u64::MAX
        };
        let multiply_3 = if i % 3 == 0 {
            min_operations[i / 3] + 1
        } else {
            u64::MAX
        };
        min_operations[i] = std::cmp::min(std::cmp::min(add_1, multiply_2), multiply_3);
    }
    get_intermediate_values(min_operations)
}

pub fn get_intermediate_values(min_operations: Vec<u64>) -> Vec<u64> {
    let mut value = min_operations.len() - 1;
    let mut intermediate_values = vec![];
    while value >= 1 {
        intermediate_values.push(value as u64);
        if min_operations[value] == (min_operations[value - 1] + 1) {
            value = value - 1
        } else if value % 2 == 0 && min_operations[value] == (min_operations[value / 2] + 1) {
            value = value / 2;
        } else if value % 3 == 0 && min_operations[value] == (min_operations[value / 3] + 1) {
            value = value / 3;
        } else {
            break;
        }
    }
    intermediate_values.reverse();
    intermediate_values
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn return_intermediate_values() {
        assert_eq!(primitive_calculator(1), vec![1]);
        let intermediate_results_5 = primitive_calculator(5);
        assert_eq!(intermediate_results_5.len(), 4);
        assert_eq!(*intermediate_results_5.last().unwrap(), 5);
        let mut it = intermediate_results_5.into_iter();
        // check if operations correct
        assert_eq!(
            match it.next() {
                None => true,
                Some(first) => it
                    .scan(first, |state, next| {
                        let previous = *state;
                        let correct_operation =
                            previous + 1 == next || previous * 2 == next || previous * 3 == next;
                        *state = next;
                        Some(correct_operation)
                    })
                    .all(|b| b),
            },
            true
        )
    }
}
