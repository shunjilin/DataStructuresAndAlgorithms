const expect = @import("std").testing.expect;

/// Maximum Pairwise Product Problem
///
/// Given a list of integers, return the maximum pairwise product,
/// i.e. product between the two largest distinct (different index) numbers in the list
pub fn max_pairwise_product(numbers: []const i64) i64 {
    var max_pair = [2]i64{ 0, 0 };
    for (numbers) |*number| {
        if (number.* > max_pair[0]) {
            max_pair[1] = max_pair[0];
            max_pair[0] = number.*;
        } else if (number.* > max_pair[1]) {
            max_pair[1] = number.*;
        } else {}
    }
    return max_pair[0] * max_pair[1];
}

test "max_pairwise_product" {
    const numbers_1 = [_]i64{ 21468, 16859, 82178, 70496, 82939, 44491 };
    try expect(max_pairwise_product(numbers_1[0..]) == 6815761142);

    const numbers_2 = [_]i64{ 10, 9, 8, 7, 6 };
    try expect(max_pairwise_product(numbers_2[0..]) == 90);
}
