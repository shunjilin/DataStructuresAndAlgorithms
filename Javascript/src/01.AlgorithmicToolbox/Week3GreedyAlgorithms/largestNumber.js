/**
 * Problem 6 - Maximum Salary
 * Compose the largest number from a sequence of positive integers
 * @param {Array.<{number}>} sequence sequence of numbers
 * @returns {number} largest number composable from the sequencea
 */
export function largestNumber(sequence) {
  const largestNumberString = sequence
    .sort((a, b) => {
      const ab = parseInt(`${a}${b}`, 10);
      const ba = parseInt(`${b}${a}`, 10);
      return ba - ab;
    })
    .join("");
  return parseInt(largestNumberString, 10);
}
