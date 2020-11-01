/// Problem 2 - Maximal Value of the Loot
///
/// Fractional Knapsack Problem
pub fn max_value_fractional_knapsack(mut items: Vec<Item>, mut capacity: u64) -> f64 {
    // sort in descending order of value over weight
    items.sort_by(|a, b| {
        (b.value as f64 / b.weight as f64)
            .partial_cmp(&(a.value as f64 / a.weight as f64))
            .unwrap()
    });

    let mut max_value = 0.0;
    for item in &items {
        if capacity == 0 {
            break;
        }
        if item.weight > capacity {
            // take fractional value
            max_value += (item.value as f64 / item.weight as f64) * capacity as f64;
            break;
        }
        // take unit value
        capacity -= item.weight;
        max_value += item.value as f64;
    }

    return max_value;
}

pub struct Item {
    value: u64,
    weight: u64,
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_correct_max_value_fractional_knapsack() {
        assert_eq!(
            max_value_fractional_knapsack(
                vec![
                    Item {
                        value: 60,
                        weight: 20
                    },
                    Item {
                        value: 100,
                        weight: 50
                    },
                    Item {
                        value: 120,
                        weight: 30
                    }
                ],
                50
            ),
            180.0
        );
    }
}
