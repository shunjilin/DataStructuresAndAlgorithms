/**
 * Problem 3 - Maximum Advertisement Revenue
 * Max Dot Product
 * @param {Array.<number>} sequence1 first sequence of numbers
 * @param {Array.<number>} sequence2 second sequence of numbers
 * @returns maximum dot product of the two sequences
 */
export function maxDotProduct(sequence1, sequence2) {
  sequence1.sort();
  sequence2.sort();
  return sequence1
    .map((value, index) => value * sequence2[index])
    .reduce((acc, cur) => acc + cur);
}
