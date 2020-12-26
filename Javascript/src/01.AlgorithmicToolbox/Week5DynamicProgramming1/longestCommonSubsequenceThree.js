/**
 * Problem 5 - Longest Common Subsequence of Three Sequence
 * Compute the length of a longest common subsequence of three sequences
 * @param {Array.<string>} first first sequence
 * @param {Array.<string>} second second sequence
 * @param {Array.<string>} third thid sequence
 * @returns {number} length of longest common subsequence
 */
export function longestCommonSubsequenceThree(first, second, third) {
  const longestSubsequenceLengths = new Array(first.length + 1)
    .fill(0)
    .map(() =>
      new Array(second.length + 1)
        .fill(0)
        .map(() => new Array(third.length + 1).fill(0))
    );

  for (let x = 1; x <= first.length; ++x) {
    for (let y = 1; y <= second.length; ++y) {
      for (let z = 1; z <= third.length; ++z) {
        if (first[x - 1] === second[y - 1] && second[y - 1] === third[z - 1]) {
          // add 1 to existing subsequence
          longestSubsequenceLengths[x][y][z] =
            longestSubsequenceLengths[x - 1][y - 1][z - 1] + 1;
        } else {
          // max of prefixes
          longestSubsequenceLengths[x][y][z] = Math.max(
            longestSubsequenceLengths[x - 1][y][z],
            longestSubsequenceLengths[x][y - 1][z],
            longestSubsequenceLengths[x][y][z - 1]
          );
        }
      }
    }
  }
  return longestSubsequenceLengths[first.length][second.length][third.length];
}
