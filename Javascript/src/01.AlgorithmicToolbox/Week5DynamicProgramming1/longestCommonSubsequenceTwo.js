/**
 * Problem 4 - Longest Common Subsequence of Two Sequence
 * Compute the length of a longest common subsequence of two sequences
 * @param {Array.<string>} first first sequence
 * @param {Array.<string?} second second sequence
 * @returns {number} length of longest common subsequence
 */
export function longestCommonSubsequenceTwo(first, second) {
  const longestSubsequenceLengths = new Array(first.length + 1)
    .fill(0)
    .map(() => new Array(second.length + 1).fill(0));

  for (let row = 1; row <= first.length; ++row) {
    for (let col = 1; col <= second.length; ++col) {
      if (first[row - 1] === second[col - 1]) {
        // add 1 to existing subsequence
        longestSubsequenceLengths[row][col] =
          longestSubsequenceLengths[row - 1][col - 1] + 1;
      } else {
        // max of prefixes
        longestSubsequenceLengths[row][col] = Math.max(
          longestSubsequenceLengths[row - 1][col],
          longestSubsequenceLengths[row][col - 1]
        );
      }
    }
  }
  return longestSubsequenceLengths[first.length][second.length];
}
